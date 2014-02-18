/*
 * led.c
 *
 *  Created on: Feb 18, 2014
 *      Author: huy
 */

#include <stdint.h>
#include <avr/io.h>
#include "led.h"
#include "math_utils.h"
#include "board.h"

#define LED_COUNT 3

uint16_t led_map[] = {LED_PIN_GREEN, LED_PIN_RED, LED_PIN_BLUE};

uint32_t led_current_msticks = 0;
uint32_t led_msticks[] = {0, 0, 0};
uint32_t led_timeout[] = {0, 0, 0};

void led_on(uint8_t channel) {
	if (channel < LED_COUNT) {
		LED_PORT &= ~_BV(led_map[channel]);
	}
}

void led_off(uint8_t channel) {
	if (channel < LED_COUNT) {
		LED_PORT |= _BV(led_map[channel]);
	}
}

void led_signal(uint8_t channel, uint32_t timeout) {
	if (channel < LED_COUNT) {
		led_timeout[channel] = timeout;
		led_msticks[channel] = led_current_msticks;
		led_on(channel);
		if (channel == LED_CHANNEL_RED || channel == LED_CHANNEL_BLUE) {
			led_off(LED_CHANNEL_GREEN);
		}
	}
}

void led_process(uint32_t msticks) {
	led_current_msticks = msticks;
	uint8_t i;
	for(i=0; i < LED_COUNT; i++) {
		if (led_timeout[i] > 0) {
			if (math_calc_diff(msticks, led_msticks[i]) > led_timeout[i]) {
				led_timeout[i] = 0;
				led_msticks[i] = 0;
				led_off(i);
				if (i == LED_CHANNEL_RED || i == LED_CHANNEL_BLUE) {
					led_on(LED_CHANNEL_GREEN);
				}
			}
		}
	}
}

