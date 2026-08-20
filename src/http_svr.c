/***********************************************************************************************************************
* File Name    : http_srv.c
* Description  : http(s) server functions and configurations
**********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
#include "common_data.h"
#include "common_utils.h"
#include "http_svr.h"
#include "lfs.h"
#include "rm_httpd.h"
#include "sensor_events.h"
#include "LSM6DSV320X/lsm6dsv320x_reg_interface.h"

https_server_sec_t p_sec;

static const uint8_t tls_srv_cert[] =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIB6DCCAY2gAwIBAgIUPUuczXvddLrhm/ckOgE2CUa9bncwCgYIKoZIzj0EAwIw\n"
    "YTELMAkGA1UEBhMCSU4xDzANBgNVBAgMBktlcmFsYTESMBAGA1UEBwwJS296aGlr\n"
    "b2RlMRQwEgYDVQQKDAtFeGFtcGxlIElvVDEXMBUGA1UEAwwObXlkZXZpY2UubG9j\n"
    "YWwwHhcNMjUwNjE2MTAxOTI3WhcNMjYwNjE2MTAxOTI3WjBhMQswCQYDVQQGEwJJ\n"
    "TjEPMA0GA1UECAwGS2VyYWxhMRIwEAYDVQQHDAlLb3poaWtvZGUxFDASBgNVBAoM\n"
    "C0V4YW1wbGUgSW9UMRcwFQYDVQQDDA5teWRldmljZS5sb2NhbDBZMBMGByqGSM49\n"
    "AgEGCCqGSM49AwEHA0IABCZu8oIidrVJjASgssa5oavfCkQUI93zRxKKTuXN8tsW\n"
    "Aq9Upn8jcCSnZAGhWZhlEHCeyQN6cZFttwWNht56FX2jIzAhMB8GA1UdEQQYMBaC\n"
    "Dm15ZGV2aWNlLmxvY2FshwTAqDKcMAoGCCqGSM49BAMCA0kAMEYCIQDq01321W0O\n"
    "5BeDCx7+Ww/8fzQg6bW5bpI9mTbG99tSTwIhANYIrykIdtDU20unlS01j3cHQM+W\n"
    "ZMx/MmdF3yKUgctH\n"
    "-----END CERTIFICATE-----\n";

static size_t tls_srv_cert_len = sizeof(tls_srv_cert);

static const uint8_t tls_srv_key[] =
    "-----BEGIN EC PRIVATE KEY-----\n"
    "MHcCAQEEINGUbjFG3GfiVsV29FG/rh8qjc3PkzqCf6B8CA/3310noAoGCCqGSM49\n"
    "AwEHoUQDQgAEJm7ygiJ2tUmMBKCyxrmhq98KRBQj3fNHEopO5c3y2xYCr1SmfyNw\n"
    "JKdkAaFZmGUQcJ7JA3pxkW23BY2G3noVfQ==\n"
    "-----END EC PRIVATE KEY-----\n";

static size_t tls_srv_key_len = sizeof(tls_srv_key);

void g_https0_callback(https_callback_args_t  *p_args)
{
    switch(p_args->event)
    {
        case HTTPS_EVENT_SERVER_RECVED:
        {
            APP_PRINT_INFO("Event: HTTPS_EVENT_SERVER_RECVED\n");
            break;
        }

        default:
            APP_PRINT_ERR("Error: Unknown event from http Server received\n");
    }
}

static void config_secure_connection(https_server_sec_t *p_sec_cfg)
{
    p_sec_cfg->p_tls_srv_cert = (uint8_t *)tls_srv_cert;
    p_sec_cfg->p_tls_srv_key = (uint8_t *)tls_srv_key;
    p_sec_cfg->tls_srv_cert_len = tls_srv_cert_len;
    p_sec_cfg->tls_srv_key_len = tls_srv_key_len;
    p_sec_cfg->tls_ver_max = MBEDTLS_SSL_VERSION_TLS1_3;
    p_sec_cfg->tls_ver_min = MBEDTLS_SSL_VERSION_TLS1_3;
    p_sec_cfg->p_priv_pass = NULL;
    p_sec_cfg->priv_pass_len = 0;
}


static int http_get_values_json(char *buf, int buflen, const char *key)
{
    (void)key;
	int n;

	/* Full JSON object */
    int ret = 0;
    int rem = buflen;
    char *p = buf;

    /* We only need the quaternions during actual webpage viewing */
    lsm6dsv320x_sflp_get();

    n = snprintf(p, (size_t)rem,
		 "{\"heart_rate\":%ld,"
		 "\"spo2\":%.1f,"
		 "\"ratio\":%.3f,"
		 "\"correl\":%.3f,"
		 "\"steps\":%u,"
		 "\"dropped\":%d,"
		 "\"quat_w\":%.3f,"
		 "\"quat_x\":%.3f,"
		 "\"quat_y\":%.3f,"
		 "\"quat_z\":%.3f",
		 (long)g_heart_rate,
		 (double)g_spo2,
		 (double)g_ratio,
		 (double)g_correl,
		 (unsigned)g_step_count,
		 (int)g_fall_count,
		 (double)g_quaternions[0],
		 (double)g_quaternions[1],
		 (double)g_quaternions[2],
		 (double)g_quaternions[3]);

    if (n < 0) return 0;
    if (n >= rem) n = rem - 1;
    p += n; rem -= n; ret += n;

    if (rem > 0) {
        int wrote = snprintf(p, (size_t)rem, ",\"files\":[");
        if (wrote < 0) wrote = 0;
        if (wrote >= rem) wrote = rem - 1;
        p += wrote; rem -= wrote; ret += wrote;

        if (lfs_mutex_get() && (lfs_mutex_take(pdMS_TO_TICKS(500)) == pdTRUE)) {
            lfs_dir_t d; struct lfs_info info; int first = 1;
            if (lfs_dir_open(&g_rm_littlefs0_lfs, &d, "/") == 0) {
                const int MAX_FILES = 64; int filecount = 0;
                while (filecount < MAX_FILES) {
                    int r = lfs_dir_read(&g_rm_littlefs0_lfs, &d, &info);
                    if (r < 0 || r == 0) break;
                    if ((strcmp(info.name, ".") == 0) || (strcmp(info.name, "..") == 0)) continue;
                    if (!first) {
                        if (rem > 1) { *p++ = ','; rem--; ret++; } else break;
                    }
                    int need = snprintf(p, (size_t)rem, "{\"name\":\"%s\",\"type\":\"%s\",\"size\":%u}",
                                       info.name, (info.type == LFS_TYPE_DIR) ? "dir" : "file", (unsigned)info.size);
                    if (need < 0) need = 0;
                    if (need >= rem) break;
                    p += need; rem -= need; ret += need;
                    first = 0; filecount++;
                }
                lfs_dir_close(&g_rm_littlefs0_lfs, &d);
            }
            lfs_mutex_give();
        }

        if (rem > 0) {
            int w2 = snprintf(p, (size_t)rem, "]");
            if (w2 > 0) { p += w2; rem -= w2; ret += w2; }
        }
    }

    if (rem > 0) {
        unsigned long total_bytes = (unsigned long)g_rm_littlefs0_lfs_cfg.block_size *
                                    (unsigned long)g_rm_littlefs0_lfs_cfg.block_count;
        unsigned long free_bytes = 0UL;
        if (lfs_mutex_get() && (lfs_mutex_take(pdMS_TO_TICKS(500)) == pdTRUE)) {
            lfs_ssize_t used_blocks = lfs_fs_size(&g_rm_littlefs0_lfs);
            if (used_blocks >= 0) {
                unsigned long used_bytes = (unsigned long)used_blocks *
                                           (unsigned long)g_rm_littlefs0_lfs_cfg.block_size;
                free_bytes = (used_bytes >= total_bytes) ? 0 : total_bytes - used_bytes;
            }
            lfs_mutex_give();
        }
        int w3 = snprintf(p, (size_t)rem, ",\"fs_total\":%lu,\"fs_free\":%lu", total_bytes, free_bytes);
        if (w3 < 0) w3 = 0;
        if (w3 >= rem) w3 = rem - 1;
        p += w3; rem -= w3; ret += w3;
    }

    if (rem > 0) {
        int w4 = snprintf(p, (size_t)rem, "}");
        if (w4 > 0) { p += w4; rem -= w4; ret += w4; }
    }

    if (buflen > 0) buf[(ret < buflen) ? ret : (buflen-1)] = '\0';
    return ret;
}

int http_get_values_for_key(char *buf, int buflen, const char *key)
{
    return http_get_values_json(buf, buflen, key);
}

int http_get_values_for_uri(char *buf, int buflen, const char *uri)
{
	(void)uri;
	return http_get_values_json(buf, buflen, NULL);
}

fsp_err_t init_server()
{
    fsp_err_t err = FSP_SUCCESS;

    err = RM_HTTPS_W_Open((https_ctrl_t *) &g_https_w0_ctrl, &g_https_w0_cfg);
    if (err != FSP_SUCCESS)
    {
        APP_PRINT_ERR("Error: Unable to open http module\n");
        return err;
    }

    config_secure_connection(&p_sec);

    err = RM_HTTPS_W_ServerStart((https_ctrl_t *) &g_https_w0_ctrl, &p_sec);
    if (err != FSP_SUCCESS)
        APP_PRINT_ERR("Error: Http Server start failed\n");
    else
        APP_PRINT_INFO("Https Server Running...\n");

    return err;
}

void deinit_server()
{
    APP_PRINT_INFO("Https Server closing...\n");
    RM_HTTPS_W_ServerStop((https_ctrl_t *) &g_https_w0_ctrl);
    RM_HTTPS_W_Close((https_ctrl_t *) &g_https_w0_ctrl);
}

void format_fs()
{
    int rc;
    rc = lfs_mount(&g_rm_littlefs0_lfs, &g_rm_littlefs0_lfs_cfg);
    if (rc < 0)
    {
        APP_PRINT_INFO("[fs] Mount failed (%d), formatting...\n", rc);
        lfs_format(&g_rm_littlefs0_lfs, &g_rm_littlefs0_lfs_cfg);
        rc = lfs_mount(&g_rm_littlefs0_lfs, &g_rm_littlefs0_lfs_cfg);
        if (rc < 0)
            APP_PRINT_ERR("[fs] Mount after format failed (%d)\n", rc);
        else
            APP_PRINT_INFO("[fs] Filesystem formatted and mounted OK\n");
    }
    else
    {
        APP_PRINT_INFO("[fs] Filesystem mounted OK (existing data preserved)\n");
    }
}

int write_file(char *p_path, char *p_buf)
{
    int lfs_rc;
    int wr;
    int err_val = 0;
    lfs_file_t file;

    lfs_rc = lfs_file_open(&g_rm_littlefs0_lfs, &file, p_path,
                           (LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC));
    if (lfs_rc < 0) return lfs_rc;

    wr = lfs_file_write(&g_rm_littlefs0_lfs, &file, p_buf, strlen(p_buf));
    if (wr < 0) err_val = wr;

    lfs_file_close(&g_rm_littlefs0_lfs, &file);
    return err_val;
}
