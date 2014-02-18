#ifndef _LED_H
#define _LED_H   1

#define HI8(x)  ((uint8_t)((x) >> 8))
#define LO8(x)  ((uint8_t)(x))

#define SET_BIT(PORT, BITNUM) ((PORT) |= (1<<(BITNUM)))
#define CLEAR_BIT(PORT, BITNUM) ((PORT) &= ~(1<<(BITNUM)))
#define TOGGLE_BIT(PORT, BITNUM) ((PORT) ^= (1<<(BITNUM)))

#include "board.h"

#ifdef XLED
#include "xled.h"
#define led_init()   LED_DDR  |= _BV(LED_PIN); xled_pos=0; xled_pattern=0xff00
#else
#ifdef LED_RGB
#define led_init()   LED_DDR  |= (_BV(LED_PIN)) | (_BV(LED_PIN_GREEN)) | (_BV(LED_PIN_RED)) | (_BV(LED_PIN_BLUE))
#define LED_CHANNEL_GREEN 0
#define LED_CHANNEL_RED 1
#define LED_CHANNEL_BLUE 2
#else
#define led_init()   LED_DDR  |= _BV(LED_PIN)
#endif
#endif

//#define LED_TOGGLE() LED_PORT ^= _BV(LED_PIN)
#define LED_TOGGLE() LED_PORT |= 0

#ifdef LED_INV
#define LED_OFF()    LED_PORT |= _BV(LED_PIN)
#define LED_ON( )    LED_PORT &= ~_BV(LED_PIN)
#else
#ifdef LED_RGB

void led_process(uint32_t msticks);
void led_signal(uint8_t channel, uint32_t timeout);
void led_on(uint8_t channel);
void led_off(uint8_t channel);

#endif
#define LED_ON()     LED_PORT |= _BV(LED_PIN)
#define LED_OFF( )   LED_PORT &= ~_BV(LED_PIN)
#endif

#endif
