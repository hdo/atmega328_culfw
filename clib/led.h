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
#ifdef LED_INV_RGB
#define led_init()   LED_DDR  |= (_BV(LED_PIN)) | (_BV(LED_PIN_GREEN)) | (_BV(LED_PIN_RED)) | (_BV(LED_PIN_BLUE))
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
#ifdef LED_INV_RGB
#define LED_GREEN_OFF()    LED_PORT |= _BV(LED_PIN_GREEN)
#define LED_GREEN_ON( )    LED_PORT &= ~_BV(LED_PIN_GREEN)
#define LED_RED_OFF()    LED_PORT |= _BV(LED_PIN_RED)
#define LED_RED_ON( )    LED_PORT &= ~_BV(LED_PIN_RED)
#define LED_BLUE_OFF()    LED_PORT |= _BV(LED_PIN_BLUE)
#define LED_BLUE_ON( )    LED_PORT &= ~_BV(LED_PIN_BLUE)
#endif
#define LED_ON()     LED_PORT |= _BV(LED_PIN)
#define LED_OFF( )   LED_PORT &= ~_BV(LED_PIN)
#endif

#endif
