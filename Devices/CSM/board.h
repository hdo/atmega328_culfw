#ifndef _BOARD_H
#define _BOARD_H

//#define HAS_FHT_8v                      // PROGMEM:  434b, RAM: 19b
//#define HAS_FHT_80b                     // PROGMEM: 1158b, RAM:  5b

#undef  FULL_CC1100_PA                  // PROGMEM:  108b

#undef  HAS_RAWSEND                     // PROGMEM:  198b     RAM:  4b
#undef  HAS_FASTRF                      // PROGMEM:  362+106  RAM:  1b
#undef  HAS_RF_ROUTER                   // PROGMEM:  920b  RAM: 38b
#undef  HAS_LONGMSG                     // CUR support     RAM: 20b


//#define HOMEMATIC_BATTERY_ACTOR
#define ARDUINO_MINI_PRO
//#define CSMV4
//#define CSMV3
//#define TUXRAIL
//#define TUXRADIO

#ifdef CSMV4
#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
#define SPI_SS			4
#define SPI_MISO		6
#define SPI_MOSI		5
#define SPI_SCLK		7

#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT          SPI_PORT
#define CC1100_CS_PIN		SPI_SS

#define CC1100_OUT_DDR		DDRB
#define CC1100_OUT_PORT         PORTB
#define CC1100_OUT_PIN          1

#define CC1100_IN_DDR		DDRD
#define CC1100_IN_PORT          PIND
#define CC1100_IN_PIN           2
#define CC1100_INT		INT0
#define CC1100_INTVECT          INT0_vect
#define CC1100_ISC		ISC00
#define CC1100_EICR             EICRA

#ifdef TUXRAIL
#define LED_DDR                 DDRD
#define LED_PORT                PORTD
#define LED_PIN                 4
#else
#define LED_DDR                 DDRA
#define LED_PORT                PORTA
#define LED_PIN                 1
#endif
#define LED_ON_DDR              DDRA
#define LED_ON_PORT             PORTA
#define LED_ON_PIN              0

#define USART_RX_vect           USART0_RX_vect
#define USART_UDRE_vect         USART0_UDRE_vect

#define FHTBUF_SIZE          174      //                 RAM: 174b
#define RCV_BUCKETS            4      //                 RAM: 25b * bucket
#define RFR_DEBUG                     // PROGMEM:  354b  RAM: 14b
#define FULL_CC1100_PA                // PROGMEM:  108b
#define HAS_RAWSEND                   //
#define HAS_FASTRF                    // PROGMEM:  468b  RAM:  1b
#define HAS_ASKSIN
#define HAS_ESA
#define HAS_INTERTECHNO

#ifdef TUXRADIO
#define HAS_DOGM
#define DOGM_RS_DDR             DDRA
#define DOGM_RS_PORT            PORTA
#define DOGM_RS_PIN             4
#define DOGM_CS_DDR             DDRA
#define DOGM_CS_PORT            PORTA
#define DOGM_CS_PIN             5

#define HAS_IRRX
#define F_INTERRUPTS            15625   // interrupts per second, min: 10000, max: 20000

#endif

#else

//#define FHTBUF_SIZE             74      //                 RAM: 74b
//#define RCV_BUCKETS             2       //                 RAM: 25b / bucket
#define FHTBUF_SIZE             174      //                 RAM: 74b
#define RCV_BUCKETS             4       //                 RAM: 25b / bucket
#define RFR_DEBUG                     // PROGMEM:  354b  RAM: 14b
#define FULL_CC1100_PA                // PROGMEM:  108b
#define HAS_RAWSEND                   //
#define HAS_FASTRF                    // PROGMEM:  468b  RAM:  1b
#define HAS_ASKSIN
#define HAS_MORITZ
//#define HAS_ESA
//#define HAS_INTERTECHNO


#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
#define SPI_SS			2
#define SPI_MISO		4
#define SPI_MOSI		3
#define SPI_SCLK		5

#endif

#ifdef ARDUINO_MINI_PRO
#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT     SPI_PORT
#define CC1100_CS_PIN		SPI_SS

#define CC1100_OUT_DDR		DDRC        // GDO0
#define CC1100_OUT_PORT    PORTC
#define CC1100_OUT_PIN     0

#define CC1100_IN_DDR		DDRC        // GDO2
#define CC1100_IN_PORT     PINC
#define CC1100_IN_PIN      1
#define CC1100_INT		INT1
#define CC1100_INTVECT          INT1_vect
#define CC1100_ISC		ISC10
#define CC1100_EICR             EICRA

#define LED_INV_RGB
#define LED_DDR                 DDRD
#define LED_PORT                PORTD
#define LED_PIN                 2
#define LED_PIN_GREEN           4
#define LED_PIN_RED             3
#define LED_PIN_BLUE            2
#endif


#ifdef HOMEMATIC_BATTERY_ACTOR
#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT     SPI_PORT
#define CC1100_CS_PIN		SPI_SS

#define CC1100_OUT_DDR		DDRD        // GDO0
#define CC1100_OUT_PORT    PORTD
#define CC1100_OUT_PIN     2

#define CC1100_IN_DDR		DDRD        // GDO2
#define CC1100_IN_PORT     PIND
#define CC1100_IN_PIN      3
#define CC1100_INT		INT1
#define CC1100_INTVECT          INT1_vect
#define CC1100_ISC		ISC10
#define CC1100_EICR             EICRA

//#define LED_INV_RGB
#define LED_DDR                 DDRB
#define LED_PORT                PORTB
#define LED_PIN                 0
#define LED_PIN_GREEN           0
#define LED_PIN_RED             0
#define LED_PIN_BLUE            0
#endif


#ifdef CSMV3
#define CC1100_CS_DDR		DDRD
#define CC1100_CS_PORT          PORTD
#define CC1100_CS_PIN		5

#define CC1100_OUT_DDR		DDRC        // GDO0
#define CC1100_OUT_PORT    PORTC
#define CC1100_OUT_PIN     0

#define CC1100_IN_DDR		DDRD        // GDO2
#define CC1100_IN_PORT     PIND
#define CC1100_IN_PIN      3
#define CC1100_INT		INT1
#define CC1100_INTVECT          INT1_vect
#define CC1100_ISC		ISC10
#define CC1100_EICR             EICRA

#define LED_DDR                 DDRD
#define LED_PORT                PORTD
#define LED_PIN                 6
#endif

#ifdef CSMV2
#define CC1100_CS_DDR		DDRD
#define CC1100_CS_PORT          PORTD
#define CC1100_CS_PIN		6

#define CC1100_OUT_DDR		DDRD
#define CC1100_OUT_PORT         PORTD
#define CC1100_OUT_PIN          5

#define CC1100_IN_DDR		DDRD
#define CC1100_IN_PORT          PIND
#define CC1100_IN_PIN           3
#define CC1100_INT		INT1
#define CC1100_INTVECT          INT1_vect
#define CC1100_ISC		ISC10
#define CC1100_EICR             EICRA

#define LED_DDR                 DDRD
#define LED_PORT                PORTD
#define LED_PIN                 2
#endif 

#define BOARD_ID_STR            "CSM868"
#define BOARD_ID_STR433         "CSM433"

#define HAS_UART                1
#define UART_BAUD_RATE          38400

#define TTY_BUFSIZE             128

#define BUSWARE_CSM

#endif
