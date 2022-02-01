/**
 * @file Hatrix_HW.cpp
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include the correct Hardware Config File in Hatrix_HW.h file.
 * @bug ("Mention any bug here if needed or found.")
 * @warning Any Changes to this file must be taken in to note with board version for version management and with respect to functionalities as well.
 * @copyright Copyright (c) 2022.
 * @brief It is .cpp file with all the possible funtionalities in the Hatrix System.
 * @details This will contain the all the functionalities supported by the hardware for the Hatrix System.
 */

#include"Hatrix_HW.h"

#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    TwoWire I2C_1 = TwoWire(PB7, PB6); // Wire(I2C1) pins (SDA, SCL) configured with initialized TwoWire Object.
    TwoWire I2C_2 = TwoWire(PB11, PB10); // I2C2 pins (SDA, SCL) configured with initialized TwoWire Object.
    #if defined(V3_Hatrix_HW_H)
        SPIClass SPI_2 = SPIClass(PB15, PB14, PB13); // SPI2 pins (MOSI, MISO, SCLK) configured with initialized SPIClass Object.
    #endif
    HardwareSerial UART_1 = HardwareSerial(PA10, PA9); // USART1 pins (Rx, Tx) configured with initialized HardwareSerial Object.
    #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)
        HardwareSerial UART_2 = HardwareSerial(PA3, PA2); // USART2 pins (Rx, Tx) configured with initialized HardwareSerial Object.
    #endif
    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        TIM_TypeDef *InstanceOfTimer_1 = TIM1; // The timer 1 is initialized to use it for general purpose.
        HardwareTimer *Timer_1 = new HardwareTimer(InstanceOfTimer_1); // HardwareTimer object is initialized for Timer 1 with pointer because, this should not be destroyed.
    #endif   
    #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)   
        TIM_TypeDef *InstanceOfTimer_2 = TIM2; // The timer 2 is initialized to use it for general purpose.
        HardwareTimer *Timer_2 = new HardwareTimer(InstanceOfTimer_2); // HardwareTimer object is initialized for Timer 2 with pointer because, this should not be destroyed.
    #endif   
    #if defined(VCO2_Hatrix_HW_H)   
        TIM_TypeDef *InstanceOfTimer_3 = TIM3; // The timer 3 is initialized to use it for general purpose.
        HardwareTimer *Timer_3 = new HardwareTimer(InstanceOfTimer_3); // HardwareTimer object is initialized for Timer 3 with pointer because, this should not be destroyed.
    #endif   
    #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)   
        TIM_TypeDef *InstanceOfTimer_4 = TIM4; // The timer 4 is initialized to use it for general purpose.
        HardwareTimer *Timer_4 = new HardwareTimer(InstanceOfTimer_4); // HardwareTimer object is initialized for Timer 4 with pointer because, this should not be destroyed.
    #endif
#endif



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************-----GPIO---START-----*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    GPIO::GPIO(structGPIO GPIOstruct)
    {
        structGPIOConfig = GPIOstruct; // This will store the details of the GPIO pin in the respective struct.
        #if defined(V3_Hatrix_HW_H)
            GPIOexternal = Adafruit_MCP23X17(); // External GPIO is initialized.
        #endif
    }

    GPIO::GPIO()
    {
        #if defined(V3_Hatrix_HW_H)
            GPIOexternal = Adafruit_MCP23X17(); // External GPIO is initialized.
        #endif
    }

    GPIO::~GPIO()
    {

    }

    void GPIO::fnGPIOPinMode(uint8_t u8PinMode)
    {
        #if defined(V3_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structGPIOConfig.u8Address == 0x20)
                {
                    GPIOexternal.begin_I2C(); // This is used to begin the External GPIO.
                    GPIOexternal.pinMode(structGPIOConfig.u8Pin, u8PinMode); // pin Mode is set for the External GPIO.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
            else if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                pinMode(structGPIOConfig.u8Pin, u8PinMode); // pin Mode is set for the Internal GPIO.
            }
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                pinMode(structGPIOConfig.u8Pin, u8PinMode); // pin Mode is set for the Internal GPIO.
            }
        #endif
    }

    void GPIO::fnGPIOPinValue(uint8_t u8HIGHorLOW)
    {
        #if defined(V3_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structGPIOConfig.u8Address == 0x20)
                {
                    GPIOexternal.digitalWrite(structGPIOConfig.u8Pin, u8HIGHorLOW); // pin Value is set for the External GPIO.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
            else if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                digitalWrite(structGPIOConfig.u8Pin, u8HIGHorLOW); // pin Value is set for the Internal GPIO.         
            }
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                digitalWrite(structGPIOConfig.u8Pin, u8HIGHorLOW); // pin Value is set for the Internal GPIO.             
            }
        #endif
    }

    uint8_t GPIO::fnGPIOPinStatus()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structGPIOConfig.u8Address == 0x20)
                {
                    u8GPIOPinStatus = GPIOexternal.digitalRead(structGPIOConfig.u8Pin); // pin status is read and stored for External GPIO.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                    return u8GPIOPinStatus;
                }
            }
            else if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                u8GPIOPinStatus = digitalRead(structGPIOConfig.u8Pin); // pin status is read and stored for Internal GPIO.
                return u8GPIOPinStatus;
            }
            return u8GPIOPinStatus;
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                u8GPIOPinStatus = digitalRead(structGPIOConfig.u8Pin); // pin status is read and stored for Internal GPIO.
                return u8GPIOPinStatus;
            }
            return u8GPIOPinStatus;
        #endif
    }

    void GPIO::fnGPIOToggle()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structGPIOConfig.u8Address == 0x20)
                {
                    GPIOexternal.digitalWrite(structGPIOConfig.u8Pin, !GPIOexternal.digitalRead(structGPIOConfig.u8Pin)); // pin is toggled for External GPIO.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
            else if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                digitalWrite(structGPIOConfig.u8Pin, !digitalRead(structGPIOConfig.u8Pin)); // pin is toggled for Internal GPIO.
            }
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structGPIOConfig.u8Location == LOCATION_INTERNAL)
            {
                digitalWrite(structGPIOConfig.u8Pin, !digitalRead(structGPIOConfig.u8Pin)); // pin is toggled for Internal GPIO.
            }
        #endif
    }

    void GPIO::fnGPIOPinModePinValue(uint8_t u8PinMode, uint8_t u8HIGHorLOW)
    {
        fnGPIOPinMode(u8PinMode); // sets the Pin Mode of the GPIO.
        fnGPIOPinValue(u8HIGHorLOW); // sets the Pin Value of the GPIO.
    }

    void GPIO::fnGPIOHatrixBoardAddressInit()
    {
        #if defined(V3_Hatrix_HW_H)
            GPIOexternal.begin_I2C(); // This is used to begin the External GPIO.
            for(uint8_t i = 0; i<7; i++)
            {
                GPIOexternal.pinMode(BoardAddress.u8AddressPins[i], INPUT_PULLUP); // sets the pin Mode to "INPUT_PULLUP" for all the GPIO pins which is dedicated to Board address of the hardware.
            }  
            I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.  
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            for(uint8_t i = 0; i<3; i++)
            {
                pinMode(BoardAddress.u8AddressPins[i], INPUT_PULLUP); // sets the pin Mode to "INPUT_PULLUP" for all the GPIO pins which is dedicated to Board address of the hardware.
            }
        #endif  
    }

    uint8_t GPIO::fnGPIOHatrixBoardAddress()
    {
        #if defined(V3_Hatrix_HW_H)
            uint8_t BoardADDRESS = 0; // This is going to be board address.
            for(int i = 0; i<7; i++)
            {
                bitWrite(BoardADDRESS, i, GPIOexternal.digitalRead(BoardAddress.u8AddressPins[i])); // Writes in bitwise to get the correct board address of the hardware.
            }
            I2C_1.flush();  // Wire(I2C1) is cleared before we proceed further.
            return BoardADDRESS; // Returns the board address.
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            uint8_t BoardADDRESS = 0; // This is going to be board address.
            for(int i = 0; i<3; i++)
            {
                bitWrite(BoardADDRESS, i, digitalRead(BoardAddress.u8AddressPins[i])); // Writes in bitwise to get the correct board address of the hardware.
            }
            return BoardADDRESS; // Returns the board address.
        #endif      
    }
#endif 
/*********************************************************************************************************************************************/
/**********************************-----GPIO---END-------*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------ADC--START------*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    ADC::ADC(structADC ADCstruct)
    {
        structADCConfig = ADCstruct; // This will store the details of the ADC pin in the respective struct.
        #if defined(V3_Hatrix_HW_H)
            ADCexternal = ADS1115_WE(structADCConfig.u8Address); // External ADC is initialized.
        #endif
    }

    ADC::~ADC() 
    {

    }

    void ADC::fnADCBegin()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structADCConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structADCConfig.u8Address == 0x48)
                {
                    ADCexternal.init(); // Initializes the external ADC.
                    ADCexternal.setVoltageRange_mV(ADS1115_RANGE_4096); // Sets the voltage range for external ADC. We wont read more tan 3.3 volts in the ADC pin.
                    ADCexternal.setMeasureMode(ADS1115_CONTINUOUS); // Sets the ADS to continous mode.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structADCConfig.u8Location == LOCATION_INTERNAL)
            {
                pinMode(structADCConfig.u8Pin, INPUT_ANALOG); // For internal ADC pin mode is set to INPUT_ANALOG.   
            }
        #endif
    }

    float ADC::fnADCInputChannelMilliVoltageValue()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structADCConfig.u8Location == LOCATION_EXTERNAL)
            {
                if(structADCConfig.u8Address == 0x48)
                {
                    ADCexternal.setSingleChannel(structADCConfig.u8Pin); // External ADC channel is set to read the corresponding ADC pin. After this we will have some delay because we have only one conversionsion register for 4 ADC channels in ADS1115. 
                    s16ADCRawresult = ADCexternal.getRawResult(); // After the delay we read raw results directly from the registers for external ADC.
                    /**/ Serial.print(s16ADCRawresult);
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                    return fADCMilliVoltageValue = (float)( (float)( s16ADCRawresult * structADCConfig.u16ScaleMaximumInternalVoltage * structADCConfig.fInputChannelVoltageDivider ) / structADCConfig.u16Resolution ); // After calculation using raw result returns the Milli Voltafe value.
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            if(structADCConfig.u8Location == LOCATION_INTERNAL)
            {
                s16ADCRawresult = adc_read_value(analogInputToPinName(structADCConfig.u8Pin), 12); // Reads the raw result of ADC of the ADC pin. And store it in s16ADCRawresult.
                return fADCMilliVoltageValue = (float)( (float)( s16ADCRawresult * structADCConfig.u16ScaleMaximumInternalVoltage * structADCConfig.fInputChannelVoltageDivider ) / structADCConfig.u16Resolution ); // After calculation using raw result returns the Milli Voltafe value.
            }
        #endif
        return fADCMilliVoltageValue;
    }

    float ADC::fnADCInputChannelVoltageValue()
    {
        return fADCMilliVoltageValue = (float)( fnADCInputChannelMilliVoltageValue() / 1000.00f ) ; // After calculation using the values from fnADCInputChannelMilliVoltageValue function and returns the Voltafe value.
    }

    #if defined(V3_Hatrix_HW_H)
        void ADC::fnADCConversionRateUpdate(uint16_t u16ConversionRate)
        {
            switch(u16ConversionRate)
            {
                case 8 : 
                    ADCexternal.setConvRate(ADS1115_8_SPS); // Sets the conversion rate to 8 samples per second. This will have delay of 260 milli seconds. More Precise.
                    break;
                case 16 : 
                    ADCexternal.setConvRate(ADS1115_16_SPS); // Sets the conversion rate to 16 samples per second. This will have delay of 130 milli seconds.
                    break;
                case 32 : 
                    ADCexternal.setConvRate(ADS1115_32_SPS); // Sets the conversion rate to 32 samples per second. This will have delay of 64 milli seconds.
                    break;
                case 64 : 
                    ADCexternal.setConvRate(ADS1115_64_SPS); // Sets the conversion rate to 64 samples per second. This will have delay of 32 milli seconds.
                    break;
                case 128 : 
                    ADCexternal.setConvRate(ADS1115_128_SPS); // Sets the conversion rate to 128 samples per second. This will have delay of 16 milli seconds. This is Default.
                    break;
                case 250 : 
                    ADCexternal.setConvRate(ADS1115_250_SPS); // Sets the conversion rate to 250 samples per second. This will have delay of 8 milli seconds. Will have noise.
                    break;
                case 475 : 
                    ADCexternal.setConvRate(ADS1115_475_SPS); // Sets the conversion rate to 450 samples per second. This will have delay of 6 milli seconds. Will have noise.
                    break;
                case 860 : 
                    ADCexternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                    break;
                default : 
                    if(u16ConversionRate < 8)
                    {
                        ADCexternal.setConvRate(ADS1115_8_SPS); // Sets the conversion rate to 8 samples per second. This will have delay of 260 milli seconds. More Precise.
                    }
                    else if(u16ConversionRate < 16)
                    {
                        ADCexternal.setConvRate(ADS1115_16_SPS); // Sets the conversion rate to 16 samples per second. This will have delay of 130 milli seconds.
                    }
                    else if(u16ConversionRate < 32)
                    {
                        ADCexternal.setConvRate(ADS1115_32_SPS); // Sets the conversion rate to 32 samples per second. This will have delay of 64 milli seconds.
                    }
                    else if(u16ConversionRate < 64)
                    {
                        ADCexternal.setConvRate(ADS1115_64_SPS); // Sets the conversion rate to 64 samples per second. This will have delay of 32 milli seconds.
                    }
                    else if(u16ConversionRate < 128)
                    {
                        ADCexternal.setConvRate(ADS1115_128_SPS); // Sets the conversion rate to 128 samples per second. This will have delay of 16 milli seconds. Will have noise.
                    }
                    else if(u16ConversionRate < 250)
                    {
                        ADCexternal.setConvRate(ADS1115_250_SPS); // Sets the conversion rate to 250 samples per second. This will have delay of 8 milli seconds. Will have noise.
                    }
                    else if(u16ConversionRate < 475)
                    {
                        ADCexternal.setConvRate(ADS1115_475_SPS); // Sets the conversion rate to 475 samples per second. This will have delay of 6 milli seconds. Will have noise.
                    }
                    else if(u16ConversionRate < 860)
                    {
                        ADCexternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                    }
                    else
                    {
                        ADCexternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                    }
                    break;
            }
            I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        }
    #endif
#endif
/*********************************************************************************************************************************************/
/**********************************------ADC--END--------*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------PWM---START-----*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)
    PWM::PWM(structPWM PWMstruct)
    {
        structPWMConfig = PWMstruct; // This will store the details of the PWM in the respective struct.
        #if defined(V3_Hatrix_HW_H)
            PWMGPIOexternal = Adafruit_MCP23X17(); // External GPIO is initialized, if needed.
            if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
            {
                if(structPWMConfig.u8IsenseAddress  == 0x49 || 0x4A || 0x4B)
                {
                    PWMADCExternal = ADS1115_WE(structPWMConfig.u8IsenseAddress); // External ADC is initialized with respective I2C address, if needed.
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8VsenseAddress == 0X40 || 0X42)
            {
                PWMI2CExternal_V = INA226_WE(structPWMConfig.u8VsenseAddress); // INA226 chip is initialized to measure the load voltage, if needed.
            }
        #endif
    }

    PWM::~PWM()
    {

    }

    void PWM::fnPWMBeginStart(uint16_t u16Frequency, uint8_t u8Dutycycle)
    {
        u16PWMFrequency = u16Frequency; // This will store the frequency value from the user.
        u8PWMDutycycle = u8Dutycycle; // This will store the dutycycle value from the user.
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    PWMGPIOexternal.begin_I2C(); // This is used to begin the External GPIO.
                    PWMGPIOexternal.pinMode(structPWMConfig.u8Inhibit, OUTPUT); // Inhibit pin of the PWM, pin mode is set as OUTPUT.
                    pinMode(structPWMConfig.u8Pin, OUTPUT); // PWM pin of the PWM, pin mode is set as OUTPUT.
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.init(); // Initializes the external ADC.
                        PWMADCExternal.setVoltageRange_mV(ADS1115_RANGE_4096); // Sets the voltage range for external ADC. We wont read more tan 3.3 volts in the ADC pin.
                        PWMADCExternal.setMeasureMode(ADS1115_CONTINUOUS); // Sets the ADS to continous mode.
                    }
                    PWMGPIOexternal.digitalWrite (structPWMConfig.u8Inhibit, HIGH); // Inhibit pin of the PWM, pin value is set to HIGH.
                    digitalWrite (structPWMConfig.u8Pin, HIGH); // PWM pin of the PWM, pin value is set to HIGH.
                    Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(structPWMConfig.u8Pin), PinMap_PWM); // Respective Timer corresponding to the PWM pin is configured and stored.
                    u8PWMChannel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(structPWMConfig.u8Pin), PinMap_PWM)); // Respective Channel of the timer corresponding to the PWM pin is configured and stored.
                    MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM.
                    MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle.               
                }
            }
            I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        #endif
        #if defined(V2_Hatrix_HW_H)
            u16PWMCounter = 0; // In the begining of the PWM. The counter is given as 0. This will be used to measure Isense raw results.
            pinMode(structPWMConfig.u8Inhibit, OUTPUT); // Inhibit pin of the PWM, pin mode is set as OUTPUT.
            pinMode(structPWMConfig.u8Pin, OUTPUT); // PWM pin of the PWM, pin mode is set as OUTPUT.
            pinMode(structPWMConfig.u8Isense, INPUT_ANALOG);
            PWMI2CExternal_V.init(); // Initializes the INA226 chip to measure the load volatge.
            PWMI2CExternal_V.setAverage(AVERAGE_1024); // sets INA226 to take an average of 1024.
            PWMI2CExternal_V.setConversionTime(CONV_TIME_140); // sets INA226 conversion time to 140 micro seconds.
            PWMI2CExternal_V.setResistorRange(0.00225,10.0); // sets INA226 resistor and current range independant. resistor value in ohm, current range in A.
            I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
            digitalWrite (structPWMConfig.u8Inhibit, HIGH); // Inhibit pin of the PWM, pin value is set to HIGH.            
            digitalWrite (structPWMConfig.u8Pin, HIGH); // PWM pin of the PWM, pin value is set to HIGH.^
            Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(structPWMConfig.u8Pin), PinMap_PWM); // Respective Timer corresponding to the PWM pin is configured and stored.
            u8PWMChannel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(structPWMConfig.u8Pin), PinMap_PWM)); // Respective Channel of the timer corresponding to the PWM pin is configured and stored.
            if(u16PWMFrequency <= 500)
            {
                MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM.
                MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle.    
                MyTim->setOverflow((u16PWMFrequency*u8PWMNumberOfSamplesPerCycle), HERTZ_FORMAT); // sets the overflow in timer to measure the Isense raw result. this will be used to make an interupts.
                MyTim->attachInterrupt(std::bind(fnPWMVersion2Isense, &structPWMConfig.u8Isense, &u16PWMIsenseADCValue[u16PWMCounter], &u16PWMCounter)); // sets the interupt in timer to measure the Isense raw result. This uses call back function and also passes three vaiables with their addresses and access them via pointers.
                MyTim->resume(); // After the completion of call back function. Timer resumes (that is, the main code will continue.)
            }
            else
            {
                MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM.
                MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle.    
            }
        #endif
    }

    void PWM::fnPWMDutycycleUpdate(uint8_t u8Dutycycle)
    {
        u8PWMDutycycle = u8Dutycycle; // This will store the dutycycle value from the user.  
        MyTim->setCaptureCompare(u8PWMChannel, u8PWMDutycycle, PERCENT_COMPARE_FORMAT); // this is used to update the dutycycle of the PWM.
    }

    void PWM::fnPWMFrequencyFromStart()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    PWMGPIOexternal.digitalWrite(structPWMConfig.u8Inhibit, LOW); // It is recomonded to make the Inhibit and PWM pin to low before updating the frequency.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                    digitalWrite(structPWMConfig.u8Pin, LOW); // It is recomonded to make the Inhibit and PWM pin to low before updating the frequency.              
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_INTERNAL)
                {
                    digitalWrite(structPWMConfig.u8Inhibit, LOW); // It is recomonded to make the Inhibit and PWM pin to low before updating the frequency.           
                    digitalWrite(structPWMConfig.u8Pin, LOW); // It is recomonded to make the Inhibit and PWM pin to low before updating the frequency.
                }
            }
        #endif
    }

    void PWM::fnPWMFrequencyUpdate(uint16_t u16Frequency)
    {
        u16PWMFrequency = u16Frequency;
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    PWMGPIOexternal.digitalWrite(structPWMConfig.u8Inhibit, HIGH); // To set PWM with new frequency, we give HIGH to the Inhibit pin. 
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                    digitalWrite(structPWMConfig.u8Pin, HIGH); // To set PWM with new frequency, we give HIGH to the PWM pin. 
                    MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM to update the frequency.
                    MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle. Now frequency is updated.                 
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_INTERNAL)
                {
                    u16PWMCounter = 0; // In the begining of the PWM after updating the frequency. The counter is given as 0. This will be used to measure Isense raw results.
                    digitalWrite(structPWMConfig.u8Inhibit, HIGH); // To set PWM with new frequency, we give HIGH to the Inhibit pin.            
                    digitalWrite(structPWMConfig.u8Pin, HIGH); // To set PWM with new frequency, we give HIGH to the PWM pin. 
                    if(u16PWMFrequency <= 500)
                    {
                        MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM.
                        MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle.    
                        MyTim->setOverflow((u16PWMFrequency*u8PWMNumberOfSamplesPerCycle), HERTZ_FORMAT); // sets the overflow in timer to measure the Isense raw result. this will be used to make an interupts.
                        MyTim->attachInterrupt(std::bind(fnPWMVersion2Isense, &structPWMConfig.u8Isense, &u16PWMIsenseADCValue[u16PWMCounter], &u16PWMCounter)); // sets the interupt in timer to measure the Isense raw result. This uses call back function and also passes three vaiables with their addresses and access them via pointers.
                        MyTim->resume(); // After the completion of call back function. Timer resumes (that is, the main code will continue.)
                    }
                    else
                    {
                        MyTim = new HardwareTimer(Instance); // Timer is initialized with pointer and new instance with respect to PWM pin of the PWM.
                        MyTim->setPWM(u8PWMChannel, structPWMConfig.u8Pin, u16PWMFrequency, u8PWMDutycycle); // Timer is set with coresponding channel of PWM pin and PWM pin and freduency and dutycyle.    
                    }
                }
            }
        #endif
    }

    void PWM::fnPWMSleepMode()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    PWMGPIOexternal.digitalWrite (structPWMConfig.u8Inhibit, LOW); // We set the Inhibit pin to LOW to stop the PWM completely.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_INTERNAL)
                {
                    digitalWrite(structPWMConfig.u8Inhibit, LOW); // We set the Inhibit pin to LOW to stop the PWM completely.
                }
            }
        #endif
    }

    void PWM::fnPWMActiveMode()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    PWMGPIOexternal.digitalWrite(structPWMConfig.u8Inhibit, HIGH); // We set the Inhibit pin to HIGH to start again the PWM.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_INTERNAL)
                {
                    digitalWrite(structPWMConfig.u8Inhibit, HIGH); // We set the Inhibit pin to HIGH to start again the PWM.
                }
            }
        #endif
    }

    uint8_t PWM::fnPWMInhibitPinStatus()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_EXTERNAL)
                {
                    u8PWMInhibitPinStatus = PWMGPIOexternal.digitalRead(structPWMConfig.u8Inhibit); //  We Read the Inhibit pin status of the PWM.
                    I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                }
            }
            return u8PWMInhibitPinStatus; // Returns the PWM inhibit pin status.
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
            {
                if(structPWMConfig.u8InhibitLocation == LOCATION_INTERNAL)
                {
                    u8PWMInhibitPinStatus = digitalRead(structPWMConfig.u8Inhibit); // We Read the Inhibit pin status of the PWM.
                }
            }
            return u8PWMInhibitPinStatus; // Returns the PWM inhibit pin status.
        #endif        
    }

    void PWM::fnPWMPinOff()
    {
        if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
        {
            digitalWrite(structPWMConfig.u8Pin, LOW); // We set the PWM pin to LOW to make the PWM completely OFF (that is 0).
        }
    }

    void PWM::fnPWMPinOn()
    {
        if(structPWMConfig.u8PWMPinLocation == LOCATION_INTERNAL)
        {
            digitalWrite(structPWMConfig.u8Pin, HIGH); // We set the PWM pin to HIGH to make the PWM completely ON (that is 100).
        }
    }

    #if defined(V3_Hatrix_HW_H)
        void PWM::fnPWMConversionRateUpdate(uint16_t u16ConversionRate)
        {
            switch(u16ConversionRate)
            {
                case 8 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_8_SPS); // Sets the conversion rate to 8 samples per second. This will have delay of 260 milli seconds. More Precise.
                    }
                    break;
                case 16 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_16_SPS); // Sets the conversion rate to 16 samples per second. This will have delay of 130 milli seconds.
                    }
                    break;
                case 32 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_32_SPS); // Sets the conversion rate to 32 samples per second. This will have delay of 64 milli seconds.
                    }
                    break;
                case 64 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_64_SPS); // Sets the conversion rate to 64 samples per second. This will have delay of 32 milli seconds.
                    }
                    break;
                case 128 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_128_SPS); // Sets the conversion rate to 128 samples per second. This will have delay of 16 milli seconds. This is Default.
                    }
                    break;
                case 250 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_250_SPS); // Sets the conversion rate to 250 samples per second. This will have delay of 8 milli seconds. Will have noise.
                    }
                    break;
                case 475 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_475_SPS); // Sets the conversion rate to 475 samples per second. This will have delay of 6 milli seconds. Will have noise.
                    }
                    break;
                case 860 : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                    }
                    break;
                default : 
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        if(u16ConversionRate < 8)
                        {
                            PWMADCExternal.setConvRate(ADS1115_8_SPS); // Sets the conversion rate to 8 samples per second. This will have delay of 260 milli seconds. More Precise.
                        }
                        else if(u16ConversionRate < 16)
                        {
                            PWMADCExternal.setConvRate(ADS1115_16_SPS); // Sets the conversion rate to 16 samples per second. This will have delay of 130 milli seconds.
                        }
                        else if(u16ConversionRate < 32)
                        {
                            PWMADCExternal.setConvRate(ADS1115_32_SPS); // Sets the conversion rate to 32 samples per second. This will have delay of 64 milli seconds.
                        }
                        else if(u16ConversionRate < 64)
                        {
                            PWMADCExternal.setConvRate(ADS1115_64_SPS); // Sets the conversion rate to 64 samples per second. This will have delay of 32 milli seconds.
                        }
                        else if(u16ConversionRate < 128)
                        {
                            PWMADCExternal.setConvRate(ADS1115_128_SPS); // Sets the conversion rate to 128 samples per second. This will have delay of 16 milli seconds. Will have noise.
                        }
                        else if(u16ConversionRate < 250)
                        {
                            PWMADCExternal.setConvRate(ADS1115_250_SPS); // Sets the conversion rate to 250 samples per second. This will have delay of 8 milli seconds. Will have noise.
                        }
                        else if(u16ConversionRate < 475)
                        {
                            PWMADCExternal.setConvRate(ADS1115_475_SPS); // Sets the conversion rate to 475 samples per second. This will have delay of 6 milli seconds. Will have noise.
                        }
                        else if(u16ConversionRate < 860)
                        {
                            PWMADCExternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                        }
                        else
                        {
                            PWMADCExternal.setConvRate(ADS1115_860_SPS); // Sets the conversion rate to 860 samples per second. This will have delay of 4 milli seconds. Will have noise.
                        }
                    }
                    break;
            }
            I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        }
    #endif

    float PWM::fnPWMLoadCurrent()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8IsenseLocation == LOCATION_EXTERNAL)
            {
                if(structPWMConfig.u8IsenseAddress == 0x49 || 0x4A || 0x4B)
                {
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setSingleChannel(structPWMConfig.u8Isense); // External ADC os Isense channel is set to read the corresponding ADC pin. After this we will have some delay because we have only one conversionsion register for 4 ADC channels in ADS1115. 
                        s16PWM_I_Load_Raw_Result = PWMADCExternal.getRawResult(); // After the delay we read raw results directly from the registers for external ADC of Isense and store it.
                        /**/ Serial.print(s16PWM_I_Load_Raw_Result);
                        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                        return fPWMLoadCurrent = (float)( structPWMConfig.fIsenseIdkILIS * (float)( (float)( (float)( s16PWM_I_Load_Raw_Result  * structPWMConfig.u16ScaleMaximumInternalVoltage ) / (float)( structPWMConfig.u16Resolution * structPWMConfig.fIsenseResistanceValue * 1000.00f ) ) - 0.0002f ) ); // Makes the necessary calculation and returns the fLoadCurrent value.
                    }
                }
            }
            return fPWMLoadCurrent;
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(u16PWMFrequency <= 500)
            {
                if(structPWMConfig.u8IsenseLocation == LOCATION_INTERNAL)
                {
                    for(uint16_t i = 0; i < (u8PWMNumberOfSamplesPerCycle * u8PWMNumberOfCyclesToSample); i++)
                    {
                        u32PWMIsenseADCRawResultSumValue += u16PWMIsenseADCValue[i]; // this will sum up all the raw results read in equal interval by intrupt.
                    }
                    return fPWMLoadCurrent = (float)( structPWMConfig.fIsenseIdkILIS * (float)( (float)( (float)( u32PWMIsenseADCRawResultSumValue  * structPWMConfig.u16ScaleMaximumInternalVoltage ) / (float)( structPWMConfig.u16Resolution * structPWMConfig.fIsenseResistanceValue * 1000.00f ) ) - 0.0002f ) ); // Makes the necessary calculation and returns the fLoadCurrent value.
                }  
                return fPWMLoadCurrent;    
            }
            else
            {
                if(structPWMConfig.u8IsenseLocation == LOCATION_INTERNAL)
                {
                    for(uint16_t i = 0; i < (u8PWMNumberOfSamplesPerCycle * u8PWMNumberOfCyclesToSample); i++)
                    {
                        /**/ delayMicroseconds(1000000*((double)1/(double)(u16PWMFrequency * u8PWMNumberOfSamplesPerCycle))); // Since the frequency is grreater than 500Hz, to get the smapled frequency with 12 readings atleast in a cycle has to be read. So, the delay is given in microseconds to get adc avlue of the analog value.
                        u16PWMIsenseADCValue[i] = adc_read_value(analogInputToPinName(structPWMConfig.u8Isense), 12); // Reads the raw result of ADC of the I_sense pin of the version2 borad. And store it in u32PWMIsenseADCValue[i].
                    }
                    for(uint16_t i = 0; i < (u8PWMNumberOfSamplesPerCycle * u8PWMNumberOfCyclesToSample); i++)
                    {
                        u32PWMIsenseADCRawResultSumValue += u16PWMIsenseADCValue[i]; // this will sum up all the raw results read in equal interval by intrupt.
                    }
                    return fPWMLoadCurrent = (float)( structPWMConfig.fIsenseIdkILIS * (float)( (float)( (float)( u32PWMIsenseADCRawResultSumValue  * structPWMConfig.u16ScaleMaximumInternalVoltage ) / (float)( structPWMConfig.u16Resolution * structPWMConfig.fIsenseResistanceValue * 1000.00f ) ) - 0.0002f ) ); // Makes the necessary calculation and returns the fLoadCurrent value.
                }  
                return fPWMLoadCurrent;    
            }
        #endif
    }

    float PWM::fnPWMLoadVoltage()
    {
        #if defined(V3_Hatrix_HW_H)
            if(structPWMConfig.u8VsenseLocation == LOCATION_EXTERNAL)
            {
                if(structPWMConfig.u8VsenseAddress == 0x49 || 0x4A || 0x4B)
                {
                    if(structPWMConfig.u8IsenseAddress == structPWMConfig.u8VsenseAddress)
                    {
                        PWMADCExternal.setSingleChannel(structPWMConfig.u8Vsense); // External ADC os Vsense channel is set to read the corresponding ADC pin. After this we will have some delay because we have only one conversionsion register for 4 ADC channels in ADS1115. 
                        s16PWM_V_Load_Raw_Result = PWMADCExternal.getRawResult(); // After the delay we read raw results directly from the registers for external ADC of Vsense and store it.
                        /**/ Serial.print(s16PWM_V_Load_Raw_Result);
                        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.    
                        return fPWMLoadVoltage = ( ( s16PWM_V_Load_Raw_Result  * structPWMConfig.u16ScaleMaximumInternalVoltage * structPWMConfig.fVsenseVoltageDividerValue ) / ( structPWMConfig.u16Resolution * 1000.00f ) ) ; // Makes the necessary calculation and returns the fLoadVoltage value.
                    }
                }
            }
        #endif
        #if defined(V2_Hatrix_HW_H)
            if(structPWMConfig.u8VsenseAddress == 0X40 || 0X42) 
            {
                fPWMLoadVoltage = PWMI2CExternal_V.getBusVoltage_V() + (PWMI2CExternal_V.getShuntVoltage_mV()/1000); // Shunt Volatge and Bus Voltage measured by INA226 and added to get Load Voltage.
                I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
                return fPWMLoadVoltage; // Returns the fLoadVoltage value.
            }
        #endif
        return fPWMLoadVoltage;
    } 

    float PWM::fnPWMLoadPower()
    {
        fPWMLoadPower = fPWMLoadVoltage * fPWMLoadCurrent; // fLoadVolatge and fLoadCurrent are multiplied to get the Load Power.
        return fPWMLoadPower; // Returns the fLoadPower value.
    }
#endif
/*********************************************************************************************************************************************/
/**********************************------PWM----END------*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------TCI---START-----*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)
    TCI::TCI(structTCI TCIstruct)
    {
        structTCIConfig = TCIstruct; // This will store the details of the TCI configuration in the respective struct.
        TCIexternalI2C = MCP9600(); // MCP9600 is initialized.
    }

    TCI::~TCI()
    {

    }

    void TCI::fnTCIBegin()
    {
        TCIexternalI2C.begin(structTCIConfig.u8Address); // MCP9600 is begin using this function with coressponding address.
        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
    }

    float TCI::fnTCIThermocoupleTemperature()
    {
        fTCIThermocoupleTemperature = TCIexternalI2C.getThermocoupleTemp(); // If the condition is true. Then reads the Hot junction temperature from MCO9600 via I2C1.
        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        return fTCIThermocoupleTemperature; // Returns the fThermocoupleTemperature value.
    }

    float TCI::fnTCIAmbientTemperature()
    {
        fTCIAmbientTemperature = TCIexternalI2C.getAmbientTemp(); // If the condition is true. Then reads the Cold junction temperature from MCO9600 via I2C1.
        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        return fTCIAmbientTemperature; // Returns the fAmbientTemperature value.
    }

    float TCI::fnTCITemperatureDelta()
    {
        fTCITemperatureDelta = TCIexternalI2C.getTempDelta(); // If the condition is true. Then reads the Delta temperature from MCO9600 via I2C1.
        I2C_1.flush(); // Wire(I2C1) is cleared before we proceed further.
        return fTCITemperatureDelta; // Returns the fTemperatureDelta value.
    }
#endif
/*********************************************************************************************************************************************/
/**********************************------TCI-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------CO2---START-----*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    CO2::CO2(uint8_t u8Co2Address, uint8_t u8Co2Type, TwoWire &wirePort)
    {
        I2C_2_Port = &wirePort; // This stores the I2C port. 
        u8Co2SensorAddress = u8Co2Address; // This store the Co2 sensor address.
        u8Co2SensorType = u8Co2Type; // This stores the type of the CO2 sensor we use.
        switch(u8Co2SensorType)
        {
            case SCD30_CO2_TYPE : 
                CO2externalI2C = SCD30(); // Initializes the SCD30 via I2C2
                break;
            case K30_CO2_TYPE : 
                u8Co2K3xScaleFactor = 1; // Sets the scale factor to "1".
                break;
            case K33_CO2_TYPE : 
                u8Co2K3xScaleFactor = 10; // Sets the scale factor to "10".
                break;
        }

    }

    CO2::~CO2()
    {

    }

    void CO2::fnCO2Begin()
    {
        switch(u8Co2SensorType)
        {
            case SCD30_CO2_TYPE : 
                CO2externalI2C.begin(I2C_2); // Begins the SC30 sensor type.
                I2C_2_Port->flush(); // I2C2 is cleared before we proceed further.
                break;
            case K30_CO2_TYPE : 
                // This function can be avoided for K30 co2 sensor types. Because they do not need any begin functionalities.    
                break;
            case K33_CO2_TYPE : 
                // This function can be avoided for K33 co2 sensor types. Because they do not need any begin functionalities.    
                break;
            default : 
                // In default we do nothing.    
                break;
        }
    }

    uint16_t CO2::fnCO2Carbondioxide()
    {
        switch(u8Co2SensorType)
        {
            case SCD30_CO2_TYPE : 
                if(CO2externalI2C.dataAvailable()) // Checks for new data whether it is available or not.
                {
                    u16CO2Carbondioxide = (uint16_t)(CO2externalI2C.getCO2()); // If the above condition is true, then gets the CO2 level in PPM.
                    I2C_2_Port->flush(); // I2C2 is cleared before we proceed further.
                }
                return u16CO2Carbondioxide; // Returns the Co2 level in PPM.
                break;
            case K30_CO2_TYPE : case K33_CO2_TYPE : 
                I2C_2_Port->beginTransmission(u8Co2SensorAddress); // Begins the I2C2 communication with Co2 sensor address.
    	        I2C_2_Port->write(0x22); // The Command to read the co2 register and sent via I2C2 port.
    	        I2C_2_Port->write(0x00); // Address of the Co2 register [LSB] and sent via I2C2 port.
    	        I2C_2_Port->write(0x08); // Address of the Co2 register [MSB] and sent via I2C2 port.
    	        I2C_2_Port->write(0x08 + 0x00 + 0x22); // Simple checksum is created as per data sheet and sent via I2C2 port.
    	        if(I2C_2_Port->endTransmission() == 0) // If the transmission is successfull. Then this condition will be true.
    	        {
    	        	/**/ delay(5); // As per datasheet K30 and K33 sensor types need typical delay of 20 milli second. Before it startes to respond.
    	        	if(I2C_2_Port->requestFrom(u8Co2SensorAddress, 4) == 4) // After the delay. I2C requests for four bytes of data from Co2 sensor. 
    	        	{
    	        		uint8_t counter = 0; // This will be used during reading the data from I2C port.
    	        		uint8_t u8ResponseData[4]; // Since we request 4 bytes of data, we create an byte array of 4.
    	        		while(I2C_2_Port->available()) // We check whether the data is available or not. 
    	        		{
    	        			u8ResponseData[counter] = I2C_2_Port->read(); // This will store all the data from the I2C port in this array.
    	        			counter++; // This will be incremented each time to store new data in new place of the array.
    	        		}
    	        		uint8_t u8CheckSum = u8ResponseData[0] + u8ResponseData[1] + u8ResponseData[2]; // we create a variable for check sum and we add the firs byte of response byte that is comand byte with the second and third byte of the response byte that is the data of the co2 level in ppm.
    	        		if(u8CheckSum == u8ResponseData[3]) //  The fourth byte of response byte is check sum which was sent from the sensor. This will show check for the condition, whether the check is correct or not. 
    	        		{
    	        			u16CO2Carbondioxide = (u8ResponseData[1] << 8 | u8ResponseData[2]) * u8Co2K3xScaleFactor; // If the above condition comes true. Then we will use the second and third byte of response data to get the Co2 leel in ppm. Second byte of the response data is Co2 LSB od the Co2 level in PPM, and the third byte of the response data is Co2 MSB od the Co2 level in PPM.
    	        		}
    	        	}
    	        }
                I2C_2_Port->flush(); // I2C2 is cleared before we proceed further.
                return u16CO2Carbondioxide; // Returns the Co2 level in PPM.
                break;
            default : 
                return u16CO2Carbondioxide; // Simply returns the Co2 level in PPM.
                break;
        }
    }
#endif
/*********************************************************************************************************************************************/
/**********************************------CO2-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------NEO---START-----*************************************************************************************/
/*********************************************************************************************************************************************/
#if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    NEOPIXEL::NEOPIXEL(structNEOPixelLED NEOPixelLEDstruct, uint8_t u8NumberofLED)
    {
        structNEOPixelLEDConfig = NEOPixelLEDstruct; // This will store the details of the NEOPIXEL configuration in the respective struct.
        u8NumberOfLEDInNeoPixel = u8NumberofLED; // This stores the Number of LEDs in NEOPIXEL.
        NeoLED = Adafruit_NeoPixel(u8NumberofLED, structNEOPixelLEDConfig.u8NeoPixelLEDPin); // Initializes the neo pixel LED with Number of LEDs and Neo Pixel LED pin.
    }

    NEOPIXEL::~NEOPIXEL()
    {

    }

    void NEOPIXEL::fnNeoLEDBegin()
    {
        pinMode(structNEOPixelLEDConfig.u8NeoPixelLEDPin, OUTPUT); // Here, we set the Neo Pixel LED pin mode to "OUTPUT".
        NeoLED.begin(); // This is used bein the all the functionalities of Neo pixel LED.
    }

    void NEOPIXEL::fnNeoLEDColorSet(uint8_t u8LEDNumber, uint32_t u32Color)
    {
        NeoLED.setPixelColor(u8LEDNumber, u32Color); // Sets the corresponding neo pixel LED with corresponding color.
        NeoLED.show(); // Implements the Neo Pixel LED with corresponding LED number and Color.
    }

    void NEOPIXEL::fnNeoLEDColorSetAllLED(uint32_t u32Color)
    {
        for(uint8_t i = 0; i < u8NumberOfLEDInNeoPixel; i++) // This iterated through all the LED in Neo Pixel.
        {
            NeoLED.setPixelColor(i, u32Color); // Sets the corresponding neo pixel LED with corresponding color.
            NeoLED.show(); // Implements the Neo Pixel LED with corresponding LED number and Color.
        }
    }

    uint32_t NEOPIXEL::fnColorLED(uint8_t u8RED, uint8_t u8Green, uint8_t u8Blue) // Protected Function of Neo Pixel Class.
    {
        return (((uint32_t)u8RED << 16) | ((uint32_t)u8Green <<  8) | ((uint32_t)u8Blue)); // Returns the desired color in RGB style.
    }
#endif
/*********************************************************************************************************************************************/
/**********************************------NEO-----END-----*************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/