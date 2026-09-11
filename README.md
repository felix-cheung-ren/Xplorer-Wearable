# Biometric Monitoring and IMU Wearable Concept — EK-RA6W1

A proof-of-concept wearable health and IMU monitoring system built on the Renesas RA6W1 Wi-Fi SoC. Combines real-time biometric and IMU sensing, a round watch-like display, and a live Wi-Fi dashboard for demonstration.

---

## Overview

This project follows the development of a wearable POC with wireless data delivery and an onboard watch-face UI. Sensor data (heart rate, SpO2, step count, fall detection) is processed in real time, displayed on a 240×240 round GC9A01 display, and streamed to a browser dashboard over Wi-Fi. An IMU-controlled maze game and a live model is included as an interactive demo of the motion sensing pipeline.

---

## Gallery

<table>
  <tr>
    <td colspan="3" align="center">
      <img width="400" src="https://github.com/user-attachments/assets/fba4d299-198c-436a-94fc-34b6e08cc9d4"/>
      <br/><sub>EK-RA6W1 with all currently implemented hardware</sub>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img width="150" src="https://github.com/user-attachments/assets/90f5a4f1-3c55-4a39-aa38-653c169e7c53"/>
      <br/><sub>Screen UI</sub>
    </td>
    <td align="center">
      <img width="350" src="https://github.com/user-attachments/assets/1c4025a7-ae19-4c49-9634-030580254363"/>
      <br/><sub>Live web dashboard</sub>
    </td>
    <td align="center">
      <img width="250" src="https://github.com/user-attachments/assets/70c38d69-8b92-44c0-8a92-9bb0e1b96813"/>
      <br/><sub>Interactive IMU features on the dashboard</sub>
    </td>
  </tr>
</table>

---

## Implemented Features

- Real-time heart rate and SpO2 measurement via MAX30102
- Step counting and fall detection via LSM6DSV320X IMU
- Round 240×240 LVGL watch face with live biometric display and RTC clock
- SNTP time sync over Wi-Fi on boot
- Live browser dashboard over HTTP with 3D device model and sensor readouts
- IMU-controlled maze game streamed to the web dashboard
- Terminal console interface

**In progress**
- DA14531 Bluetooth UART pipe
- Coin LRA haptic feedback
- Passive buzzer alerts

---

## Hardware

| Component | Role |
|---|---|
| Renesas EK-RA6W1 | Main MCU — Cortex-M33 + Wi-Fi SoC |
| MAX30102 | Pulse oximeter — heart rate & SpO2 via I2C |
| LSM6DSV320X | 6-axis IMU — step counting, fall detection via I2C |
| GC9A01 (240×240) | Round SPI display driven by LVGL v9.2 |
| DA14531 (UART) | Bluetooth UART pipe (in-progress) |
| Coin LRA + driver | Haptic feedback (in-progress) |
| Passive buzzer | Audio alerts (in-progress) |

---

## Software Architecture

Built on Renesas FSP v2.1.0 with FreeRTOS:

<img width="930" height="668" alt="image" src="https://github.com/user-attachments/assets/e7082968-566d-4a4c-99f0-832f69ac8af6" />

### Task Breakdown

- **app_task**: Initialises Wi-Fi, starts the HTTP server, triggers SNTP time sync, then exits
- **Data_Processing**: Handles external hardware initialization, blocks on sensor events, runs the RF heart rate/SpO2 algorithm on MAX30102 data, reads LSM6DSV step/fall events, writes results to shared globals
- **MAX30102**: Polls the sensor FIFO on interrupt, fills the algorithm buffer, notifies Data_Processing when full
- **Display**: Updates at 50 ms; updates the watch face labels and arcs

### Notes

- **RA6W1 EP Memory Leak**: Patched memory leak in FSP code that would cause eventual system crash after some number of HTTP requests, verified in unchanged EP, will document later 

---

## Building

Requires e² studio with RAFW FSP v2.1.0 pack installed.

1. Import project into e² studio workspace
2. Configure Wi-Fi credentials in `src/http_svr.h`
3. Build and flash via J-Link
4. Connect to the board's HTTP server IP: "https://10.0.0.17/wearable_dash.html" to view the live dashboard
