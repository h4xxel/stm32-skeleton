#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/can.h>

void can_setup(uint16_t baud_rate_prescale, uint8_t ts1, uint8_t ts2);
void can_send(uint32_t id, bool extended_id, size_t len, uint8_t *buf);
int can_recv(uint8_t fifo, uint8_t *data, uint8_t *matched_filter, bool *extended_id, uint32_t *id, uint16_t *timestamp);
int can_try_recv(uint8_t fifo, uint8_t *data, uint8_t *matched_filter, bool *extended_id, uint32_t *id, uint16_t *timestamp);
int can_set_filter_mask(uint8_t fifo, uint32_t mask, uint32_t ident, bool extended_id);
int can_set_filter_ident(uint8_t fifo, uint32_t ident1, uint32_t ident2, bool extended_id);

#endif
