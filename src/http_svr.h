/***********************************************************************************************************************
 * File Name    : http_svr.h
 * Description  : Contains macros, data structures and functions used common to
 * the EP
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its
 * affiliates SPDX-License-Identifier: BSD-3-Clause
 ***********************************************************************************************************************/
#ifndef HTTP_SVR_H_
#define HTTP_SVR_H_

#include "common_utils.h"

#define SSID "test101_24g"
#define PASSPHRASE "vhorse23"
#define CHANNEL 0
#define PASSS_LEN strlen(PASSPHRASE)
#define SSID_LEN strlen(SSID)

/* Server lifecycle */
fsp_err_t init_server(void);
void deinit_server(void);

/* Filesystem helpers */
void format_fs(void);
int write_file(char *p_path, char *p_buf);

/* JSON API used by the HTTP handler */
int http_get_values_for_key(char *buf, int buflen, const char *key);
int http_get_values_for_uri(char *buf, int buflen, const char *uri);

#endif /* HTTP_SVR_H_ */
