/*
 * MAX30102_data.h
 *
 *  Created on: Aug 2, 2026
 *      Author: a5163560
 */

#ifndef MAX30102_DATA_H_
#define MAX30102_DATA_H_

#define ALGO_BUFFER_SIZE 100 // from aromring's algorithm

extern volatile uint32_t g_algo_red[ALGO_BUFFER_SIZE];
extern volatile uint32_t g_algo_ir[ALGO_BUFFER_SIZE];
extern volatile uint16_t g_algo_count;


#endif /* MAX30102_DATA_H_ */
