/**
 * @file V2_Hatrix_HW.h
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include this file in Hatrix_HW.h, only if you want to programme with this board type.
 * @bug ("Mention any bug here if needed or found.")
 * @warning All the pin, location of pin, address of pin and any other factor must be given correctly with respect to the board.
 * @copyright Copyright (c) 2022. 
 * @brief Hardware Config file for version 2 board.
 * @details This will contain the all the details of version 2 hardware.
 */

#ifndef V2_Hatrix_HW_H
#define V2_Hatrix_HW_H

#define      EMPTY_DATA        0              // If the data type is empty.
#define      LOCATION_EXTERNAL 1              // The location of pin will be given 1, if it is external pin.
#define      LOCATION_INTERNAL 2              // The location of pin will be given 2, if it is internal pin.

typedef struct
{
    uint8_t  u8Pin                          ; // Name of the Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8Location                     ; // The location of pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8Address                      ; // Address of the pin will be given here.
}structGPIO;

typedef struct
{
    uint8_t  u8Pin                          ; // Name of the Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint16_t u16ScaleMaximumInternalVoltage ; // The refernce voltage of ADC pin will be given here.
    uint16_t u16Resolution                  ; // Resolution of the ADC pin will be given here.
    uint8_t  u8Location                     ; // The location of pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8Address                      ; // Address of the pin will be given here.
    float    fInputChannelVoltageDivider    ; // Voltage divider Multiplication factor will be given here.
}structADC;  

typedef struct
{
    uint8_t  u8Pin                          ; // Name of the PWM Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8Inhibit                      ; // Name of the Inhibit Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8Isense                       ; // Name of the Isense Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8Vsense                       ; // Name of the Vsense Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint16_t u16ScaleMaximumInternalVoltage ; // The refernce voltage of ADC pin will be given here.
    uint16_t u16Resolution                  ; // Resolution of the ADC pin will be given here.
    uint8_t  u8PWMPinLocation               ; // The location of PWM pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8InhibitLocation              ; // The location of Inhipbit pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8IsenseLocation               ; // The location of Isense pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8VsenseLocation               ; // The location of Vsense pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8PWMPinAddress                ; // Address of the PWM pin will be given here.
    uint8_t  u8InhibitAddress               ; // Address of the Inhipbit pin will be given here.
    uint8_t  u8IsenseAddress                ; // Address of the Isense pin will be given here.
    uint8_t  u8VsenseAddress                ; // Address of the Vsense pin will be given here.
    float    fIsenseResistanceValue         ; // Resistance value to calculate Isense will be given here.
    float    fVsenseVoltageDividerValue     ; // Voltage divider Multiplication factor will be given here.
    float    fIsenseIdkILIS                 ; // IdkILIS value to calculate Load Current.
}structPWM;

typedef struct
{
    uint8_t  u8Address                      ; // There are possible of 8 I2C address {0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67} for MCP9600 IC.
}structTCI;

typedef struct
{
    uint8_t  u8NeoPixelLEDPin               ; // Name of the Neo Pixel LED Pin as per the MCU.
}structNEOPixelLED;

typedef struct
{
    uint8_t  u8AddressPins[7]               ; // Name of the Board Address Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8AddressPinsLocation[7]       ; // The location of pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8AddressPinsAddress[7]        ; // Address of the pin will be given here.
}structBoardAddressPins;

typedef struct
{
    uint8_t  u8EnablePin                    ; // Name of the UART enable Pin as per the MCU for internal pins, and for external pins as per documentation in the library we used.
    uint8_t  u8EnablePinLocation            ; // The location of pin will be given LOCATION_INTERNAL for internal pin and LOCATION_EXTERNAL for external pin.
    uint8_t  u8EnablePinAddress             ; // Address of the pin will be given here.
}structUARTEnablepins;

/// There are toatally 5 GPIO pins in the version 2 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                            /*Pin*/    /*Location*/       /*Address*/
const structGPIO GPO_CH1 = {  PB8  , LOCATION_INTERNAL , EMPTY_DATA } ; // GPO_CH1
const structGPIO GPO_CH2 = {  PB5  , LOCATION_INTERNAL , EMPTY_DATA } ; // GPO_CH2
const structGPIO GPO_CH3 = {  PB4  , LOCATION_INTERNAL , EMPTY_DATA } ; // GPO_CH3
const structGPIO GPO_CH4 = {  PB3  , LOCATION_INTERNAL , EMPTY_DATA } ; // GPO_CH4
const structGPIO GPO_CH5 = {  PA15 , LOCATION_INTERNAL , EMPTY_DATA } ; // GPO_CH5

/// There are toatally 2 ADC pins in the version 2 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*Pin*//*Vref*//*Res*/   /*Location*/     /*Addr*/   /*InputMultiplication*/
const structADC Aii_1 = { PA0 , 3300 , 4096 , LOCATION_INTERNAL , EMPTY_DATA , ((10000+10000+10000)/10000) } ; // Aii_1
const structADC Aii_2 = { PA1 , 3300 , 4096 , LOCATION_INTERNAL , EMPTY_DATA , ((10000+10000+10000)/10000) } ; // Aii_2

/// There are toatally 2 PWM pins in the version 2 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*PWMPin*//*InhibitPin*//*IsensePin*/    /*VsensePin*/  /*Vref*//*Res*/  /*PWMLocation*/   /*InhibitLocation*/  /*IsenseLocation*/  /*VsenseLocation*/   /*PWMAddr*/       /*InhibitAddr*/       /*IsenseAddr*/   /*VsenseAddr*//*IsenseResistance*//*VsenseVoltagedivider*//*Isense_IdkILIS_VAlue*/
const structPWM PWM_1 = {  PA8  ,     PB1     ,    PB0    ,     EMPTY_DATA    ,  3300 , 4096 , LOCATION_INTERNAL , LOCATION_INTERNAL , LOCATION_INTERNAL , LOCATION_EXTERNAL ,   EMPTY_DATA   ,     EMPTY_DATA     ,     EMPTY_DATA    ,     0X40    ,        2000      ,          EMPTY_DATA     ,         10000         }; // PWM_1
const structPWM PWM_2 = {  PA6  ,     PA7     ,    PA5    ,     EMPTY_DATA    ,  3300 , 4096 , LOCATION_INTERNAL , LOCATION_INTERNAL , LOCATION_INTERNAL , LOCATION_EXTERNAL ,   EMPTY_DATA   ,     EMPTY_DATA     ,     EMPTY_DATA    ,     0X42    ,        2000      ,          EMPTY_DATA     ,         10000         }; // PWM_2

/// There are toatally 5 TCI in the version 2 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*Address*/
const structTCI J114 = {  0x64  } ; // J114
const structTCI J113 = {  0x66  } ; // J113
const structTCI J115 = {  0x65  } ; // J115
const structTCI J116 = {  0x63  } ; // J116
const structTCI J117 = {  0x62  } ; // J117

/// Only one Neo Pixel LED via internal pin in the version 2 board. 
                                      /*Pin*/
const structNEOPixelLED NEO_PIXEL = {  PB9  } ; // NEO_PIXEL

/// Only 3 address pins (rotory dip switch) are available for Version-2 Board.
                                              /*Pin*//*Pin*//*Pin*/   /*Pin*/     /*Pin*/     /*Pin*/     /*Pin*/      /*PinLoction*/     /*PinLoction*/      /*PinLoction*/     /*PinLoction*/     /*PinLoction*/     /*PinLoction*/     /*PinLoction*/    /*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*/
const structBoardAddressPins BoardAddress = {{ PB12 , PB13 , PB14 , EMPTY_DATA, EMPTY_DATA, EMPTY_DATA, EMPTY_DATA}, {LOCATION_INTERNAL, LOCATION_INTERNAL, LOCATION_INTERNAL, LOCATION_INTERNAL, LOCATION_INTERNAL, LOCATION_INTERNAL, LOCATION_INTERNAL}, { EMPTY_DATA ,  EMPTY_DATA ,  EMPTY_DATA ,  EMPTY_DATA ,  EMPTY_DATA ,  EMPTY_DATA ,  EMPTY_DATA  }}; // Board Address Pins.

/// Only 2 UART communication is available for Version-3 Board.
                                                  /*Pin*/    /*PinLoction*/     /*PinAddress*/
const structUARTEnablepins UART_1_Ennable_Pin = {  PC14  ,  LOCATION_INTERNAL  ,  EMPTY_DATA  } ; // UART_1_Ennable_Pin
const structUARTEnablepins UART_2_Ennable_Pin = {  PA4   ,  LOCATION_INTERNAL  ,  EMPTY_DATA  } ; // UART_2_Ennable_Pin

#endif
