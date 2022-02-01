/**
 * @file Hatrix_HW.h
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include the correct Hardware Config File in this file with respect to the board you programme.
 * @bug ("Mention any bug here if needed or found.")
 * @warning Any Changes to this file must be taken in to note with board version for version management and with respect to functionalities as well.
 * @copyright Copyright (c) 2022.
 * @brief It is header file with all the possible funtionalities in the Hatrix System.
 * @details This will contain the all the classess of all the functionalities supported by the Hatrix hardware. It is also imprtant to add the correct hardware config file only in this file.
 */

#ifndef Hatrix_HW_H
#define Hatrix_HW_H

#include "Arduino.h"                                                                   // This is mandatory.
                            
#include "V3_Hatrix_HW.h"  /*******************IMPORTANT****************************/  // This include file will change according to the hardware. This is where we have to include the correct hardware file as per the hardware.

#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    #include <Wire.h>                                                                  // This is included to use the I2C communication.                   
    #if defined(V3_Hatrix_HW_H)                            
        #include <SPI.h>                                                               // This is included to use the SPI communication.
    #endif   
    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        #include <IWatchdog.h>                                                         // This is included to use Watchdog to use it for reset.
    #endif                           
    // Extenal Libraries are added here.
    #if defined(V3_Hatrix_HW_H)                            
        #include <Adafruit_MCP23X17.h>                                                 // This is included handle External GPIO pins using I2C1 communication.
        #include <ADS1115_WE.h>                                                        // This is included handle External ADC pins using I2C1 communication.
    #endif                                       
    #if defined(V2_Hatrix_HW_H)                                       
        #include <INA226_WE.h>                                                         // This is included Caculate Voltage in PWM using I2C1 communication. 
    #endif                            
    #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)                           
        #include <SparkFun_MCP9600.h>                                                  // This is included handle TCI using I2C1 communication.
    #endif
    #include <SparkFun_SCD30_Arduino_Library.h>                                        // This is included handle CO2 using I2C2 only for SCD communication.
    #include <Adafruit_NeoPixel.h>                                                     // This is included Handle NeoPixelLED.
    #if defined(V3_Hatrix_HW_H)
        //#include <SD.h>                                                              // This libraray is suposed to be included if we use SD card via SPI2 interface. But due to storage issue, we did not use it now.                                      
        //#include <Adafruit_GFX.h>                                                    // This libraray is suposed to be included to supposrt the dispaly, if we use Display via SPI2 interface. But due to storage issue, we did not use it now.  
        //#include <Waveshare_ILI9486.h>                                               // This libraray is suposed to be included if we use Display via SPI2 interface. But due to storage issue, we did not use it now.              
    #endif
#endif

#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    extern      TwoWire I2C_1                                                        ; // Twowire object is initialized for Wire(I2C1).
    extern      TwoWire I2C_2                                                        ; // Twowire object is initialized for I2C2.
    #if defined(V3_Hatrix_HW_H)             
        extern  SPIClass SPI_2                                                       ; // SPIClass object is initialized for SPI2.
    #endif             
    extern      HardwareSerial UART_1                                                ; // HardwareSerial object is initialized for USART1.
    #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)             
        extern  HardwareSerial UART_2                                                ; // HardwareSerial object is initialized for USART2.
    #endif             
    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)             
        extern      TIM_TypeDef *InstanceOfTimer_1                                   ; // The timer 1 is initialized to use it for general purpose.
        extern      HardwareTimer *Timer_1                                           ; // HardwareTimer object is initialized for Timer 1 with pointer because, this should not be destroyed.
    #endif                
    #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)                
        extern      TIM_TypeDef *InstanceOfTimer_2                                   ; // The timer 2 is initialized to use it for general purpose.
        extern      HardwareTimer *Timer_2                                           ; // HardwareTimer object is initialized for Timer 2 with pointer because, this should not be destroyed.
    #endif                
    #if defined(VCO2_Hatrix_HW_H)                
        extern      TIM_TypeDef *InstanceOfTimer_3                                   ; // The timer 3 is initialized to use it for general purpose.
        extern      HardwareTimer *Timer_3                                           ; // HardwareTimer object is initialized for Timer 3 with pointer because, this should not be destroyed.
    #endif                
    #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)                
        extern      TIM_TypeDef *InstanceOfTimer_4                                   ; // The timer 4 is initialized to use it for general purpose.
        extern      HardwareTimer *Timer_4                                           ; // HardwareTimer object is initialized for Timer 4 with pointer because, this should not be destroyed.
    #endif
#endif

#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    class       GPIO                                                                 ; // This class is used for GPIO
    class       ADC                                                                  ; // This class is used for ADC
    #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)            
        class   PWM                                                                  ; // This class is used for PWM
        class   TCI                                                                  ; // This class is used for TCI
    #endif            
    class       CO2                                                                  ; // This class is used for CO2
    class       NEOPIXEL                                                             ; // This class is used for NEOPIXEL
#endif



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************-----GPIO---START-----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    /**
     * @brief GPIO class for Hatrix System. 
     * This will be used to handle all the General Purpose Input/Output pins. 
     * Mostly We will be using Output Mode.
     */
    class GPIO
    {
        public : 
            /**
             * @brief Construct a new GPIO object
             * For Version 3 board, it also initiates the external GPIO.
             * 
             * @param structGPIOConfig This is struct type which contoins all the necessary information of the 
             * GPIO pin in the xx_Hatrix_HW.h file. 
             */
            GPIO                                 (structGPIO structGPIOConfig)                                    ; 
            /**
             * @brief Construct a new GPIO object. 
             * This Contructor should be used when we want read the board of the address. 
             * fnGPIOHatrixBoardAddressInit and fnGPIOHatrixBoardAddress are to be used with this contruct. 
             * Ths will be used for communication between different hardwares.
             */
            GPIO                                 ()                                                               ; 
            /**
             * @brief Destroy the GPIO object
             * 
             */
            ~GPIO                                ()                                                               ;

            /**
             * @brief This function to set the pin Mode of the GPIO pin. 
             * It is recomended to use it only one at begining.
             * 
             * @param u8GPIOPinMode "OUTPUT" or "INPUT". Default will be "OUTPUT". 
             */
            void    fnGPIOPinMode                (uint8_t u8GPIOPinMode = OUTPUT)                                 ;
            /**
             * @brief This function to set the pin value of the GPIO pin.
             * 
             * @param u8GPIOHIGHorLOW "HIGH" or "LOW".
             */
            void    fnGPIOPinValue               (uint8_t u8GPIOHIGHorLOW)                                        ;
            /**
             * @brief This function to read the pin value of the GPIO pin.
             * 
             * @return uint8_t u8PinStatus (if it is HIGH, it will return 1 or if it is LOW it will return 0).
             */
            uint8_t fnGPIOPinStatus              ()                                                                ;
            /**
             * @brief This function is used if we want to toggle the GPIO pin from HIGH to LOW or from LOW to HIGH
             * 
             */
            void    fnGPIOToggle                 ()                                                                ;
            /**
             * @brief This function used if we want to give pin Mode and pin Value at same same time. 
             * It is recomended to use it only one at begining.
             *  
             * @param u8GPIOPinMode "OUTPUT" or "INPUT". Default will be "OUTPUT". 
             * @param u8GPIOHIGHorLOW "HIGH" or "LOW". Default will be "LOW". 
             */
            void    fnGPIOPinModePinValue        (uint8_t u8GPIOPinMode  = OUTPUT, uint8_t u8GPIOHIGHorLOW = LOW)  ;

            /**
             * @brief This function is used only to set the pin MODES of address pins of the hardware. 
             * All the pins are set to "INPUT_PULLUP".
             * 
             */
            void    fnGPIOHatrixBoardAddressInit ()                                                                ;
            /**
             * @brief This function is used to read the board address of the hardware.
             * 
             * @return uint8_t u8BoardAddress. (This will be determined by reading the pins which are 
             * dedecated to address of the board)
             */
            uint8_t fnGPIOHatrixBoardAddress     ()                                                                ;

            #if defined(V3_Hatrix_HW_H)
                Adafruit_MCP23X17                GPIOexternal                                                      ; // This will be initialized only if we have external GPIO.
            #endif        
         
        protected :                  
            
            structGPIO                           structGPIOConfig                                                  ; // This will store all the values of struct which we call during Construct.
             
            uint8_t                              u8GPIOPinStatus                                                   ; // This will store the status of the GPIO pin.
    };                 
#endif
/**********************************-----GPIO-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------ADC---START-----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    /**
     * @brief ADC class for Hatrix System. 
     * This will be used to handle all the Analog to Digital Converter pins. 
     * Mostly We will be using it to read it as INPUT_ANALOG.
     * 
     */
    class ADC
    {
        public : 
            /**
             * @brief Construct a new ADC object
             * For Version 3 board, it initiates the external ADC with coressponding address.
             * 
             * @param structADCConfig This is struct type which contoins all the 
             * necessary information of the ADC pin in the xx_Hatrix_HW.h file. 
             */
            ADC                                      (structADC structADCConfig)                  ; 
            /**
             * @brief Destroy the ADC object
             * 
             */
            ~ADC                                     ()                                           ; 

            /**
             * @brief This function used to set the ADC pins or initialize the ADC pins.
             * To read an analog value from internal pin ADC pin will be set to 
             * "INPUT_ANALOG" mode. To read an analog values from external ADC, 
             * then the initialization takes place.
             * 
             */
            void  fnADCBegin                         ()                                           ; 

            /**
             * @brief This function is used to get the Volatge value from the ADC.
             * 
             * @return float fVolatge will be returned.
             */
            float fnADCInputChannelVoltageValue      ()                                           ; 
            /**
             * @brief This function is used to get the Milli Volatge value from the ADC.
             * 
             * @return float fMilliVolatge will be returned.
             */
            float fnADCInputChannelMilliVoltageValue ()                                           ; 

            #if defined(V3_Hatrix_HW_H)
                /**
                 * @brief This function is used to update the conversion rate of external ADC. 
                 * 
                 * @param u16ConversionRate "8" or "16" or "32" or "64" or "128" or 
                 * "250" or "475" or "860". default will "128". Above 128 we might get wrong 
                 * values due to noise. But less than 128 will give more precise values 
                 * but this will take lot of time.
                 */
                void  fnADCConversionRateUpdate      (uint16_t u16ConversionRate)                 ; 
            #endif                 
                 
            #if defined(V3_Hatrix_HW_H)                 
                ADS1115_WE                           ADCexternal                                  ; // This will be initialized only if we have external ADC.
            #endif                 
                 
        protected :                  
                 
            structADC                                structADCConfig                              ; // This will store all the values of struct which we call during Construct.
                 
            float                                    fADCVoltageValue                             ; // This will store the volatge value of the ADC pins.
            float                                    fADCMilliVoltageValue                        ; // This will store the Milli volatge value of the ADC pins.
            int16_t                                  s16ADCRawresult                              ; // This will store the raw value of the ADC pins.
    };    
#endif                               
/**********************************------ADC-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------PWM----START----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)    
    /**
     * @brief PWM class for Hatrix System. 
     * This will be used to handle all the Pulse Width Modulation pins. 
     * Mostly We will be using it to control the PWM and read the Load Volatage, Load Current, and Load Power.
     * 
     */
    class PWM
    {
        public : 
            /**
             * @brief Construct a new PWM object
             * For Version 3 board, it initiates the external GPIO and ADC with coressponding address, if needed.
             * For Version 2 board, it initiates the INA226 to meassure the voltage at output.
             * 
             * @param structPWMConfig This is struct type which contoins all the necessary information of the 
             * PWM configuration in the xx_Hatrix_HW.h file.
             */
            PWM                                    (structPWM structPWMConfig)                                                         ; 
            /**  
             * @brief Destroy the PWM object  
             *   
             */  
            ~PWM                                   ()                                                                                  ; 
  
            /**  
             * @brief This function is used to begin the whole functionality of PWM, by initializing the timer corespomding to   
             * PWM pin. And all other necessary peripherals are initialized and set to begin the PWM. We use BTN8962TA.  
             * For Version 3 board, we use external GPIO for Inhibit pin and esternal ADC with coressponding address for I_sense and  
             * V_sense measuremnet.  
             * For Version 2 board, we use INA226 to meassure the voltage at output.  
             *   
             * @param u16Frequency from "0" to "20000". Anywhere between "0" to "20000" is acceptable.  
             * @param u8Dutycycle from "0" to "100". Anywhere between "0" to "100" is acceptable.  
             */  
            void     fnPWMBeginStart               (uint16_t u16Frequency, uint8_t u8Dutycycle)                                        ; 
  
            /**  
             * @brief This function is used to update the DutyCycle of PWM.  
             *   
             * @param u8Dutycycle from "0" to "100". Anywhere between "0" to "100" is acceptable.  
             */  
            void     fnPWMDutycycleUpdate          (uint8_t u8Dutycycle)                                                               ; 
  
            /**  
             * @brief This function is used before fnPWMFrequencyUpdate function to update the Frequency of PWM.   
             *   
             */  
            void     fnPWMFrequencyFromStart       ()                                                                                  ; 
            /**  
             * @brief This function is used to update the Frequency of PWM. Before, this function it is recomended to   
             * use fnPWMFrequencyFromStart function.  
             *   
             * @param u16Frequency from "0" to "20000". Anywhere between "0" to "20000" is acceptable.  
             */  
            void     fnPWMFrequencyUpdate          (uint16_t u16Frequency)                                                             ; 
  
            /**  
             * @brief This function is used to stop the PWM completely by making Inhibit pin of PWM to LOW.  
             *   
             */  
            void     fnPWMSleepMode                ()                                                                                  ; 
            /**  
             * @brief This function is used to Start the PWM again by making Inhibit pin of PWM to HIGH.  
             *   
             */  
            void     fnPWMActiveMode               ()                                                                                  ; 
            
            /**
             * @brief This function is used to get the status of the PWM Inhibit pin status.
             * 
             * @return uint8_t Status of the Inhibit pin will returned as "0" or "1" for "LOW" or "HIGH".
             */
            uint8_t  fnPWMInhibitPinStatus         ()                                                                                  ;
  
            /**  
             * @brief This function is used to OFF the PWM completely by making PWM pin of PWM to LOW. (Than is 0.)  
             *   
             */  
            void     fnPWMPinOff                   ()                                                                                  ; 
            /**  
             * @brief This function is used to ON the PWM completely by making PWM pin of PWM to HIGH. (Than is 100.)  
             *   
             */  
            void     fnPWMPinOn                    ()                                                                                  ; 
  
            #if defined(V3_Hatrix_HW_H)  
                /**  
                 * @brief This function is used to update the conversion rate of external ADC,  
                 * which is used to measure I_sense and Vsense.   
                 *   
                 * @param u16ConversionRate "8" or "16" or "32" or "64" or "128" or "250" or "475" or "860". default will "128".   
                 * Above 128 we might get wrong values due to noise. But less than 128 will give more precise values,   
                 * but this will take lot of time.  
                 */  
                void fnPWMConversionRateUpdate     (uint16_t u16ConversionRate)                                                        ; 
            #endif  
              
            /**  
             * @brief This function is used to get the Load Current of the PWM.  
             *   
             * @return float fLoadCurrent will be returned.  
             */  
            float    fnPWMLoadCurrent              ()                                                                                  ; 
            /**  
             * @brief This function is used to get the Load Volatge of the PWM.  
             *   
             * @return float fLoadVoltage will be returned.  
             */  
            float    fnPWMLoadVoltage              ()                                                                                  ; 
  
            /**  
             * @brief This function is used to get the Load Power of the PWM by Multiblying fLoadCurrent and fLoadVolatge.  
             *   
             * @return float fLoadPower will be returned.  
             */  
            float    fnPWMLoadPower                ()                                                                                  ; 
  
            HardwareTimer *                        MyTim                                                                               ; // This Hardware Timer will be initialized with pointer so that this wont be destructed.
            TIM_TypeDef   *                        Instance                                                                            ; // This TIM_TypeDef of Timer will be initialized with pointer so that this wont be destructed.
            uint8_t                                u8PWMChannel                                                                        ; // The respective channel of the PWM pin will be stored here corresponding to the timer.
  
            #if defined(V3_Hatrix_HW_H)  
                Adafruit_MCP23X17                  PWMGPIOexternal                                                                     ; // This will be initialized only if we have external GPIO for PWM.
                ADS1115_WE                         PWMADCExternal                                                                      ; // This will be initialized only if we have external ADC for PWM.
            #endif  
  
            #if defined(V2_Hatrix_HW_H)  
                INA226_WE                          PWMI2CExternal_V                                                                    ; // This will be initialized only if we want to measure the load voltage through INA226 chip.
            #endif  
  
        protected :                                                              
  
            structPWM                              structPWMConfig                                                                     ; // This will store all the values of struct which we call during Construct.
  
            uint16_t                               u16PWMFrequency                                                                     ; // This will store the frequency value of the PWM.
            uint8_t                                u8PWMDutycycle                                                                      ; // This will store the dutycycle value of the PWM.

            uint8_t                                u8PWMInhibitPinStatus                                                               ; // This will store the status of the Inhibit pin of the PWM.
  
            #if defined(V3_Hatrix_HW_H)   
                int16_t                            s16PWM_I_Load_Raw_Result                                                            ; // This will store the raw result from the I_sense pin of the PWM.
                int16_t                            s16PWM_V_Load_Raw_Result                                                            ; // This will store the raw result from the V_sense pin of the PWM (that is raw results from Load Voltage).
            #endif  
  
            #if defined(V2_Hatrix_HW_H)   
                uint16_t                           u16PWMIsenseADCValue[1020]                                                          ; // This will store the raw result from the I_sense pin of the PWM. (upto [1024] values.)
                uint32_t                           u32PWMIsenseADCRawResultSumValue                                                    ; // This will sum up the raw resluts of all the I_sense values that is available and store it.
                uint16_t                           u16PWMCounter                                                                       ; // This will be the counter for u32PWMIsenseADCValue. from 0 to 1024.
                uint8_t                            u8PWMNumberOfSamplesPerCycle        =        12                                     ; // This will say the number of samples to be taken per cycle. 
                uint8_t                            u8PWMNumberOfCyclesToSample         =        85                                     ; // This will say the number of cycles to sample. 
            #endif  
  
            float                                  fPWMLoadCurrent                                                                     ; // This will store the Load Current value of the PWM.     
            float                                  fPWMLoadVoltage                                                                     ; // This will store the Load Volatage value of the PWM.
            float                                  fPWMLoadPower                                                                       ; // This will store the Load Power value of the PWM.
    }; 

    #if defined(V2_Hatrix_HW_H)
        /**
         * @brief This function is used only to read the analog value of version 2 board. 
         * 
         * @param u8IsensePin Address of the I_sense pin is given and the pin variable is accesed via pointer.
         * @param u16PWMIsenseADCValue Address of the u32PWMIsenseADCValue[u16PWMCounter] is given and the variable is accesed via pointer.
         * @param u16PWMCounter Address of the u16PWMCounter is given and the variable is accesed via pointer.
         * @return uint32_t u32PWMIsenseADCValue[u16PWMCounter] returns the value to the corresponding address via pointer.
         */
        static inline uint32_t fnPWMVersion2Isense(uint8_t * u8IsensePin, uint16_t * u16PWMIsenseADCValue, uint16_t * u16PWMCounter)
        {
            *u16PWMIsenseADCValue = adc_read_value(analogInputToPinName(*u8IsensePin), 12); // Reads the raw result of ADC of the I_sense pin of the version2 borad. And store it in u32PWMIsenseADCValue[u16PWMCounter].
            *u16PWMCounter++; // We add 1 to the u16PWMCounter for next iteration.
            if(*u16PWMCounter == 1020)
            {
                *u16PWMCounter = 0;
            }
            return *u16PWMIsenseADCValue; // Returns the value of u32PWMIsenseADCValue[u16PWMCounter].
        }
    #endif
#endif
/**********************************------PWM----END------*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------TCI---START-----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)    
    /**
     * @brief TCI class for Hatrix System. 
     * This will be used to handle all the Thermocouple Inputs via I2C1. 
     * 
     */
    class TCI
    {
        public : 
            /**
             * @brief Construct a new TCI object
             * This will initialitize the MCP9600.
             * 
             * @param structTCIConfig This is struct type which 
             * contoins all the necessary information of the 
             * TCI configuration in the xx_Hatrix_HW.h file.
             */
            TCI                                (structTCI structTCIConfig) ; 
            /**
             * @brief Destroy the TCI objectdd
             * 
             */
            ~TCI                               ()                          ; 

            /**
             * @brief This function is used to begin functionalities of 
             * TCI via I2C1.
             * 
             */
            void  fnTCIBegin                   ()                          ; 

            /**
             * @brief This function is used to get the Thermocouple 
             * temperature from hot junction.
             * 
             * @return float fThermocoupleTemperature will be returned.
             */
            float fnTCIThermocoupleTemperature ()                          ; 
            /**
             * @brief This function is used to get the Ambient 
             * temperature from cold junction.
             * 
             * @return float fAmbientTemperature will be returned.
             */
            float fnTCIAmbientTemperature      ()                          ; 
            /**
             * @brief This function is used to get the Delta temperature.
             * 
             * @return float fTemperatureDelta will be returned.
             */
            float fnTCITemperatureDelta        ()                          ; 
    
            MCP9600                            TCIexternalI2C              ; // MCP9600 chip is initialized via I2C1.

        protected : 

            structTCI                          structTCIConfig             ; // This will store all the values of struct which we call during Construct.

            float                              fTCIThermocoupleTemperature ; // This will store the Thermocouple Temperature value of the TCI from Hot junction.     
            float                              fTCIAmbientTemperature      ; // This will store the Ambient Temperature value of the TCI from Cold junction.     
            float                              fTCITemperatureDelta        ; // This will store the Delta Temperature value of the TCI.     
    };
#endif
/**********************************------TCI-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------CO2---START-----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    #define SCD30_CO2_TYPE 61
    #define K30_CO2_TYPE   30
    #define K33_CO2_TYPE   33
    
    /**
     * @brief CO2 class for Hatrix System. 
     * This will be used to handle all the Carbon-di-oxide sensors via I2C2 (SCD30, K30, K33). 
     * 
     */
    class CO2
    {
        public : 
            /**
             * @brief Construct a new CO2 object
             * For "SCD30_CO2_TYPE" sensor type this will initialize the SCD30. 
             * For "K30_CO2_TYPE" and "K30_CO2_TYPE" type sensors, this will set the scale facter to "1" and "10".
             * 
             * @param u8Co2Address Address of the Co2 sensor must be given here.
             * @param u8Co2Type Type of the Co2 Sensor has to be given here. 
             *                  "SCD30_CO2_TYPE" or "K30_CO2_TYPE" or "K30_CO2_TYPE". 
             * @param wirePort The port of the I2C can be given here. But This has defult to I2C_2 port.
             *                 You can ignore this if you do not want to change the default port.
             *                 It is also recomended to use I2C2 port for "K30_CO2_TYPE" or "K30_CO2_TYPE" sensors.
             *                 For Version CO2 sensor borad prefernce must be more in I2C1 port than I2C2.
             * 
             */
            CO2                         (uint8_t u8Co2Address, uint8_t u8Co2Type, TwoWire &wirePort = I2C_2)        ; 
            /**       
             * @brief Destroy the CO2 object       
             *        
             */       
            ~CO2                        ()                                                                          ; 
                   
            /**       
             * @brief This function is used to begin functionalities of CO2 sensor via I2C2.        
             * For "SCD30_CO2_TYPE" type sensors this function is needed.       
             * For "K30_CO2_TYPE" and "K30_CO2_TYPE" type sensors this function is not needed.       
             *        
             */       
            void     fnCO2Begin         ()                                                                          ; 
       
            /**       
             * @brief This function is used to get the Carbon-di-oxide level from the Co2 Sensor.       
             *        
             * @return uint16_t u16Carbondioxide will be returned.       
             */       
            uint16_t fnCO2Carbondioxide ()                                                                          ; 
       
            SCD30                       CO2externalI2C                                                              ; // SCD30 sensor will be initialized if we use SCD30 sensor type.
       
        protected :                                 
       
            uint8_t                     u8Co2SensorAddress                                                          ; // This will store the address of the CO2 sensor.
            uint8_t                     u8Co2SensorType                                                             ; // This will store the sensor type of the CO2 sensor.
            uint8_t                     u8Co2K3xScaleFactor                                                         ; // This will store the scale facor for K30 oe K33 types of the CO2 sensor. 
        
            uint16_t                    u16CO2Carbondioxide                                                         ; // This will store the CO2 level in PPM.
        
            TwoWire *                   I2C_2_Port                                                                  ; // This will have the I2C port used for CO2 with pointer.
    };
#endif
/**********************************------CO2-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------NEO---START-----*************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    /**
     * @brief NEOPIXEL class for Hatrix System. 
     * This will be used to handle Neo Pixel LED. 
     * 
     */
    class NEOPIXEL
    {
        public : 
            /**
             * @brief Construct a new NEOPIXEL object
             * This will contruct an object for NEO pixel LED.
             * 
             * @param structNEOPixelLEDConfig This is struct type which contoins all the necessary information 
             *                                of the Neo Pixel LED configuration in the xx_Hatrix_HW.h file.
             * @param u8NumberofLED Default is "8". In case of changing the default,
             *                      you can give here as per the NEOPIXEL LED.
             */
            NEOPIXEL                    (structNEOPixelLED structNEOPixelLEDConfig, uint8_t u8NumberofLED = 8) ; 
            /**
             * @brief Destroy the NEOPIXEL object
             * 
             */
            ~NEOPIXEL                   ()                                                                     ; 

            /**
             * @brief This function is used to begin the functionalities of Neo Pixel LED.
             * And set the Neo pixel pin mode as OUTPUT.
             * 
             */
            void fnNeoLEDBegin          ()                                                                     ; 

            /**
             * @brief This function is used set the LED Color separately. 
             * 
             * @param u8LEDNumber Here The number of LED must be given. 
             *                    For example: We consider NEOPIXEL of 8 LED. 
             *                    To change the color of First LED. We have to give here as "0".
             *                    To change the color of Second LED. We have to give here as "1".
             *                    And so on.
             *                    To change the color of Last LED (that is eighth LED). 
             *                    We have to give here as "7".
             * @param u32Color Color of the LED can be given here. Since all the colors are public members
             *                 of the same class. You can access upto 25 colors through this class object.
             */
            void fnNeoLEDColorSet       (uint8_t u8LEDNumber, uint32_t u32Color)                               ; 
            /**
             * @brief This function is used set the LED Color of whole Neo Pixel. 
             * 
             * @param u32Color Color of the LED can be given here. Since all the colors are public members
             *                 of the same class. You can access upto 25 colors through this class object.
             */
            void fnNeoLEDColorSetAllLED (uint32_t u32Color)                                                    ; 

            Adafruit_NeoPixel            NeoLED                                                                ; // This is initialized to use the Neo Pixel as our desire.

                                                        /*R*/ /*G*/ /*B*/
            uint32_t Black              = fnColorLED   (   0 ,   0 ,   0 )                                     ; // Black Color.
            uint32_t White              = fnColorLED   ( 255 , 255 , 255 )                                     ; // White Color.
            uint32_t Red                = fnColorLED   ( 255 ,   0 ,   0 )                                     ; // Red Color.
            uint32_t Lime               = fnColorLED   (   0 , 255 ,   0 )                                     ; // Lime Color.
            uint32_t Blue               = fnColorLED   (   0 ,   0 , 255 )                                     ; // Blue Color.
            uint32_t Yellow             = fnColorLED   ( 255 , 255 ,   0 )                                     ; // Yellow Color.
            uint32_t Cyan               = fnColorLED   (   0 , 255 , 255 )                                     ; // Cyan Color.
            uint32_t Magenta            = fnColorLED   ( 255 ,   0 , 255 )                                     ; // Magenta Color.
            uint32_t Silver             = fnColorLED   ( 192 , 192 , 192 )                                     ; // Silver Color.
            uint32_t Gray               = fnColorLED   ( 128 , 128 , 128 )                                     ; // Gray Color.
            uint32_t Maroon             = fnColorLED   ( 128 ,   0 ,   0 )                                     ; // Maroon Color.
            uint32_t Olive              = fnColorLED   ( 128 , 128 ,   0 )                                     ; // Olive Color.
            uint32_t Green              = fnColorLED   (   0 , 128 ,   0 )                                     ; // Green Color.
            uint32_t Purple             = fnColorLED   ( 128 ,   0 , 128 )                                     ; // Purple Color.
            uint32_t Teal               = fnColorLED   (   0 , 128 , 128 )                                     ; // Teal Color.
            uint32_t Navy               = fnColorLED   (   0 ,   0 , 128 )                                     ; // Navy Color.
            uint32_t Brown              = fnColorLED   ( 165 , 42  ,  42 )                                     ; // Brown Color.
            uint32_t Orange             = fnColorLED   ( 255 , 165 ,   0 )                                     ; // Orange Color.
            uint32_t Gold               = fnColorLED   ( 255 , 215 ,   0 )                                     ; // Gold Color.
            uint32_t Violet             = fnColorLED   ( 238 , 130 , 238 )                                     ; // Violet Color.
            uint32_t Pink               = fnColorLED   ( 255 , 192 , 203 )                                     ; // Pink Color.
            uint32_t Beige              = fnColorLED   ( 245 , 245 , 220 )                                     ; // Beige Color.
            uint32_t Tan                = fnColorLED   ( 210 , 180 , 140 )                                     ; // Tan Color.
            uint32_t Hengst_Yellow      = fnColorLED   ( 248 , 196 ,   0 )                                     ; // Hengst_Yellow Color.
            uint32_t Hengst_Blue        = fnColorLED   (  15 ,  29 ,  82 )                                     ; // Hengst_Blue Color.

        protected : 

            structNEOPixelLED           structNEOPixelLEDConfig                                                ; // This will store all the values of struct which we call during Construct.

            uint8_t                     u8NumberOfLEDInNeoPixel                                                ; // This will stor the Number LEDs in Neo Pixel.

            /**
             * @brief This function is protected function of this class. This function is used to set colors.
             * 
             * @param u8RED Value of Red Color in RGB style.
             * @param u8Green Value of Green Color in RGB style.
             * @param u8Blue Value of Blue Color in RGB style.
             * @return uint32_t Returns the desired color in RGB style.
             */
            uint32_t fnColorLED         (uint8_t u8RED, uint8_t u8Green, uint8_t u8Blue)                       ; 


    };
#endif
/**********************************------NEO-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



#endif
