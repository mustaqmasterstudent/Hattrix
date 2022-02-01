/**
 * @file Hatrix_Cpp_Lib_2_4.ino
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Go to the Hatrix_HW.h file and include the correct Hardware config file in that File.
 *      Then Go the Hatrix.h file and Give the NUMBER_OF_BOARDS in line 34 as per the requiremnet for you. If it is standalone or slave board then it can be "1". If it is Master board with "n" number of slaves, then it should be "n+1"
 * @bug ("Mention any bug here if needed or found.")
 * @warning ("Mention any warning here if needed.")
 * @copyright Copyright (c) 2022. 
 * @brief Example by using Hatrix library.
 * @details Simple Example by using simple functions from all the possible class for version 3 and Version 2 board.
 */

#include"Hatrix.h" // Before starting anything. Navigate to this header file and then navigate to the Hatrix_HW.h header file. Then add the correct header file of the header. To make this work correctly.
                   // In Hatrix.h file and give the NUMBER_OF_BOARDS in line 34 as per the requiremnet for you. If it is standalone or slave board then it can be "01". If it is Master board with "n" number of slaves, then it should be "n+1"
                   // /*******IMPORTANT**************IMPORTANT**************IMPORTANT***************IMPORTANT**********IMPORTANT********IMPORTANT*********IMPORTANT**********IMPORTANT********IMPORTANT*****/

#define SERIAL_DEBUG

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                                    //
#define HATRIX_CLASS // This is for Standalone Boards.                                                                 ///          //
                                                                                                                                    //
//#define HATRIX_CLASS_UART_COMMUNICATION // This is for Master Boards.                                                  ///          //   Any one of the these three defines has to be there. There should not be all together. 
//#define SLAVE_SHOW_IN_MASTER // This is for Master Boards. (This #define requires more than 64 kilobytes of storage)   /*/          //
                                                                                                                                    //
//#define HATRIX_CLASS_UART_COMMUNICATION_SLAVE // This is for Slave Boards.                                             ///          //
                                                                                                                                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define GPIO_CLASS_BOARD_ADDRESS 

//#define NEOPIXEL_CLASS

#define GPIO_CLASS
//#define ADC_CLASS
#define PWM_CLASS
#define TCI_CLASS
#define CO2_CLASS


/// Main Code Starts From Here.

#ifdef HATRIX_CLASS

    #define     STANDALONE_BOARD                    00

    #define     BOARD                               00
    #define     PAGE                                01
    #define     POSITION_OF_VALUE                   02
    #define     VALUE                               03

    Hatrix HATRIX ; // Hatrix Class initialization for stanalone board.

#endif

#ifdef HATRIX_CLASS_UART_COMMUNICATION

    #define     MASTER_BOARD                        00

    #define     BOARD                               00
    #define     PAGE                                01
    #define     POSITION_OF_VALUE                   02
    #define     VALUE                               03

    #if NUMBER_OF_BOARDS >= 02

        #define  SLAVE_1_BOARD  01
    
    #endif

    #if NUMBER_OF_BOARDS >= 03

        #define  SLAVE_2_BOARD  02
    
    #endif

    #if NUMBER_OF_BOARDS >= 04
    
        #define  SLAVE_3_BOARD  03

    #endif // This Keeps on going untill NUMBER_OF_BOARDS >= 32

    HatrixMaster Master; // HatrixMaster Class initialization for master board.

#endif 

#ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE

    #define  SLAVE_BOARD   00
    
    HatrixSlave Slave; // HatrixSlave Class initialization for slave board.
    
#endif 

#ifdef GPIO_CLASS_BOARD_ADDRESS

    GPIO BoardAddressGPIO ; // Board Address

#endif

#ifdef NEOPIXEL_CLASS

    NEOPIXEL Neo = NEOPIXEL(NEO_PIXEL) ; // NEO_PIXEL

#endif

#ifdef V3_Hatrix_HW_H

    #ifdef GPIO_CLASS

        GPIO GPIO_0 = GPIO(IND_GPO0) ; // IND_GPO0    
        GPIO GPIO_1 = GPIO(IND_GPO1) ; // IND_GPO1   
        GPIO GPIO_2 = GPIO(IND_GPO2) ; // IND_GPO2 
        GPIO GPIO_3 = GPIO(IND_GPO3) ; // IND_GPO3  
        GPIO GPIO_4 = GPIO(IND_GPO4) ; // IND_GPO4   
        GPIO GPIO_5 = GPIO(IND_GPO5) ; // IND_GPO5   

    #endif

#endif

#ifdef V2_Hatrix_HW_H

    #ifdef GPIO_CLASS

        GPIO GPIO_0 = GPIO(GPO_CH1) ; // GPO_CH1    
        GPIO GPIO_1 = GPIO(GPO_CH2) ; // GPO_CH2   
        GPIO GPIO_2 = GPIO(GPO_CH3) ; // GPO_CH3 
        GPIO GPIO_3 = GPIO(GPO_CH4) ; // GPO_CH4  
        GPIO GPIO_4 = GPIO(GPO_CH5) ; // GPO_CH5   

    #endif

#endif

#ifdef V3_Hatrix_HW_H

    #ifdef ADC_CLASS

        ADC ADC_0 = ADC(AIN0) ; // AIN0 
        ADC ADC_1 = ADC(AIN1) ; // AIN1 
        ADC ADC_2 = ADC(AIN2) ; // AIN2 
        ADC ADC_3 = ADC(AIN3) ; // AIN3 

    #endif    

#endif

#ifdef V2_Hatrix_HW_H

    #ifdef ADC_CLASS

        ADC ADC_0 = ADC(Aii_1) ; // Aii_1 
        ADC ADC_1 = ADC(Aii_2) ; // Aii_2 

    #endif    

#endif

#ifdef V3_Hatrix_HW_H

    #ifdef PWM_CLASS

        PWM * PWM_0 = new PWM(PWM0) ; // PWM0 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM_1 = new PWM(PWM1) ; // PWM1 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM_2 = new PWM(PWM2) ; // PWM2 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM_3 = new PWM(PWM3) ; // PWM3 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM_4 = new PWM(PWM4) ; // PWM4 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM_5 = new PWM(PWM5) ; // PWM5 // We need to initialitize this constructor with pointer because we use timers.

    #endif  

#endif

#ifdef V2_Hatrix_HW_H

    #ifdef PWM_CLASS

        PWM * PWM0 = new PWM(PWM_1) ; // PWM_1 // We need to initialitize this constructor with pointer because we use timers.
        PWM * PWM1 = new PWM(PWM_2) ; // PWM_2 // We need to initialitize this constructor with pointer because we use timers.

    #endif  

#endif

#ifdef V3_Hatrix_HW_H

    #ifdef TCI_CLASS

        TCI TCI_1_J29 = TCI(J29) ; // J29       
        TCI TCI_2_J25 = TCI(J25) ; // J25       
        TCI TCI_3_J28 = TCI(J28) ; // J28       
        TCI TCI_4_J27 = TCI(J27) ; // J27       
        TCI TCI_5_J26 = TCI(J26) ; // J26      

    #endif  

#endif

#ifdef V2_Hatrix_HW_H

    #ifdef TCI_CLASS

        TCI TCI_1_J114 = TCI(J114) ; // J114       
        TCI TCI_2_J113 = TCI(J113) ; // J113       
        TCI TCI_3_J115 = TCI(J115) ; // J115       
        TCI TCI_4_J116 = TCI(J116) ; // J116       
        TCI TCI_5_J117 = TCI(J117) ; // J117      

    #endif  

#endif

#ifdef CO2_CLASS

    CO2 CO2_1_K30 = CO2(0x69, K30_CO2_TYPE) ; // K30    
    CO2 CO2_2_K33 = CO2(0x6B, K33_CO2_TYPE) ; // K33  

#endif  

unsigned long         ulCurrent_Time                                                                 ; // This is used to calculate the total time of one loop in the board.

#ifdef SERIAL_DEBUG

    #define  NUMBER_OF_SERIAL_INPUT_VIA_USB  4

    String            stringInputSerial    = ""                                                      ; // This is used to read the Serail input via USB.
    uint8_t           u8InputSerialRead                                                              ; // This is used to read the Serail input via USB one by one.
    int               iLoop_Number                                                                   ; // this is used to have an count of loop number in the board.
    uint16_t          u16SerialInput[NUMBER_OF_SERIAL_INPUT_VIA_USB][NUMBER_OF_SERIAL_INPUT_VIA_USB] ; // This is used to proccess the Serail input via USB. We can not change more than NUMBER_OF_SERIAL_INPUT_VIA_USB values at a time.
    uint8_t           u8SerialInputForOneValueCounter                                                ; // This is used as counter for u16SerialInput[u8SerialInputForOneValueCounter][4] variable.
    uint8_t           u8SerialInputCounter                                                           ; // This is used as counter for u16SerialInput[4][u8SerialInputCounter] variable.
    bool              bSerialAvailable                                                               ; // This is used to mention whether the data is available via USB as Serial Input.
                                              
    #ifdef HATRIX_CLASS_UART_COMMUNICATION                                              
                                              
        unsigned long ulMasterTotalTime                                                              ; // This is used to calculate the total time of one loop in the Master board.

    #endif 

#endif

void setup()
{
    #ifdef SERIAL_DEBUG

        Serial.begin(115200);
        /**/ while(!Serial);
    
    #endif

    for(uint8_t u8Board = 0; u8Board < NUMBER_OF_BOARDS; u8Board++)
    {
        for(uint8_t u8Page = 0; u8Page < NUMBER_OF_PAGES_EACH_BOARD; u8Page++)
        {
            for(uint8_t u8Values = 0; u8Values < NUMBER_OF_VALUES_IN_EACH_PAGE; u8Values++)
            {
                u16PagesConcept[u8Board][u8Page][u8Values] = 0;
            }
        }
    }
    
    #ifdef HATRIX_CLASS

        u16PagesConcept[STANDALONE_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[STANDALONE_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This all refers to the number of values in this page in the board.

        u16PagesConcept[STANDALONE_BOARD][CONTROLLER_CONFIGURATION_PAGE][TYPE_OF_THE_BOARD] =  03; // This refers to the Type of the Board.

    #endif

    #ifdef HATRIX_CLASS_UART_COMMUNICATION

        u16PagesConcept[MASTER_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[MASTER_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This all refers to the number of values in this page in the board.

        u16PagesConcept[MASTER_BOARD][CONTROLLER_CONFIGURATION_PAGE][TYPE_OF_THE_BOARD] =  03; // This refers to the Type of the Board.
        
    #endif 

    #ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE
    
        u16PagesConcept[SLAVE_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This all refers to the number of values in this page in the board.
        u16PagesConcept[SLAVE_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This all refers to the number of values in this page in the board.

        u16PagesConcept[SLAVE_BOARD][CONTROLLER_CONFIGURATION_PAGE][TYPE_OF_THE_BOARD] =  03; // This refers to the Type of the Board.

    #endif 

    #ifdef HATRIX_CLASS_UART_COMMUNICATION

        #if NUMBER_OF_BOARDS >= 02       

            u16PagesConcept[SLAVE_1_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of first slave.
            u16PagesConcept[SLAVE_1_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This refers to the number of values in this page of first slave.

        #endif

        #if NUMBER_OF_BOARDS >= 03

            u16PagesConcept[SLAVE_2_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of second slave.
            u16PagesConcept[SLAVE_2_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This refers to the number of values in this page of second slave.

        #endif

        #if NUMBER_OF_BOARDS >= 04

            u16PagesConcept[SLAVE_3_BOARD][CONTROLLER_CONFIGURATION_PAGE   ][ZEROTH_VALUE_OF_EACH_PAGE] =  2; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][SENSOR_HYSTERESIS_LIMIT_PAGE    ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][SENSOR_LIMIT_PAGE               ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][BOARD_CONTROL_PAGE              ][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][ZEROTH_VALUE_OF_EACH_PAGE] = 19; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][IMPORTANT_DATA_PAGE             ][ZEROTH_VALUE_OF_EACH_PAGE] = 26; // This refers to the number of values in this page of third slave.
            u16PagesConcept[SLAVE_3_BOARD][MISCELLANEOUS_DATA_PAGE         ][ZEROTH_VALUE_OF_EACH_PAGE] = 16; // This refers to the number of values in this page of third slave.

        #endif // This Keeps on going untill NUMBER_OF_BOARDS >= 32
        
    #endif
    
    #ifdef  SERIAL_DEBUG

        /**/ Serial.print('*');

    #endif

    #ifdef HATRIX_CLASS

        HATRIX.fnHatrixBegin();  

    #endif

    #ifdef HATRIX_CLASS_UART_COMMUNICATION

        Master.fnHatrixBegin();  

    #endif

    #ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE

        Slave.fnHatrixBegin();  

    #endif

    #ifdef GPIO_CLASS_BOARD_ADDRESS

        BoardAddressGPIO.fnGPIOHatrixBoardAddressInit();

    #endif

    #ifdef NEOPIXEL_CLASS

        Neo.fnNeoLEDBegin();
        Neo.fnNeoLEDColorSetAllLED(Neo.Black);
        Neo.fnNeoLEDColorSet(0, Neo.White);

    #endif

    #ifdef V3_Hatrix_HW_H

        #ifdef GPIO_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1]  = 0b00000000; // This refers to Boatd Control Page: GPIO Control Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1]; // This refers to Boatd Control Configuration Page: Check GPIO Control Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16]  = 0b00000000; // This refers to Boatd Control Page: GPIO SET Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16]; // This refers to Boatd Control Configuration Page: Check GPIO SET Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17]  = 0b00000000; // This refers to Boatd Control Page: GPIO CLEAR Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17]; // This refers to Boatd Control Configuration Page: Check GPIO CLEAR Byte.

            GPIO_0.fnGPIOPinModePinValue();
            GPIO_1.fnGPIOPinModePinValue();
            GPIO_2.fnGPIOPinModePinValue();
            GPIO_3.fnGPIOPinModePinValue();
            GPIO_4.fnGPIOPinModePinValue();
            GPIO_5.fnGPIOPinModePinValue();

        #endif

    #endif

    #ifdef V2_Hatrix_HW_H

        #ifdef GPIO_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1]  = 0b00000000; // This refers to Boatd Control Page: GPIO Control Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1]; // This refers to Boatd Control Configuration Page: Check GPIO Control Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16]  = 0b00000000; // This refers to Boatd Control Page: GPIO SET Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16]; // This refers to Boatd Control Configuration Page: Check GPIO SET Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17]  = 0b00000000; // This refers to Boatd Control Page: GPIO CLEAR Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17]; // This refers to Boatd Control Configuration Page: Check GPIO CLEAR Byte.

            GPIO_0.fnGPIOPinModePinValue();
            GPIO_1.fnGPIOPinModePinValue();
            GPIO_2.fnGPIOPinModePinValue();
            GPIO_3.fnGPIOPinModePinValue();
            GPIO_4.fnGPIOPinModePinValue();

        #endif

    #endif

    #ifdef V3_Hatrix_HW_H

        #ifdef ADC_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2] = 128; // This refers to Boatd Control Page: ADC ADS.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]; // This refers to Boatd Control Configuration Page: Check ADC ADS.    

            ADC_0.fnADCBegin();
            ADC_1.fnADCBegin();
            ADC_2.fnADCBegin();
            ADC_3.fnADCBegin();

            ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
            ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
            ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
            ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);

        #endif 
    
    #endif

    #ifdef V2_Hatrix_HW_H

        #ifdef ADC_CLASS

            ADC_0.fnADCBegin();
            ADC_1.fnADCBegin();

        #endif 
    
    #endif

    #ifdef V3_Hatrix_HW_H

        #ifdef PWM_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]  = 20000; // This refers to Boatd Control Page: PWM-0&1 Freq.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]; // This refers to Boatd Control Configuration Page: Check PWM-0&1 Freq.    

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]  = 20000; // This refers to Boatd Control Page: PWM-2&3 Freq.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]; // This refers to Boatd Control Configuration Page: Check PWM-2&3 Freq.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]  = 20000; // This refers to Boatd Control Page: PWM-4&5 Freq.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]; // This refers to Boatd Control Configuration Page: Check PWM-4&5 Freq.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6]  = 0b00111111; // This refers to Boatd Control Page: PWM InhibitControlByte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6]; // This refers to Boatd Control Configuration Page: Check PWM InhibitControlByte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18]  = 0b00000000; // This refers to Boatd Control Page: PWM SET Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18]; // This refers to Boatd Control Configuration Page: Check PWM SET Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19]  = 0b00000000; // This refers to Boatd Control Page: PWM CLEAR Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19]; // This refers to Boatd Control Configuration Page: Check PWM CLEAR Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]  = 0; // This refers to Boatd Control Page: PWM-0 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]; // This refers to Boatd Control Configuration Page: Check PWM-0 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]  = 0; // This refers to Boatd Control Page: PWM-1 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]; // This refers to Boatd Control Configuration Page: Check PWM-1 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9] = 0; // This refers to Boatd Control Page: PWM-2 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]; // This refers to Boatd Control Configuration Page: Check PWM-2 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10] = 0; // This refers to Boatd Control Page: PWM-3 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]; // This refers to Boatd Control Configuration Page: Check PWM-3 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11] = 0; // This refers to Boatd Control Page: PWM-4 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]; // This refers to Boatd Control Configuration Page: Check PWM-4 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12] = 0; // This refers to Boatd Control Page: PWM-5 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]; // This refers to Boatd Control Configuration Page: Check PWM-5 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13] = 128; // This refers to Boatd Control Page: PWM-0&1 ADS.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][13] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]; // This refers to Boatd Control Configuration Page: Check PWM-0&1 ADS.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14] = 128; // This refers to Boatd Control Page: PWM-2&3 ADS.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]; // This refers to Boatd Control Configuration Page: Check PWM-2&3 ADS.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15] = 128; // This refers to Boatd Control Page: PWM-4&5 ADS.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]; // This refers to Boatd Control Configuration Page: Check PWM-4&5 ADS.

            PWM_0->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][ 7]);
            PWM_1->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][ 8]);
            PWM_2->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][ 9]);
            PWM_3->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]);
            PWM_4->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]);
            PWM_5->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]);

            PWM_0->fnPWMSleepMode();
            PWM_1->fnPWMSleepMode();
            PWM_2->fnPWMSleepMode();
            PWM_3->fnPWMSleepMode();
            PWM_4->fnPWMSleepMode();
            PWM_5->fnPWMSleepMode();

            PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
            PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
            PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
            PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
            PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
            PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);

        #endif 
    
    #endif

    #ifdef V2_Hatrix_HW_H

        #ifdef PWM_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]  = 200; // This refers to Boatd Control Page: PWM-0 Freq.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]; // This refers to Boatd Control Configuration Page: Check PWM-0 Freq.    

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]  = 200; // This refers to Boatd Control Page: PWM-1 Freq.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]; // This refers to Boatd Control Configuration Page: Check PWM-1 Freq.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6]  = 0b00000000; // This refers to Boatd Control Page: PWM InhibitControlByte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6]; // This refers to Boatd Control Configuration Page: Check PWM InhibitControlByte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18]  = 0b00000000; // This refers to Boatd Control Page: PWM SET Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18]; // This refers to Boatd Control Configuration Page: Check PWM SET Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19]  = 0b00000000; // This refers to Boatd Control Page: PWM CLEAR Byte.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19]; // This refers to Boatd Control Configuration Page: Check PWM CLEAR Byte.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]  = 0; // This refers to Boatd Control Page: PWM-0 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]; // This refers to Boatd Control Configuration Page: Check PWM-0 DutyCycle.

            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]  = 0; // This refers to Boatd Control Page: PWM-1 DutyCycle.
            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]; // This refers to Boatd Control Configuration Page: Check PWM-1 DutyCycle.

            PWM0->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][ 7]);
            PWM1->fnPWMBeginStart(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4], u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][ 8]);

            PWM0->fnPWMSleepMode();
            PWM1->fnPWMSleepMode();

        #endif 
    
    #endif

    #ifdef V3_Hatrix_HW_H

        #ifdef TCI_CLASS

            TCI_1_J29.fnTCIBegin();
            TCI_2_J25.fnTCIBegin();
            TCI_3_J28.fnTCIBegin();
            TCI_4_J27.fnTCIBegin();
            TCI_5_J26.fnTCIBegin();

        #endif 

    #endif

    #ifdef V2_Hatrix_HW_H

        #ifdef TCI_CLASS

            TCI_1_J114.fnTCIBegin();
            TCI_2_J113.fnTCIBegin();
            TCI_3_J115.fnTCIBegin();
            TCI_4_J116.fnTCIBegin();
            TCI_5_J117.fnTCIBegin();

        #endif 

    #endif

    #ifdef CO2_CLASS

        //CO2_1_K30.fnCO2Begin(); // /*This function is needed only if we use SCD30 Sensor.*/

    #endif 

    #ifdef GPIO_CLASS_BOARD_ADDRESS

        u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD] = BoardAddressGPIO.fnGPIOHatrixBoardAddress(); // This refers to the address of the board.

        #ifdef SERIAL_DEBUG

            Serial.println(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD]); 

        #endif

    #endif

    #ifdef HATRIX_CLASS_UART_COMMUNICATION
        
        Master.fnHatrixMasterUARTCommunicationBegin();

        /**/ delay(1000);

        #ifdef SERIAL_DEBUG

            /**/ Serial.print('+');

        #endif
        /**/ delay(1000);

        Master.fnHatrixMasterReset();

        /**/ delay(3000);

        #ifdef SERIAL_DEBUG

            /**/ Serial.print('#');

        #endif

        /**/ delay(1000);
        
                                    /*Number Of Slaves Connected*//*First Slave Type*//*Second Slave Type*//*Third Slave Type*//*and so on untill 31st Slave Type*//*First Slave Address*//*Second Slave Address*//*Third Slave Address*//*and so on untill 31st Slave Address*/
        Master.fnHatrixMasterBusScan(             02             , {        03       ,            03      ,                                                      } , {        40          ,           02          ,                                                            } ); // Note Slave address must be different for all the slaves irespective of Slave type.
        Master.fnHatrixMasterRequestingData(SENSOR_HYSTERESIS_LIMIT_PAGE);
        Master.fnHatrixMasterRequestingData(SENSOR_LIMIT_PAGE);
        Master.fnHatrixMasterRequestingData(BOARD_CONTROL_PAGE);
        Master.fnHatrixMasterRequestingData(BOARD_CONTROL_CONFIGURATION_PAGE);

        Master.fnHatrixMasterSendingData(BOARD_CONTROL_PAGE);

    #endif 

    #ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE

        Slave.fnHatrixSlaveUARTCommunicationBegin();

    #endif 

}

void loop()
{ 
    #ifdef HATRIX_CLASS_UART_COMMUNICATION

        #ifdef SERIAL_DEBUG

            Serial.println('#');
            ulMasterTotalTime = micros();
            Serial.println(ulMasterTotalTime);
            Serial.println('#');

        #endif


        fnMasterFullLoopRun();
        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Master.fnHatrixReloadWatchdogToReset();
        #endif
        
        Master.fnHatrixMasterRequestingData(IMPORTANT_DATA_PAGE);
        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Master.fnHatrixReloadWatchdogToReset();
        #endif

        Master.fnHatrixMasterRequestingData(MISCELLANEOUS_DATA_PAGE);
        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Master.fnHatrixReloadWatchdogToReset();
        #endif
        
        #ifdef SERIAL_DEBUG

            #ifdef SLAVE_SHOW_IN_MASTER

                fnMasterSlaveShow();
                #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
                    Master.fnHatrixReloadWatchdogToReset();
                #endif

            #endif
        
        #endif

        Master.fnHatrixMasterReadAllData();  
        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Master.fnHatrixReloadWatchdogToReset();
        #endif

        #ifdef SERIAL_DEBUG

            Serial.println('*');
            ulMasterTotalTime = (micros() - ulMasterTotalTime);
            Serial.println(ulMasterTotalTime);
            Serial.println('*');

        #endif

        delay(500); 

        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Master.fnHatrixReloadWatchdogToReset();
        #endif

    #endif 

    #ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE
       
        Slave.fnHatrixSlaveWaitingForCommandFrame();

        if(Slave.u8SlaveUpdateFlag == 1)
        {
            /**/ fnSlaveUpdate();
            Slave.u8SlaveUpdateFlag = 0;
        }

        if(Slave.u8SlaveFullLoopRunFlag == 1)
        {
            /**/ fnSlaveFullLoopRun();
            Slave.u8SlaveFullLoopRunFlag = 0;
        }

        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            Slave.fnHatrixReloadWatchdogToReset();
        #endif

    #endif 

    #ifdef HATRIX_CLASS
       
        fnFullLoopRun();

        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            HATRIX.fnHatrixReloadWatchdogToReset();
        #endif

    #endif 
}

#ifdef HATRIX_CLASS_UART_COMMUNICATION

    void fnMasterFullLoopRun()
    {
        ulCurrent_Time = micros();  
        #ifdef SERIAL_DEBUG

            Serial.print(ulCurrent_Time); Serial.print(',');   
            iLoop_Number = iLoop_Number + 1;
            Serial.print(iLoop_Number); Serial.print(',');   

        #endif

        #ifdef SERIAL_DEBUG

            u8SerialInputForOneValueCounter = 0;
            u8SerialInputCounter = 0;
            while(Serial.available())
            {
                u8InputSerialRead = Serial.read(); 
                if(u8InputSerialRead != ',' && u8InputSerialRead != '.' && u8SerialInputCounter != NUMBER_OF_SERIAL_INPUT_VIA_USB)
                {
                    stringInputSerial += (char)u8InputSerialRead;
                }
                else if(u8InputSerialRead == '.')
                {
                    u16SerialInput[u8SerialInputCounter][u8SerialInputForOneValueCounter] = (uint16_t)stringInputSerial.toInt();
                    u8SerialInputForOneValueCounter++;
                    stringInputSerial = "";
                }
                else if(u8InputSerialRead == ',')
                {
                    u8SerialInputForOneValueCounter = 0;
                    stringInputSerial = "";
                    u8SerialInputCounter++;
                    bSerialAvailable = true;
                }
            }
            if(bSerialAvailable == true)
            {
                for(uint8_t u8BoardPageValue = 0; u8BoardPageValue < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8BoardPageValue++)
                {
                    u16PagesConcept[(uint8_t)u16SerialInput[u8BoardPageValue][BOARD]][(uint8_t)u16SerialInput[u8BoardPageValue][PAGE]][(uint8_t)u16SerialInput[u8BoardPageValue][POSITION_OF_VALUE]] = u16SerialInput[u8BoardPageValue][VALUE];
                }
                for(uint8_t u8SlaveBoardPageValue = 0; u8SlaveBoardPageValue < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8SlaveBoardPageValue++)
                {
                    if(u16SerialInput[u8SlaveBoardPageValue][BOARD] != MASTER_BOARD)
                    {
                        if(u16SerialInput[u8SlaveBoardPageValue][PAGE] == SENSOR_HYSTERESIS_LIMIT_PAGE || u16SerialInput[u8SlaveBoardPageValue][PAGE] == SENSOR_LIMIT_PAGE || u16SerialInput[u8SlaveBoardPageValue][PAGE] == BOARD_CONTROL_PAGE)
                        {
                            Master.fnHatrixMasterSendingData((uint8_t)u16SerialInput[u8SlaveBoardPageValue][PAGE], Master.u8SlaveTypes[((uint8_t)u16SerialInput[u8SlaveBoardPageValue][BOARD]-1)], Master.u8SlaveAddress[((uint8_t)u16SerialInput[u8SlaveBoardPageValue][BOARD]-1)]);
                        }
                    }
                }
                for(uint8_t u8FirstValueInTwoDimensionalArray; u8FirstValueInTwoDimensionalArray < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8FirstValueInTwoDimensionalArray++)
                {
                    for(uint8_t u8SecondValueInTwoDimensionalArray; u8SecondValueInTwoDimensionalArray < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8SecondValueInTwoDimensionalArray++)
                    {
                        u16SerialInput[u8FirstValueInTwoDimensionalArray][u8SecondValueInTwoDimensionalArray] = 0;
                    }
                }  
                u8InputSerialRead = 0;
                stringInputSerial = "";
                u8SerialInputForOneValueCounter = 0;
                u8SerialInputCounter = 0;
                bSerialAvailable = false;

                #ifdef V3_Hatrix_HW_H

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                            {
                                GPIO_5.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                            {
                                GPIO_5.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                        }

                    #endif

                    #ifdef ADC_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2])
                        {
                            ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2];
                        }

                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                        {
                            PWM_0->fnPWMFrequencyFromStart();
                            PWM_1->fnPWMFrequencyFromStart();
                            PWM_0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            PWM_1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM_0->fnPWMSleepMode() : PWM_0->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000) ? PWM_1->fnPWMSleepMode() : PWM_1->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                        {
                            PWM_2->fnPWMFrequencyFromStart();
                            PWM_3->fnPWMFrequencyFromStart();
                            PWM_2->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            PWM_3->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM_2->fnPWMSleepMode() : PWM_2->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000) ? PWM_3->fnPWMSleepMode() : PWM_3->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5])
                        {
                            PWM_5->fnPWMFrequencyFromStart();
                            PWM_5->fnPWMFrequencyFromStart();
                            PWM_4->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                            PWM_5->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000) ? PWM_4->fnPWMSleepMode() : PWM_4->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000) ? PWM_5->fnPWMSleepMode() : PWM_5->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM_0->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM_0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM_1->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM_1->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                            {
                                PWM_2->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                            {
                                PWM_2->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                            {
                                PWM_3->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                            {
                                PWM_3->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                            {
                                PWM_4->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                            {
                                PWM_4->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                            {
                                PWM_5->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                            {
                                PWM_5->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                        {
                            PWM_0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                        {
                            PWM_1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9])
                        {
                            PWM_2->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10])
                        {
                            PWM_3->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11])
                        {
                            PWM_4->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12])
                        {
                            PWM_5->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][13])
                        {
                            PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                            PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14])
                        {
                            PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                            PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15])
                        {
                            PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                            PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15];
                        }  

                    #endif  

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_5.fnGPIOPinValue(HIGH);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_5.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                        }

                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_0->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_1->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_2->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_3->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_4->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_5->fnPWMActiveMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_1->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_2->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_3->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_4->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_5->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                        }

                    #endif
                
                #endif

                #ifdef V2_Hatrix_HW_H

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                        }

                    #endif 

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                        {
                            PWM0->fnPWMFrequencyFromStart();
                            PWM0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM0->fnPWMSleepMode() : PWM0->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                        {
                            PWM1->fnPWMFrequencyFromStart();
                            PWM1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM1->fnPWMSleepMode() : PWM1->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM0->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM1->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM1->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                        {
                            PWM0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                        {
                            PWM1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                        }
                    
                    #endif 

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                        }

                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM0->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM1->fnPWMActiveMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM1->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                        }

                    #endif

                #endif
            }

        #endif

        #ifdef GPIO_CLASS_BOARD_ADDRESS

            u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD] = BoardAddressGPIO.fnGPIOHatrixBoardAddress(); // This refers to the address of the board.

            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD]); Serial.print(',');

            #endif

        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 5, GPIO_5.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif
        
        #ifdef V3_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] = ADC_2.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-2.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] = ADC_3.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-3.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] / 100); Serial.print(',');

                #endif

                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM_0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM_0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM_0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM_0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM_1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM_1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM_1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM_1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] = PWM_2->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-2-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] = PWM_2->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-2-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] = PWM_2->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-2-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] / 100); Serial.print(',');
                    Serial.print(PWM_2->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif 

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] = PWM_3->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-3-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] = PWM_3->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-3-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] = PWM_3->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-3-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] / 100); Serial.print(',');
                    Serial.print(PWM_3->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] = PWM_4->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-4-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] = PWM_4->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-4-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] = PWM_4->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-4-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] / 100); Serial.print(',');
                    Serial.print(PWM_4->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] = PWM_5->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-5-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] = PWM_5->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-5-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] = PWM_5->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-5-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] / 100); Serial.print(',');
                    Serial.print(PWM_5->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

            #endif  
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 

                #endif

            #endif  
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J29.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J29.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J29.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J25.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J25.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J25.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J28.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J28.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J28.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J27.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J27.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J27.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J26.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J26.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J26.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef V2_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J114.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J114.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J114.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J113.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J113.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J113.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J115.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J115.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J115.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J116.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J116.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J116.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J117.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J117.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J117.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef CO2_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23] = CO2_1_K30.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-0.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23]); Serial.print(',');

            #endif
            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24] = CO2_2_K33.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-1.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24]); Serial.print(',');

            #endif

        #endif 

        ulCurrent_Time = (micros() - ulCurrent_Time);
        #ifdef SERIAL_DEBUG

            Serial.println(ulCurrent_Time);

        #endif

        #ifdef V3_Hatrix_HW_H

            if(ulCurrent_Time > 500000) // Since when I run evrythingthing together it was taking less than 350 milli. ADS1115 is always goes to long delay by itself. So, this condition is given here to manage that.
            {
                #ifdef ADC_CLASS

                    ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);

                #endif

                #ifdef PWM_CLASS

                    PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                    PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);

                #endif
            }

        #endif
    }

#endif

#ifdef HATRIX_CLASS_UART_COMMUNICATION_SLAVE

    void fnSlaveFullLoopRun()
    {
        ulCurrent_Time = micros();  
        #ifdef SERIAL_DEBUG

            Serial.print(ulCurrent_Time); Serial.print(',');   
            iLoop_Number = iLoop_Number + 1;
            Serial.print(iLoop_Number); Serial.print(',');   

        #endif

        #ifdef GPIO_CLASS_BOARD_ADDRESS

            u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD] = BoardAddressGPIO.fnGPIOHatrixBoardAddress(); // This refers to the address of the board.

            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD]); Serial.print(',');

            #endif

        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 5, GPIO_5.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif
        
        #ifdef V3_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] = ADC_2.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-2.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] = ADC_3.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-3.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] / 100); Serial.print(',');

                #endif

                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM_0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM_0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM_0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM_0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM_1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM_1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM_1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM_1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] = PWM_2->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-2-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] = PWM_2->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-2-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] = PWM_2->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-2-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] / 100); Serial.print(',');
                    Serial.print(PWM_2->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif 

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] = PWM_3->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-3-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] = PWM_3->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-3-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] = PWM_3->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-3-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] / 100); Serial.print(',');
                    Serial.print(PWM_3->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] = PWM_4->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-4-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] = PWM_4->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-4-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] = PWM_4->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-4-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] / 100); Serial.print(',');
                    Serial.print(PWM_4->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] = PWM_5->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-5-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] = PWM_5->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-5-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] = PWM_5->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-5-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] / 100); Serial.print(',');
                    Serial.print(PWM_5->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

            #endif  
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 

                #endif

            #endif  
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J29.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J29.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J29.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J25.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J25.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J25.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J28.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J28.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J28.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J27.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J27.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J27.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J26.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J26.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J26.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef V2_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J114.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J114.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J114.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J113.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J113.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J113.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J115.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J115.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J115.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J116.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J116.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J116.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J117.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J117.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J117.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef CO2_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23] = CO2_1_K30.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-0.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23]); Serial.print(',');

            #endif
            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24] = CO2_2_K33.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-1.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24]); Serial.print(',');

            #endif

        #endif 

        ulCurrent_Time = (micros() - ulCurrent_Time);
        #ifdef SERIAL_DEBUG
            
            Serial.println(ulCurrent_Time);
        
        #endif

        #ifdef V3_Hatrix_HW_H

            if(ulCurrent_Time > 500000) // Since when I run evrythingthing together it was taking less than 350 milli. ADS1115 is always goes to long delay by itself. So, this condition is given here to manage that.
            {
                #ifdef ADC_CLASS

                    ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);

                #endif

                #ifdef PWM_CLASS

                    PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                    PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);

                #endif
            }
        
        #endif
    }

    void fnSlaveUpdate()
    {
        #ifdef V3_Hatrix_HW_H

            #ifdef GPIO_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                    {
                        GPIO_0.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                    {
                        GPIO_0.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                    {
                        GPIO_1.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                    {
                        GPIO_1.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                    {
                        GPIO_2.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                    {
                        GPIO_2.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                    {
                        GPIO_3.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                    {
                        GPIO_3.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                    {
                        GPIO_4.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                    {
                        GPIO_4.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                    {
                        GPIO_5.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                    {
                        GPIO_5.fnGPIOPinValue(LOW);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                }

            #endif

            #ifdef ADC_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2])
                {
                    ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2];
                }

            #endif

            #ifdef PWM_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                {
                    PWM_0->fnPWMFrequencyFromStart();
                    PWM_1->fnPWMFrequencyFromStart();
                    PWM_0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                    PWM_1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM_0->fnPWMSleepMode() : PWM_0->fnPWMActiveMode();
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000) ? PWM_1->fnPWMSleepMode() : PWM_1->fnPWMActiveMode();
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                {
                    PWM_2->fnPWMFrequencyFromStart();
                    PWM_3->fnPWMFrequencyFromStart();
                    PWM_2->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                    PWM_3->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM_2->fnPWMSleepMode() : PWM_2->fnPWMActiveMode();
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000) ? PWM_3->fnPWMSleepMode() : PWM_3->fnPWMActiveMode();
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5])
                {
                    PWM_5->fnPWMFrequencyFromStart();
                    PWM_5->fnPWMFrequencyFromStart();
                    PWM_4->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                    PWM_5->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000) ? PWM_4->fnPWMSleepMode() : PWM_4->fnPWMActiveMode();
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000) ? PWM_5->fnPWMSleepMode() : PWM_5->fnPWMActiveMode();
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                    {
                        PWM_0->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                    {
                        PWM_0->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                    {
                        PWM_1->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                    {
                        PWM_1->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                    {
                        PWM_2->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                    {
                        PWM_2->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                    {
                        PWM_3->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                    {
                        PWM_3->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                    {
                        PWM_4->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                    {
                        PWM_4->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                    {
                        PWM_5->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                    {
                        PWM_5->fnPWMSleepMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                {
                    PWM_0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                {
                    PWM_1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9])
                {
                    PWM_2->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10])
                {
                    PWM_3->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11])
                {
                    PWM_4->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12])
                {
                    PWM_5->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][13])
                {
                    PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14])
                {
                    PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15])
                {
                    PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                    PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15];
                }   
            #endif 

            #ifdef GPIO_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_0.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_1.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_2.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_3.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_4.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_5.fnGPIOPinValue(HIGH);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_0.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_1.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_2.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_3.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_4.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_5.fnGPIOPinValue(LOW);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                }

            #endif

            #ifdef PWM_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_0->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_1->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_2->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_3->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_4->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM_5->fnPWMActiveMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_0->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_1->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_2->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_3->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_4->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM_5->fnPWMSleepMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                }

            #endif
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef GPIO_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                    {
                        GPIO_0.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                    {
                        GPIO_0.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                    {
                        GPIO_1.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                    {
                        GPIO_1.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                    {
                        GPIO_2.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                    {
                        GPIO_2.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                    {
                        GPIO_3.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                    {
                        GPIO_3.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                    {
                        GPIO_4.fnGPIOPinValue(HIGH);
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                    {
                        GPIO_4.fnGPIOPinValue(LOW);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                }

            #endif

            #ifdef PWM_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                {
                    PWM0->fnPWMFrequencyFromStart();
                    PWM0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM0->fnPWMSleepMode() : PWM0->fnPWMActiveMode();
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                {
                    PWM1->fnPWMFrequencyFromStart();
                    PWM1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                    ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM1->fnPWMSleepMode() : PWM1->fnPWMActiveMode();
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                    {
                        PWM0->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                    {
                        PWM0->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                    {
                        PWM1->fnPWMActiveMode();
                    }
                    else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                    {
                        PWM1->fnPWMSleepMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                {
                    PWM0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                {
                    PWM1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                }
            
            #endif

            #ifdef GPIO_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_0.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_1.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_2.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_3.fnGPIOPinValue(HIGH);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                    {
                        GPIO_4.fnGPIOPinValue(HIGH);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_0.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_1.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_2.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_3.fnGPIOPinValue(LOW);
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                    {
                        GPIO_4.fnGPIOPinValue(LOW);
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                }

            #endif

            #ifdef PWM_CLASS

                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM0->fnPWMActiveMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                    {
                        PWM1->fnPWMActiveMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                }
                if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                {
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM0->fnPWMSleepMode();
                    }
                    if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                    {
                        PWM1->fnPWMSleepMode();
                    }
                    u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                }

            #endif

        #endif

    }

#endif

#ifdef HATRIX_CLASS

    void fnFullLoopRun()
    {
        ulCurrent_Time = micros();  
        #ifdef SERIAL_DEBUG

            Serial.print(ulCurrent_Time); Serial.print(',');   
            iLoop_Number = iLoop_Number + 1;
            Serial.print(iLoop_Number); Serial.print(',');   

        #endif

        #ifdef SERIAL_DEBUG

            u8SerialInputForOneValueCounter = 0;
            u8SerialInputCounter = 0;
            while(Serial.available())
            {
                u8InputSerialRead = Serial.read(); 
                if(u8InputSerialRead != ',' && u8InputSerialRead != '.' && u8SerialInputCounter != NUMBER_OF_SERIAL_INPUT_VIA_USB)
                {
                    stringInputSerial += (char)u8InputSerialRead;
                }
                else if(u8InputSerialRead == '.')
                {
                    u16SerialInput[u8SerialInputCounter][u8SerialInputForOneValueCounter] = (uint16_t)stringInputSerial.toInt();
                    u8SerialInputForOneValueCounter++;
                    stringInputSerial = "";
                }
                else if(u8InputSerialRead == ',')
                {
                    u8SerialInputForOneValueCounter = 0;
                    stringInputSerial = "";
                    u8SerialInputCounter++;
                    bSerialAvailable = true;
                }
            }
            if(bSerialAvailable == true)
            {
                for(uint8_t u8BoardPageValue = 0; u8BoardPageValue < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8BoardPageValue++)
                {
                    u16PagesConcept[(uint8_t)u16SerialInput[u8BoardPageValue][BOARD]][(uint8_t)u16SerialInput[u8BoardPageValue][PAGE]][(uint8_t)u16SerialInput[u8BoardPageValue][POSITION_OF_VALUE]] = u16SerialInput[u8BoardPageValue][VALUE];
                }
                for(uint8_t u8FirstValueInTwoDimensionalArray; u8FirstValueInTwoDimensionalArray < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8FirstValueInTwoDimensionalArray++)
                {
                    for(uint8_t u8SecondValueInTwoDimensionalArray; u8SecondValueInTwoDimensionalArray < NUMBER_OF_SERIAL_INPUT_VIA_USB; u8SecondValueInTwoDimensionalArray++)
                    {
                        u16SerialInput[u8FirstValueInTwoDimensionalArray][u8SecondValueInTwoDimensionalArray] = 0;
                    }
                }  
                bSerialAvailable = false;   
                u8InputSerialRead = 0;
                stringInputSerial = "";
                u8SerialInputForOneValueCounter = 0;
                u8SerialInputCounter = 0;

                #ifdef V3_Hatrix_HW_H

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                            {
                                GPIO_5.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00100000))
                            {
                                GPIO_5.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                        }

                    #endif

                    #ifdef ADC_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2])
                        {
                            ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][2] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2];
                        }
                    
                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                        {
                            PWM_0->fnPWMFrequencyFromStart();
                            PWM_1->fnPWMFrequencyFromStart();
                            PWM_0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            PWM_1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM_0->fnPWMSleepMode() : PWM_0->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000) ? PWM_1->fnPWMSleepMode() : PWM_1->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                        {
                            PWM_2->fnPWMFrequencyFromStart();
                            PWM_3->fnPWMFrequencyFromStart();
                            PWM_2->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            PWM_3->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM_2->fnPWMSleepMode() : PWM_2->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000) ? PWM_3->fnPWMSleepMode() : PWM_3->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5])
                        {
                            PWM_5->fnPWMFrequencyFromStart();
                            PWM_5->fnPWMFrequencyFromStart();
                            PWM_4->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                            PWM_5->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000) ? PWM_4->fnPWMSleepMode() : PWM_4->fnPWMActiveMode();
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000) ? PWM_5->fnPWMSleepMode() : PWM_5->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][5] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM_0->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM_0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM_1->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM_1->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                            {
                                PWM_2->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100))
                            {
                                PWM_2->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                            {
                                PWM_3->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00001000))
                            {
                                PWM_3->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                            {
                                PWM_4->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00010000))
                            {
                                PWM_4->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00100000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                            {
                                PWM_5->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00100000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00100000))
                            {
                                PWM_5->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                        {
                            PWM_0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                        {
                            PWM_1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9])
                        {
                            PWM_2->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][9] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10])
                        {
                            PWM_3->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][10] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11])
                        {
                            PWM_4->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][11] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12])
                        {
                            PWM_5->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][12] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][13])
                        {
                            PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                            PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14])
                        {
                            PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                            PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][14] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15])
                        {
                            PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                            PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][15] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15];
                        }  

                    #endif  

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_5.fnGPIOPinValue(HIGH);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00100000) == 0b00100000 && (GPIO_5.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_5.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                        }

                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_0->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_1->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_2->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_3->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_4->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM_5->fnPWMActiveMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_1->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000100) == 0b00000100 && (PWM_2->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_2->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00001000) == 0b00001000 && (PWM_3->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_3->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00010000) == 0b00010000 && (PWM_4->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_4->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00100000) == 0b00100000 && (PWM_5->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM_5->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                        }

                    #endif
                
                #endif

                #ifdef V2_Hatrix_HW_H

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000001))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000010))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000100 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00000100) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00000100))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00001000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00001000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00001000))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00010000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] & 0b00010000) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1] & 0b00010000))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][1] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][1];
                        }
                    
                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3])
                        {
                            PWM0->fnPWMFrequencyFromStart();
                            PWM0->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000) ? PWM0->fnPWMSleepMode() : PWM0->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][3] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4])
                        {
                            PWM1->fnPWMFrequencyFromStart();
                            PWM1->fnPWMFrequencyUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]);
                            ((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000100) == 0b00000000) ? PWM1->fnPWMSleepMode() : PWM1->fnPWMActiveMode();
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][4] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000001 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM0->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000001) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000001))
                            {
                                PWM0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000010 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM1->fnPWMActiveMode();
                            }
                            else if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010) == 0b00000000 && (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] & 0b00000010) !=  (u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6] & 0b00000010))
                            {
                                PWM1->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][6] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][6];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7])
                        {
                            PWM0->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][7] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8])
                        {
                            PWM1->fnPWMDutycycleUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]);
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][8] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8];
                        }
                    
                    #endif

                    #ifdef GPIO_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_0.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_1.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_2.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_3.fnGPIOPinValue(HIGH);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  HIGH))
                            {
                                GPIO_4.fnGPIOPinValue(HIGH);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][16] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][16];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000001) == 0b00000001 && (GPIO_0.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_0.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000010) == 0b00000010 && (GPIO_1.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_1.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00000100) == 0b00000100 && (GPIO_2.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_2.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00001000) == 0b00001000 && (GPIO_3.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_3.fnGPIOPinValue(LOW);
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17] & 0b00010000) == 0b00010000 && (GPIO_4.fnGPIOPinStatus() !=  LOW))
                            {
                                GPIO_4.fnGPIOPinValue(LOW);
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][17] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][17];
                        }

                    #endif

                    #ifdef PWM_CLASS

                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM0->fnPWMActiveMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  HIGH))
                            {
                                PWM1->fnPWMActiveMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][18] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][18];
                        }
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] != u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19])
                        {
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000001) == 0b00000001 && (PWM_0->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM0->fnPWMSleepMode();
                            }
                            if((u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19] & 0b00000010) == 0b00000010 && (PWM_1->fnPWMInhibitPinStatus() !=  LOW))
                            {
                                PWM1->fnPWMSleepMode();
                            }
                            u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_CONFIGURATION_PAGE][19] = u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][19];
                        }

                    #endif

                #endif
            }

        #endif

        #ifdef GPIO_CLASS_BOARD_ADDRESS

            u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD] = BoardAddressGPIO.fnGPIOHatrixBoardAddress(); // This refers to the address of the board.

            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD]); Serial.print(',');

            #endif

        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 5, GPIO_5.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef GPIO_CLASS

                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 0, GPIO_0.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 1, GPIO_1.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 2, GPIO_2.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 3, GPIO_3.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                bitWrite(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], 4, GPIO_4.fnGPIOPinStatus()); // This all refers to Imprtant data page: GPIO-Value byte.
                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                #endif

            #endif

        #endif
        
        #ifdef V3_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] = ADC_2.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-2.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][4] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] = ADC_3.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-3.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][5] / 100); Serial.print(',');

                #endif

                #ifdef SERIAL_DEBUG

                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef ADC_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] = ADC_0.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-0.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] = ADC_1.fnADCInputChannelVoltageValue() * 100; // This refers to Imprtant data page: ADC-1.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');

                #endif

            #endif 
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM_0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM_0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM_0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM_0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM_1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM_1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM_1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM_1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] = PWM_2->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-2-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][10] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] = PWM_2->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-2-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] = PWM_2->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-2-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][3] / 100); Serial.print(',');
                    Serial.print(PWM_2->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][9]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif 

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] = PWM_3->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-3-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][12] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] = PWM_3->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-3-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] = PWM_3->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-3-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][4] / 100); Serial.print(',');
                    Serial.print(PWM_3->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][10]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] = PWM_4->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-4-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][14] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] = PWM_4->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-4-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] = PWM_4->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-4-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][5] / 100); Serial.print(',');
                    Serial.print(PWM_4->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][11]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] = PWM_5->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-5-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][16] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] = PWM_5->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-5-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print(','); Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][17] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] = PWM_5->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-5-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][6] / 100); Serial.print(',');
                    Serial.print(PWM_5->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][12]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                #endif

            #endif  
        
        #endif

        #ifdef V2_Hatrix_HW_H

            #ifdef PWM_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] = PWM0->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-0-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] = PWM0->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-0-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] = PWM0->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-0-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                    Serial.print(PWM0->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][7]); Serial.print(','); 

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] = PWM1->fnPWMLoadCurrent() * 100; // This refers to Imprtant data page: PWM-1-Isense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] = PWM1->fnPWMLoadVoltage() * 100; // This refers to Imprtant data page: PWM-1-Vsense.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] = PWM1->fnPWMLoadPower() * 100; // This refers to Miscellaneous data page: PWM-1-Power.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                    Serial.print(PWM1->fnPWMInhibitPinStatus()); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                    Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][8]); Serial.print(','); 

                #endif

            #endif  
        
        #endif

        #ifdef V3_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J29.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J29.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J29.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J25.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J25.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J25.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J28.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J28.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J28.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J27.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J27.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J27.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J26.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J26.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J26.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef V2_Hatrix_HW_H

            #ifdef TCI_CLASS

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] = TCI_1_J114.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-1-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] = TCI_1_J114.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-1-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] = TCI_1_J114.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-1-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] = TCI_2_J113.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-2-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] = TCI_2_J113.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-2-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] = TCI_2_J113.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-2-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] = TCI_3_J115.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-3-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] = TCI_3_J115.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-3-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] = TCI_3_J115.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-3-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] = TCI_4_J116.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-4-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] = TCI_4_J116.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-4-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] = TCI_4_J116.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-4-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                #endif

                u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] = TCI_5_J117.fnTCIThermocoupleTemperature() * 100; // This refers to Imprtant data page: TCI-5-Thermo.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] = TCI_5_J117.fnTCIAmbientTemperature() * 100; // This refers to Miscellaneous data page: TCI-5-Ambient.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');

                #endif
                u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] = TCI_5_J117.fnTCITemperatureDelta() * 100; // This refers to Miscellaneous data page: TCI-5-Delta.
                #ifdef SERIAL_DEBUG

                    Serial.print((float)u16PagesConcept[CURRENT_WORKING_BOARD][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                #endif

            #endif

        #endif 

        #ifdef CO2_CLASS

            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23] = CO2_1_K30.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-0.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][23]); Serial.print(',');

            #endif
            u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24] = CO2_2_K33.fnCO2Carbondioxide(); // This refers to Imprtant data page: CO2-1.
            #ifdef SERIAL_DEBUG

                Serial.print(u16PagesConcept[CURRENT_WORKING_BOARD][IMPORTANT_DATA_PAGE][24]); Serial.print(',');

            #endif

        #endif

        ulCurrent_Time = (micros() - ulCurrent_Time);

        #ifdef SERIAL_DEBUG

            Serial.println(ulCurrent_Time);
        
        #endif

        #ifdef V3_Hatrix_HW_H

            if(ulCurrent_Time > 500000) // Since when I run evrythingthing together it was taking less than 350 milli. ADS1115 is always goes to long delay by itself. So, this condition is given here to manage that.
            {
                #ifdef ADC_CLASS

                    ADC_0.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_1.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_2.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);
                    ADC_3.fnADCConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][2]);

                #endif

                #ifdef PWM_CLASS

                    PWM_0->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_1->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][13]);
                    PWM_2->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_3->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][14]);
                    PWM_4->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);
                    PWM_5->fnPWMConversionRateUpdate(u16PagesConcept[CURRENT_WORKING_BOARD][BOARD_CONTROL_PAGE][15]);

                #endif
            }
            else
            {
                delay(150);
            }

        #endif 

        #if !defined(V3_Hatrix_HW_H)

            delay(150);

        #endif 
    }

#endif

#ifdef SERIAL_DEBUG

    #ifdef HATRIX_CLASS_UART_COMMUNICATION

        #ifdef SLAVE_SHOW_IN_MASTER

            void fnMasterSlaveShow()
            {
                for(uint8_t u8SlaveShow = 1; u8SlaveShow <= Master.u8ConnectedNumberOfSlaves; u8SlaveShow++)
                {
                    Serial.print('S'); Serial.print(u8SlaveShow); Serial.print('=');

                    #ifdef GPIO_CLASS_BOARD_ADDRESS

                        #ifdef SERIAL_DEBUG

                            Serial.print(u16PagesConcept[u8SlaveShow][CONTROLLER_CONFIGURATION_PAGE][2]); Serial.print(',');

                        #endif

                    #endif

                    #ifdef GPIO_CLASS

                        #ifdef SERIAL_DEBUG

                            Serial.print(u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][1], BIN); Serial.print(',');

                        #endif

                    #endif

                    #ifdef ADC_CLASS

                        #ifdef SERIAL_DEBUG

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][2] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][3] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][4] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][5] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][2]); Serial.print(',');

                        #endif

                    #endif 

                    #ifdef PWM_CLASS

                        #ifdef SERIAL_DEBUG

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][6] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][7] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][1] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00000001); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][7]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][8] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][9] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][2] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00000010); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][3]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][8]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][13]); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][10] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][11] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][3] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00000100); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][9]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][12] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][13] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][4] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00001000); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][4]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][10]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][14]); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][14] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][15] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][5] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00010000); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][11]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][16] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][17] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][6] / 100); Serial.print(',');
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][6] & 0b00100000); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][5]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][12]); Serial.print(','); 
                            Serial.print(u16PagesConcept[u8SlaveShow][BOARD_CONTROL_PAGE][15]); Serial.print(',');

                        #endif

                    #endif  

                    #ifdef TCI_CLASS

                        #ifdef SERIAL_DEBUG

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][18] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][7] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][8] / 100); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][19] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][9] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][10] / 100); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][20] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][11] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][12] / 100); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][21] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][13] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][14] / 100); Serial.print(',');

                            Serial.print((float)u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][22] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][15] / 100); Serial.print(',');
                            Serial.print((float)u16PagesConcept[u8SlaveShow][MISCELLANEOUS_DATA_PAGE][16] / 100); Serial.print(',');

                        #endif

                    #endif 

                    #ifdef CO2_CLASS

                        #ifdef SERIAL_DEBUG

                            Serial.print(u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][23]); Serial.print(',');

                            Serial.print(u16PagesConcept[u8SlaveShow][IMPORTANT_DATA_PAGE][24]); Serial.print(',');

                        #endif
                    
                    #endif
                }
            }
        
        #endif

    #endif

#endif
