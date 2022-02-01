/**
 * @file V3_Hatrix_HW.h
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include this file in Hatrix_HW.h, only if you want to programme with this board type.
 * @bug ("Mention any bug here if needed or found.")
 * @warning All the pin, location of pin, address of pin and any other factor must be given correctly with respect to the board.
 * @copyright Copyright (c) 2022. 
 * @brief Hardware Config file for version 3 board.
 * @details This will contain the all the details of version 3 hardware.
 */

#ifndef V3_Hatrix_HW_H
#define V3_Hatrix_HW_H

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


/// There are toatally 8 GPIO pins in the version 3 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                            /*Pin*/    /*Location*/       /*Address*/
const structGPIO IND_GPO0 = { PB0  , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO0
const structGPIO IND_GPO1 = { PB1  , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO1
const structGPIO IND_GPO2 = { PB3  , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO2
const structGPIO IND_GPO3 = { PB4  , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO3
const structGPIO IND_GPO4 = { PB5  , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO4
const structGPIO IND_GPO5 = { PB12 , LOCATION_INTERNAL , EMPTY_DATA } ; // IND_GPO5
//const structGPIO GPOA7    = { 7    , LOCATION_EXTERNAL , 0x20       } ; // GPOA7 // This does not have ground pin together, right. Only used if the ground is used along with this pin. (Maybe having ground externally or something similar to that.) /// If needed we can uncomment this. Mostly, I do not think, we will be using this.
//const structGPIO GPOB7    = { 15   , LOCATION_EXTERNAL , 0x20       } ; // GPOB7 // This does not have ground pin together, right. Only used if the ground is used along with this pin. (Maybe having ground externally or something similar to that.) /// If needed we can uncomment this. Mostly, I do not think, we will be using this.
                  
/// There are toatally 4 ADC pins in the version 3 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*Pin*//*Vref=3.3*//*Resolution*/   /*Location*/   /*Addr*/      /*InputMultiplication*/
const structADC AIN0 = { 0 ,     4096    ,    32768    , LOCATION_EXTERNAL , 0x48 , ((10000+10000+10000)/10000)  }  ; // AIN0
const structADC AIN1 = { 1 ,     4096    ,    32768    , LOCATION_EXTERNAL , 0x48 , ((10000+10000+10000)/10000)  }  ; // AIN1
const structADC AIN2 = { 2 ,     4096    ,    32768    , LOCATION_EXTERNAL , 0x48 , ((10000+10000+10000)/10000)  }  ; // AIN2
const structADC AIN3 = { 3 ,     4096    ,    32768    , LOCATION_EXTERNAL , 0x48 , ((10000+10000+10000)/10000)  }  ; // AIN3

/// There are toatally 6 PWM pins in the version 3 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*PWMPin*//*InhibitPin*//*IsensePin*//*VsensePin*//*Vref=3.3*//*Resolution*/  /*PWMLocation*/   /*InhibitLocation*/  /*IsenseLocation*/  /*VsenseLocation*/  /*PWMAddr*/  /*InhibitAddr*//*IsenseAddr*//*VsenseAddr*//*IsenseResistance*//*VsenseVoltagedivider*/  /*Isense_IdkILIS_VAlue*/
const structPWM PWM0 = {   PA0   ,     2     ,       0      ,    1     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x49    ,      0x49    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM0
const structPWM PWM1 = {   PA1   ,     3     ,       2      ,    3     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x49    ,      0x49    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM1
const structPWM PWM2 = {   PA6   ,     0     ,       0      ,    1     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x4A    ,      0x4A    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM2
const structPWM PWM3 = {   PA7   ,     1     ,       2      ,    3     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x4A    ,      0x4A    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM3
const structPWM PWM4 = {   PB8   ,     4     ,       0      ,    1     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x4B    ,      0x4B    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM4
const structPWM PWM5 = {   PB9   ,     5     ,       2      ,    3     ,    4096    ,    32768   , LOCATION_INTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL , LOCATION_EXTERNAL ,  EMPTY_DATA   ,     0x20     ,     0x4B    ,      0x4B    ,       2000      ,   ((51000+5100)/5100)    ,       10783           } ; // PWM5

/// There are toatally 5 TCI in the version 3 board. Each of them are given unique names as per the KiCAD schematics using above struct.
                       /*Address*/
const structTCI J29 = {  0x67  } ; // J29
const structTCI J25 = {  0x63  } ; // J25
const structTCI J28 = {  0x66  } ; // J28
const structTCI J27 = {  0x65  } ; // J27
const structTCI J26 = {  0x64  } ; // J26

/// Only one Neo Pixel LED via internal pin in the version 2 board. 
                                      /*Pin*/
const structNEOPixelLED NEO_PIXEL = {  PA5  } ; // NEO_PIXEL

/// Only 7 address pins(3 rotory dip switch and 4 fixed pins) are available for Version-3 Board.
                                            /*Pin*//*Pin*//*Pin*//*Pin*//*Pin*//*Pin*//*Pin*/    /*PinLoction*/     /*PinLoction*/      /*PinLoction*/     /*PinLoction*/     /*PinLoction*/     /*PinLoction*/     /*PinLoction*/    /*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*//*PinAddress*/
const structBoardAddressPins BoardAddress = {{  8  ,  9  ,  10  ,  11  ,  12  ,  13  ,  14  }, {LOCATION_EXTERNAL, LOCATION_EXTERNAL, LOCATION_EXTERNAL, LOCATION_EXTERNAL, LOCATION_EXTERNAL, LOCATION_EXTERNAL, LOCATION_EXTERNAL}, {    0x20    ,    0x20    ,    0x20    ,      0x20    ,    0x20     ,     0x20    ,       0x20    }}; // Board Address Pins.

/// Only 1 UART communication is available for Version-3 Board.
                                                  /*Pin*/   /*PinLoction*/     /*PinAddress*/
const structUARTEnablepins UART_1_Ennable_Pin = {  PA8  ,  LOCATION_INTERNAL  ,  EMPTY_DATA  } ; // UART_1_Ennable_Pin

#endif