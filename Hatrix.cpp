/**
 * @file HATRIX.cpp
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include the correct Hardware Config File in Hatrix_HW.h file.
 * @bug ("Mention any bug here if needed or found.")
 * @warning Any Changes to this file must be taken in to note with board version for version management and with respect to Smooth communication of via UART_1.
 * @copyright Copyright (c) 2022.
 * @brief It is .cpp file with Hatrix Communication protocol.
 * @details This will contain the Hatrix Communication protocol between the Boards and storing in Pages and working arround with the useful values.
 */

#include "Hatrix.h"

uint16_t u16PagesConcept[NUMBER_OF_BOARDS][NUMBER_OF_PAGES_EACH_BOARD][NUMBER_OF_VALUES_IN_EACH_PAGE]; // This will be usefull to store the values and work arround with our code.

/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------HATRIX--START------**********************************************************************************/
/*********************************************************************************************************************************************/

Hatrix::Hatrix()
{
    
}

Hatrix::~Hatrix()
{

}

void Hatrix::fnHatrixBegin()
{
    // We are seting the priorities using HAL library.
    HAL_NVIC_SetPriority( I2C1_ER_IRQn      , 0 ,  0 ) ; // I2C1 is given highest and first priority.
    HAL_NVIC_SetPriority( I2C1_EV_IRQn      , 0 ,  1 ) ; // I2C1 is given highest and first priority.
    HAL_NVIC_SetPriority( I2C2_ER_IRQn      , 0 ,  2 ) ; // I2C2 is given second priority.
    HAL_NVIC_SetPriority( I2C2_EV_IRQn      , 0 ,  3 ) ; // I2C2 is given second priority.
    HAL_NVIC_SetPriority( SPI2_IRQn         , 0 ,  4 ) ; // SPI2 is given third priority.
    HAL_NVIC_SetPriority( USART1_IRQn       , 0 ,  5 ) ; // USART1 is given fourth priority.
    HAL_NVIC_SetPriority( USART2_IRQn       , 0 ,  6 ) ; // USART2 is given fifth priority.
    HAL_NVIC_SetPriority( TIM1_BRK_IRQn     , 0 ,  7 ) ; // TIM1 is given sixth priority.
    HAL_NVIC_SetPriority( TIM1_UP_IRQn      , 0 ,  8 ) ; // TIM1 is given sixth priority.
    HAL_NVIC_SetPriority( TIM1_TRG_COM_IRQn , 0 ,  9 ) ; // TIM1 is given sixth priority.
    HAL_NVIC_SetPriority( TIM1_CC_IRQn      , 0 , 10 ) ; // TIM1 is given sixth priority.
    HAL_NVIC_SetPriority( TIM2_IRQn         , 0 , 11 ) ; // TIM2 is given seventh priority.
    HAL_NVIC_SetPriority( TIM3_IRQn         , 0 , 12 ) ; // TIM3 is given eighth priority.
    HAL_NVIC_SetPriority( TIM4_IRQn         , 0 , 13 ) ; // TIM4 is given ninth priority.
    
    #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        I2C_1.begin(); // Initialized the I2C1 using begin function.
        I2C_2.begin(); // Initialized the I2C2 using begin function.
        #if defined(V3_Hatrix_HW_H)
            SPI_2.begin(); // Initialized the SPI2 using begin function.
        #endif
        UART_1.begin(115200); // Initialized the USART1 using begin function with the baud rate of 115200.
        pinMode(UART_1_Ennable_Pin.u8EnablePin, OUTPUT); // sets enable pin as output mode for USART1 coommunication in Hatrix board.
        #if defined(V3_Hatrix_HW_H) || defined(V2_Hatrix_HW_H)
            UART_2.begin(115200); // Initialized the USART2 using begin function with the baud rate of 115200.
            #if defined(V2_Hatrix_HW_H)
                pinMode(UART_2_Ennable_Pin.u8EnablePin, OUTPUT); // sets enable pin as output mode for USART1 coommunication in Version 2 board.
            #endif
        #endif
    #endif

    pinMode(LED_BUILTIN, OUTPUT); // Sets the default LED pin MODE to "OUTPUT" which is in PC13(LED_BUILTIN).

    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        if(IWatchdog.isReset(true))  // LED blinks for 5 time to indicate reset
        {
            for(uint8_t i = 0; i < 5; i++) 
            {
                digitalWrite(LED_BUILTIN, HIGH);
                /**/ delay(500);
                digitalWrite(LED_BUILTIN, LOW);
                /**/ delay(500);
            }
        }
        IWatchdog.begin(12000000); // The watchdog has given a 12 seconds of time. If this not reloaded in 12 seconds. Then the system will be reseting itself in software.
        if(!IWatchdog.isEnabled()) // LED blinks indefinitely to indicate the watch dog is not initialized.
        {
            while(1) 
            {
                digitalWrite(LED_BUILTIN, HIGH);
                /**/ delay(500);
                digitalWrite(LED_BUILTIN, LOW);
                /**/ delay(500);
            }
        }
    #endif
}   

#if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
    void Hatrix::fnHatrixReloadWatchdogToReset()
    {
        IWatchdog.reload(); // This will be used to reload the watchdog whenever this function is called.
    }
#endif

uint16_t Hatrix::fnHatrixComputeCRC16(uint16_t u16DataToSend[], uint8_t u8LengthofData) // https://ctlsys.com/support/how_to_compute_the_modbus_rtu_message_crc/ // Protected Function of Hatrix Class.
{
    uint16_t u16CRC = 0xFFFF; //From: http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html
    for(uint8_t x = 0; x < u8LengthofData; x++)
    {
        u16CRC ^= u16DataToSend[x]; // XOR-in the next input byte
        for(uint8_t i = 0; i < 16; i++)
        {
            if((u16CRC & 0x8000) != 0)
            {
                u16CRC = (uint16_t)((u16CRC << 1) ^ 0x8005); // x^15+x^2+1 = 0x8005 // http://www.sunshine2k.de/coding/javascript/crc/crc_js.html // CRC16_MODBUS.
            }              
            else
            {
                u16CRC <<= 1;
            }              
        }
    }
    return u16CRC; // Result and Input reflected.
}

uint8_t Hatrix::fnHatrixComputeCRC8(uint8_t u8DataToSend[], uint8_t u8LengthofData) // https://ctlsys.com/support/how_to_compute_the_modbus_rtu_message_crc/ // Protected Function of Hatrix Class.
{
    uint8_t u8CRC = 0xFF; //From: http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html
    for(uint8_t x = 0; x < u8LengthofData; x++)
    {
        u8CRC ^= u8DataToSend[x]; // XOR-in the next input byte
        for(uint8_t i = 0; i < 8; i++)
        {
            if((u8CRC & 0x80) != 0)
            {
                u8CRC = (uint8_t)((u8CRC << 1) ^ 0x31); // http://www.sunshine2k.de/coding/javascript/crc/crc_js.html 
            }              
            else
            {
                u8CRC <<= 1;
            }              
        }
    }
    return u8CRC; 
}

/*********************************************************************************************************************************************/
/**********************************-----HATRIX---END-------***********************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------MASTER--START------**********************************************************************************/
/*********************************************************************************************************************************************/

HatrixMaster::HatrixMaster()
{
    
}

HatrixMaster::~HatrixMaster()
{

}

void HatrixMaster::fnHatrixMasterUARTCommunicationBegin()
{
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // sets enable pin as HIGH for USART1 coommunication in Hatrix board as Master. Not listenting.
    /**/ delay(500); // This waits for all te slaves to be done with their initialization.
}

void HatrixMaster::fnHatrixMasterBusScan(uint8_t u8NumberofSlavesAttached, std::array<uint8_t, 32> u8ListOfSlaveTypesInOrder, std::array<uint8_t, 32> u8ListOfSlaveAddressesInSameOrderAsSlaveTypesOrder)
{
    uint8_t  u8BusResponse[3]; // Creating a variable to proceess the response from the slave for the Bus Scan.
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    bool     bDataAvailable; // Creating a variable to check, whether the data available in the buffer or not.
    u8ConnectedNumberOfSlaves = u8NumberofSlavesAttached; // The Master will store the number of avaialable slave to process with UART communication.
    for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
    {
        u8SlaveTypes[i] = u8ListOfSlaveTypesInOrder[i]; // The Master will store the slave types in order of the given array to process with UART communication.
        u8SlaveAddress[i] = u8ListOfSlaveAddressesInSameOrderAsSlaveTypesOrder[i]; // The Master will store the slave address in order of the given array to process with UART communication.
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.           
        u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
        u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
        u8CommandFrame[2] = 0; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here in Bus Scan we can give it as 0.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_REQUESTING_DATA | CONTROLBYTE_BUS_SCAN; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Then we go for Listening state in Master to get response from the Master.
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        /**/ delay(50); // This 50 milli second delay is given to give some time get response from the slave.
        if(UART_1.available()) // If the response is available, then the following steps will take palce. 
        {
            bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
            u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.
            for(uint8_t k = 0; k < u8LengthOfTheFrame; k++)
            {
                u8BusResponse[k] = UART_1.read(); // Now all the avaiable response is read from the buffer untill the length of the buffer.
            }
        }
        else // if the above "if" condition is flase, then the following steps will be done.
        {
            /**/ delay(50); // This is another 50 milli second delay is given to give some more time get response from the slave.
            if(UART_1.available()) // Now, again checks, If the response is available, then the following steps will take palce. 
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.
                for(uint8_t k = 0; k < u8LengthOfTheFrame; k++)
                {
                    u8BusResponse[k] = UART_1.read(); // Now all the avaiable response is read from the buffer untill the length of the buffer.
                }
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know the response data is not available from Slave.
                digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                fnHatrixMasterReset(u8SlaveTypes[i], u8SlaveAddress[i]); // Since, we did not get any response from the Slave, So, we send reset command to the Slave.
            }
        }
        uint8_t u8CRC = fnHatrixComputeCRC8(u8BusResponse, (u8LengthOfTheFrame-1)); // After Creating a varaiable for u8CRC. Calculating CRC from the u8BusResponse Variable.
        if(u8BusResponse[u8LengthOfTheFrame-1] == u8CRC && bDataAvailable == true) // Check for this condition. If this is true, then the following steps will be done.
        {
            if(u8SlaveTypes[i] == u8BusResponse[0] && u8SlaveAddress[i] == u8BusResponse[1]) // Then checks for this condition. If this is true, then the following steps will be done.
            {
                u16PagesConcept[i+1][ZEROTH_VALUE_OF_EACH_PAGE][TYPE_OF_THE_BOARD] = (uint16_t)u8BusResponse[0]; // This is slave type. This will be stored respectivly with slave.
                u16PagesConcept[i+1][ZEROTH_VALUE_OF_EACH_PAGE][ADDRESS_OF_THE_BOARD] = (uint16_t)u8BusResponse[1]; // This is slave address. This will be stored respectivly with slave.
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                while(u8SlaveTypes[i] != u8BusResponse[0] && u8SlaveAddress[i] != u8BusResponse[1]) // This steps will be repeated untill the condition gets false.
                {
                    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                    fnHatrixMasterReset(u8SlaveTypes[i], u8SlaveAddress[i]); // Since, we did not get correct response that is slave type and slave address from the Slave, So, we send reset command to the Slave.
                    fnHatrixMasterBusScan(u8NumberofSlavesAttached, u8ListOfSlaveTypesInOrder, u8ListOfSlaveAddressesInSameOrderAsSlaveTypesOrder); // Again we do the bus scan for the whole system from the master.
                }                         
            }
        }
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
    }            
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
}

void HatrixMaster::fnHatrixMasterSendingData(uint8_t u8PageAccess, uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    if(u8SlaveType == 254 && u8SlaveID == 254) // if it left with default parameters, then this condition will be true.
    {
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {   
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.             
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
            u8LengthOfTheFrame = u16PagesConcept[i+1][u8PageAccess][ZEROTH_VALUE_OF_EACH_PAGE] + 1; // This +1 is for two bytes crc. Note: All the data in the Data frame is two bytes. // This will store the 0th value from the u8PageAccess to know the length of the data to be send in data frame.
            for(uint8_t j = 0; j < (u8LengthOfTheFrame-1); j++)
            {
                u16DataFrame[j] = u16PagesConcept[i+1][u8PageAccess][j+1]; // untill the length of the data this will be proccessed.
            }
            u16DataFrame[u8LengthOfTheFrame-1] = fnHatrixComputeCRC16(u16DataFrame, (u8LengthOfTheFrame-1)); // Computes the CRC for two byte data, which contains the Check Sum.
            /**/ delay(5); // Giving some more time so that the slave will wait for data frame from the master.
            while(UART_1.availableForWrite() < 30); // Checks for available for write is atleast 30. If not, this will wait untill available for write is atleast 30.
            UART_1.write(u8LengthOfTheFrame * 2); // Then writes the length of the frame in system bus. // This is multiplied by two becase here each data is two bytes long.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                for(uint8_t k = 0; k < 2; k++)
                {
                    if(k == 0)
                    {
                        UART_1.write(u16DataFrame[j] >> 8); // Then writes the MSB of the Data in to the system bus of two byte data.
                    }
                    else
                    {
                        UART_1.write(u16DataFrame[j] & 0xFF); // Then writes the LSB of the Data in to the system bus of two byte data.
                    }
                }                
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        }            
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        uint8_t SlaveMemory; // Creating a variable to know the slave memory in the Master. Which will used later to process.
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {
            if(u8SlaveTypes[i] == u8SlaveType && u8SlaveAddress[i] == u8SlaveID)
            {
                SlaveMemory = i+1; // Slave memory is defined here.
            }
        }
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.                        
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        u8LengthOfTheFrame = u16PagesConcept[SlaveMemory][u8PageAccess][ZEROTH_VALUE_OF_EACH_PAGE] + 1; // This +1 is for two bytes crc. Note: All the data in the Data frame is two bytes. // This will store the 0th value from the u8PageAccess to know the length of the data to be send in data frame.
        for(uint8_t j = 0; j < (u8LengthOfTheFrame-1); j++)
        {
            u16DataFrame[j] = u16PagesConcept[SlaveMemory][u8PageAccess][j+1]; // untill the length of the data this will be proccessed.
        }
        u16DataFrame[u8LengthOfTheFrame-1] = fnHatrixComputeCRC16(u16DataFrame, (u8LengthOfTheFrame-1)); // Computes the CRC for two byte data, which contains the Check Sum.
        /**/ delay(5); // Giving some more time so that the slave will wait for data frame from the master.
        while(UART_1.availableForWrite() < 30); // Checks for available for write is atleast 30. If not, this will wait untill available for write is atleast 30.
        UART_1.write(u8LengthOfTheFrame * 2); // Then writes the length of the frame in system bus. // This is multiplied by two becase here each data is two bytes long.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            for(uint8_t k = 0; k < 2; k++)
            {
                if(k == 0)
                {
                    UART_1.write(u16DataFrame[j] >> 8); // Then writes the MSB of the Data in to the system bus of two byte data.
                }
                else
                {
                    UART_1.write(u16DataFrame[j] & 0xFF); // Then writes the LSB of the Data in to the system bus of two byte data.
                }
            }                
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.  
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
    }
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
    if(u8PageAccess == 3) // If the Page is 3, the this condition will be true because 3 rd page is used to update the values by comparing page 4.
    {
        /**/ delay(100); // Giving 100 milli seconds time, so, that the slaves will update all its values in its system.
    }
}

void HatrixMaster::fnHatrixMasterSendingDataToReadAllData(uint8_t u8PageAccess, uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    if(u8SlaveType == 254 && u8SlaveID == 254) // if it left with default parameters, then this condition will be true.
    {
        for(uint8_t i = 0; i <= u8ConnectedNumberOfSlaves; i++)
        {   
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.                       
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.  
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
            u8LengthOfTheFrame = u16PagesConcept[i+1][u8PageAccess][ZEROTH_VALUE_OF_EACH_PAGE] + 1; // This +1 is for two bytes crc. Note: All the data in the Data frame is two bytes. // This will store the 0th value from the u8PageAccess to know the length of the data to be send in data frame.
            for(uint8_t j = 0; j < (u8LengthOfTheFrame-1); j++)
            {
                u16DataFrame[j] = u16PagesConcept[i+1][u8PageAccess][j+1]; // untill the length of the data this will be proccessed.
            }
            u16DataFrame[u8LengthOfTheFrame-1] = fnHatrixComputeCRC16(u16DataFrame, (u8LengthOfTheFrame-1)); // Computes the CRC for two byte data, which contains the Check Sum.
            /**/ delay(5); // Giving some more time so that the slave will wait for data frame from the master.
            while(UART_1.availableForWrite() < 30); // Checks for available for write is atleast 30. If not, this will wait untill available for write is atleast 30.
            UART_1.write(u8LengthOfTheFrame * 2); // Then writes the length of the frame in system bus. // This is multiplied by two becase here each data is two bytes long.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                for(uint8_t k = 0; k < 2; k++)
                {
                    if(k == 0)
                    {
                        UART_1.write(u16DataFrame[j] >> 8); // Then writes the MSB of the Data in to the system bus of two byte data.
                    }
                    else
                    {
                        UART_1.write(u16DataFrame[j] & 0xFF); // Then writes the LSB of the Data in to the system bus of two byte data.
                    }
                }                
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.  
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        }            
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        uint8_t SlaveMemory; // Creating a variable to know the slave memory in the Master. Which will used later to process.
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {
            if(u8SlaveTypes[i] == u8SlaveType && u8SlaveAddress[i] == u8SlaveID)
            {
                SlaveMemory = i+1; // Slave memory is defined here.
            }
        }
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.             
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.  
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        u8LengthOfTheFrame = u16PagesConcept[SlaveMemory][u8PageAccess][ZEROTH_VALUE_OF_EACH_PAGE] + 1; // This +1 is for two bytes crc. Note: All the data in the Data frame is two bytes. // This will store the 0th value from the u8PageAccess to know the length of the data to be send in data frame.
        for(uint8_t j = 0; j < (u8LengthOfTheFrame-1); j++)
        {
            u16DataFrame[j] = u16PagesConcept[SlaveMemory][u8PageAccess][j+1]; // untill the length of the data this will be proccessed.
        }
        u16DataFrame[u8LengthOfTheFrame-1] = fnHatrixComputeCRC16(u16DataFrame, (u8LengthOfTheFrame-1)); // Computes the CRC for two byte data, which contains the Check Sum.
        /**/ delay(5); // Giving some more time so that the slave will wait for data frame from the master.
        while(UART_1.availableForWrite() < 30); // Checks for available for write is atleast 30. If not, this will wait untill available for write is atleast 30.
        UART_1.write(u8LengthOfTheFrame * 2); // Then writes the length of the frame in system bus. // This is multiplied by two becase here each data is two bytes long.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            for(uint8_t k = 0; k < 2; k++)
            {
                if(k == 0)
                {
                    UART_1.write(u16DataFrame[j] >> 8); // Then writes the MSB of the Data in to the system bus of two byte data.
                }
                else
                {
                    UART_1.write(u16DataFrame[j] & 0xFF); // Then writes the LSB of the Data in to the system bus of two byte data.
                }
            }                
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.        
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.  
    }  
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master. 
    if(u8PageAccess == 3) // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
    {
        /**/ delay(100); // Giving 100 milli seconds time, so, that the slaves will update all its values in its system.
    }
}

void HatrixMaster::fnHatrixMasterReset(uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        fnHatrixReloadWatchdogToReset(); // This will reset the Watchdog timer, so it will do software reset uneccessarily.
    #endif
    if(u8SlaveType == 254 && u8SlaveID == 254) // if the condition is true, then the following steps will take palce. 
    {
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.              
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = 0; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here in Reset, we can give it as 0.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_RESET; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.      
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.   
        }
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            fnHatrixReloadWatchdogToReset(); // This will reset the Watchdog timer, so it will do software reset uneccessarily.
        #endif  
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.              
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = 0; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here in Reset, we can give it as 0.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_RESET; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.      
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master. 
    }
    /**/ delay(1000); // Giving 1000 milli seconds time, so, that the slave will reset itself with respect software and again waits for the command frame from Master. 
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.   
    #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
        fnHatrixReloadWatchdogToReset(); // This will reset the Watchdog timer, so it will do software reset uneccessarily.
    #endif
}

void HatrixMaster::fnHatrixMasterRequestingData(uint8_t u8PageAccess, uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    bool     bDataAvailable; // Creating a variable to check, whether the data available in the buffer or not.
    if(u8SlaveType == 254 && u8SlaveID == 254) // if it left with default parameters, then this condition will be true.
    {
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {   
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.           
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_REQUESTING_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.      
            digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Then we go for Listening state in Master to get requested response from the Master.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master. 
            /**/ delay(50); // This 50 milli second delay is given to give some time get requested response from the slave.
            if(UART_1.available()) // If the response is available, then the following steps will take palce. 
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.
                for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                {
                    for(uint8_t m = 0; m < 2; m++)
                    {
                        if(m == 0)
                        {
                            u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                        }
                        else
                        {
                            u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                        }
                    }
                }                        
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                /**/ delay(50); // This is another 50 milli second delay is given to give some more time get response from the slave.
                if(UART_1.available()) // Now, again checks, If the response is available, then the following steps will take palce. 
                {
                    bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                    u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                    /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.
                    for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                    {
                        for(uint8_t m = 0; m < 2; m++)
                        {
                            if(m == 0)
                            {
                                u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                            }
                            else
                            {
                                u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                            }
                        }
                    }                        
                }
                else // if the above "if" condition is flase, then the following steps will be done.
                {
                    bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know the response data is not available from Slave.
                    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                    fnHatrixMasterReset(u8SlaveTypes[i], u8SlaveAddress[i]); // Since, we did not get any requested response from the Slave, So, we send reset command to the Slave.
                }
            }
            uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable.
            if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC && bDataAvailable == true) // Check for this condition. If this is true, then the following steps will be done.
            {
                for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++)
                {
                    u16PagesConcept[i+1][u8PageAccess][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective slave memory page.
                }
            }
            digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
        }            
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        uint8_t SlaveMemory; // Creating a variable to know the slave memory in the Master. Which will used later to process.
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {
            if(u8SlaveTypes[i] == u8SlaveType && u8SlaveAddress[i] == u8SlaveID)
            {
                SlaveMemory = i+1; // Slave memory is defined here.
            }
        }
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.              
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_REQUESTING_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.      
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Then we go for Listening state in Master to get requested response from the Master.
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master. 
        /**/ delay(50); // This 50 milli second delay is given to give some time get requested response from the slave.
        if(UART_1.available()) // If the response is available, then the following steps will take palce. 
        {
            bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
            u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
            for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
            {
                for(uint8_t m = 0; m < 2; m++)
                {
                    if(m == 0)
                    {
                        u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                    }
                    else
                    {
                        u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data. 
                    }
                }
            }                        
        }
        else // if the above "if" condition is flase, then the following steps will be done.
        {
            /**/ delay(50); // This is another 50 milli second delay is given to give some more time get response from the slave.
            if(UART_1.available()) // Now, again checks, If the response is available, then the following steps will take palce. 
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.
                for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                {
                    for(uint8_t m = 0; m < 2; m++)
                    {
                        if(m == 0)
                        {
                            u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                        }
                        else 
                        {
                            u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                        }
                    }
                }                        
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know the response data is not available from Slave.
                digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                fnHatrixMasterReset(u8SlaveType, u8SlaveID); // Since, we did not get any requested response from the Slave, So, we send reset command to the Slave.
            }
        }
        uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable.
        if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC && bDataAvailable == true) // Check for this condition. If this is true, then the following steps will be done.
        {
            for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++) 
            {
                u16PagesConcept[SlaveMemory][u8PageAccess][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective slave memory page.
            }
        }
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
    }   
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.   
}

void HatrixMaster::fnHatrixMasterRequestingDataAndReadAllData(uint8_t u8PageAccess, uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    bool     bDataAvailable; // Creating a variable to check, whether the data available in the buffer or not.
    if(u8SlaveType == 254 && u8SlaveID == 254) // if it left with default parameters, then this condition will be true.
    {
        for(uint8_t i = 0; i <= u8ConnectedNumberOfSlaves; i++)
        {   
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.          
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i].
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_REQUESTING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
            digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Then we go for Listening state in Master to get requested response from the Master. 
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
            /**/ /**/ delay(500); /**/ // This 500 milli second delay is given to give some time get requested response from the slave after running one loop in the slave board.
            if(UART_1.available()) // If the response is available, then the following steps will take palce. 
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
                for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                {
                    for(uint8_t m = 0; m < 2; m++)
                    {
                        if(m == 0)
                        {
                            u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                        }
                        else
                        {
                            u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data. 
                        }
                    }
                }                        
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                /**/ /**/ delay(500); /**/ // This is another 500 milli second delay is given to give some more time get response from the slave after running one loop in the slave board.
                if(UART_1.available()) // Now, again checks, If the response is available, then the following steps will take palce. 
                {
                    bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                    u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                    /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
                    for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                    {
                        for(uint8_t m = 0; m < 2; m++)
                        {
                            if(m == 0)
                            {
                                u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                            }
                            else
                            {
                                u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                            }
                        }
                    }                        
                }
                else // if the above "if" condition is flase, then the following steps will be done.
                {
                    bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know the response data is not available from Slave.
                    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                    fnHatrixMasterReset(u8SlaveTypes[i], u8SlaveAddress[i]); // Since, we did not get any requested response from the Slave, So, we send reset command to the Slave.
                }
            }
            uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable.
            if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC && bDataAvailable == true) // Check for this condition. If this is true, then the following steps will be done.
            {
                for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++)
                {
                    u16PagesConcept[i+1][u8PageAccess][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective slave memory page.
                }
            }
            digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
        }            
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        uint8_t SlaveMemory; // Creating a variable to know the slave memory in the Master. Which will used later to process.
        for(uint8_t i = 0; i < u8ConnectedNumberOfSlaves; i++)
        {
            if(u8SlaveTypes[i] == u8SlaveType && u8SlaveAddress[i] == u8SlaveID)
            {
                SlaveMemory = i+1; // Slave memory is defined here.
            }
        }
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.           
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = u8PageAccess; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here it is u8PageAccess.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_REQUESTING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Then we go for Listening state in Master to get requested response from the Master.
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        /**/ /**/ delay(500); /**/ // This 500 milli second delay is given to give some time get requested response from the slave after running one loop in the slave board.
        if(UART_1.available()) // If the response is available, then the following steps will take palce. 
        {
            bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
            u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
            for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
            {
                for(uint8_t m = 0; m < 2; m++)
                {
                    if(m == 0)
                    {
                        u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                    }
                    else
                    {
                        u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                    }
                }
            }                        
        }
        else // if the above "if" condition is flase, then the following steps will be done.
        {
            /**/ /**/ delay(500); /**/ // This is another 500 milli second delay is given to give some more time get response from the slave after running one loop in the slave board.
            if(UART_1.available()) // Now, again checks, If the response is available, then the following steps will take palce. 
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know the response data is available from Slave.
                u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
                for(uint8_t k = 0; k < (u8LengthOfTheFrame/2); k++)
                {
                    for(uint8_t m = 0; m < 2; m++)
                    {
                        if(m == 0)
                        {
                            u16DataFrame[k] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
                        }
                        else
                        {
                            u16DataFrame[k] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
                        }
                    }
                }                        
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know the response data is not available from Slave.
                digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
                fnHatrixMasterReset(u8SlaveType, u8SlaveID); // Since, we did not get any requested response from the Slave, So, we send reset command to the Slave.
            }
        }
        uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable. 
        if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC && bDataAvailable == true) // Check for this condition. If this is true, then the following steps will be done.
        {
            for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++)
            {
                u16PagesConcept[SlaveMemory][u8PageAccess][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective slave memory page. 
            }
        }
        digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
    }  
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.   
}

void HatrixMaster::fnHatrixMasterReadAllData(uint8_t u8SlaveType, uint8_t u8SlaveID)
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
    if(u8SlaveType == 254 && u8SlaveID == 254)
    {
        for(uint8_t i = 0; i <= u8ConnectedNumberOfSlaves; i++)
        {   
            u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.            
            u8CommandFrame[0] = u8SlaveTypes[i]; // First byte of Command frame is given with type of slave which we stored in u8SlaveTypes[i]. 
            u8CommandFrame[1] = u8SlaveAddress[i]; // Second byte of Command frame is given with address of slave which we stored in u8SlaveAddress[i].
            u8CommandFrame[2] = 0; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here in Read all Data Command, we can give it as 0.
            u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
            u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
            while(UART_1.availableForWrite() < 7); // Checks for available for write is atleast 7. If not, this will wait untill available for write is atleast 7.
            UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
            for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
            {
                UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
            }
            UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
            /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
        }            
    }
    else // if the above "if" condition is flase, then the following steps will be done.
    {
        u8LengthOfTheFrame = 5; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.          
        u8CommandFrame[0] = u8SlaveType; // First byte of Command frame is given with type of slave which we stored in u8SlaveType.
        u8CommandFrame[1] = u8SlaveID; // Second byte of Command frame is given with address of slave which we stored in u8SlaveID.
        u8CommandFrame[2] = 0; // Third byte of Command frame is given with the Page in which and what we are going to access in the slave. Here in Read all Data Command, we can give it as 0.
        u8CommandFrame[3] = CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_READ_ALL_DATA; // Fourth byte of Command frame is control byte of the command frame, which contains the information to be done in Slave Board.
        u8CommandFrame[4] = fnHatrixComputeCRC8(u8CommandFrame, 4); // Fifth byte of Command frame is CRC byte of the command frame, which contains the Check Sum value.
        while(UART_1.availableForWrite() < 7);
        UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
        for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
        {
            UART_1.write(u8CommandFrame[j]); // Then writes all the command frame in to the system bus.
        }
        UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.
        /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
    }   
    /**/ delay(5); // Giving some spare time, so, That the buffer will have some rest or gap. This will be easier for slave to follow the master.
}

/*********************************************************************************************************************************************/
/**********************************-----MASTER---END-------***********************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/





/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------SLAVE--START------***********************************************************************************/
/*********************************************************************************************************************************************/

HatrixSlave::HatrixSlave()
{

}

HatrixSlave::~HatrixSlave()
{

}

void HatrixSlave::fnHatrixSlaveUARTCommunicationBegin()
{
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // sets enable pin as LOW for USART1 coommunication in Hatrix board as Slave. Always listenting.
}

void HatrixSlave::fnHatrixSlaveWaitingForCommandFrame()
{
    switch(u8SlaveResponseAfterFullReading) // Checks for the flag that whether slave needs to repond after one loop full reading or not.
    {
        case 1 : // if the above mentioned "switch" condition flag is set then this case will be proccessed.
            fnHatrixSlaveSendingData(); // Sends the requested data to the Master.
            u8SlaveResponseAfterFullReading = 0; // The flag is cleard here. 
            break;
        case 0 : // if the above mentioned "switch" condition flag is not set then this case will be proccessed.
            uint8_t  u8UARTSerialChar; // Creating variable to read the unwanted avaialble data in the system bus or buffer.
            uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
            uint8_t  u8CommandFrame[4 + 1]; // This +1 is for one byte CRC. // Creating a variable for Command frame that is needed to send to the slaves.
            bool     bDataAvailable; // Creating a variable to check, whether the data available in the buffer or not.
            while(UART_1.available() != 0) // if there is already some data available in the buffer, then this condition will be true. So, untill the buffer gets to zero this will take place.
            {
                u8UARTSerialChar = UART_1.read(); // Clearing the buffer by reading the unwanted data availalble in the buffer.
            }
            while(UART_1.available() == 0) // if data available in the buffer is "0", then this condition will be true. So, untill the buffer gets any data this will take palce.
            {
                
            }
            u8UARTSerialChar = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8UARTSerialChar.   
            if(u8UARTSerialChar == 5) // Checks for this condition, if it is true then the following will take place. In hatrix protocol the length of the frame of the Command frame from Master will be always "5".
            {
                bDataAvailable = true; // Making the bDataAvailable to true. So, by this we know that we got the commad frame from the Master.
                u8LengthOfTheFrame = u8UARTSerialChar; // In Hatrix Protocol all frames start with length of the frame to be transmitted. u8UARTSerialChar is given to u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer.  
                for(uint8_t i = 0; i < u8LengthOfTheFrame; i++)
                {
                    u8CommandFrame[i] = UART_1.read(); // Then reads all the command frame from the system bus. 
                }
            }
            else // if the above "if" condition is flase, then the following steps will be done.
            {
                bDataAvailable = false; // Making the bDataAvailable to false. So, by this we know that we did not got the commad frame from the Master.
                u8LengthOfTheFrame = u8UARTSerialChar; // In Hatrix Protocol all frames start with length of the frame to be transmitted. u8UARTSerialChar is given to u8LengthOfTheFrame.
                /**/ delay(5); // Giving some spare time, so, That the buffer will have all the unneccessary data wich is needed to be read and cleared from buffer.  
                for(uint8_t i = 0; i < u8LengthOfTheFrame; i++)
                {
                    u8UARTSerialChar = UART_1.read(); // Then reads all the command frame from the system bus. 
                }
            }
            if(bDataAvailable == true) // Checks for this condition, if it is true then the following will take place.
            {
                uint8_t u8CRC = fnHatrixComputeCRC8(u8CommandFrame, (u8LengthOfTheFrame-1)); // After Creating a varaiable for u8CRC. Calculating CRC from the u8CommandFrame Variable.
                if(u8CommandFrame[u8LengthOfTheFrame-1] == u8CRC) // Checks for this condition, if it is true then the following will take place.
                {
                    if(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][TYPE_OF_THE_BOARD] == u8CommandFrame[0] || u8CommandFrame[0] == 255) // Checks for this condition, if it is true then the following will take place.
                    {
                        if(u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD] == u8CommandFrame[1] || u8CommandFrame[1] == 255) // Checks for this condition, if it is true then the following will take place.
                        {
                            u8Page = u8CommandFrame[2]; // Stores the Page to accessed in the slave from the Commad Frame. 
                            u8ControlByte = u8CommandFrame[3]; // Stores the Control Byte from the Commad Frame. 
                            switch(u8ControlByte) // Checks for the u8ControlByte.                                           
                            {                                                                
                                case (CONTROLBYTE_MASTER_SENDING_DATA) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.                            
                                    fnHatrixSlaveGettingData(); // Recivieing the data from the Master                             
                                    break;                                                   
                                case (CONTROLBYTE_MASTER_REQUESTING_DATA) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.                
                                    fnHatrixSlaveSendingData(); // Sends the requested data to the Master.                         
                                    break;                                                   
                                case (CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_RESET) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.    
                                    fnHatrixSlaveReset(); // Reseting the software in the Slave Board.                                   
                                    break;                                                   
                                case (CONTROLBYTE_MASTER_REQUESTING_DATA | CONTROLBYTE_BUS_SCAN) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.  
                                    fnHatrixSlaveRespondingBusScan(); // Responding to the Bus Scan to the Master.
                                    break;
                                case (CONTROLBYTE_MASTER_SENDING_DATA | CONTROLBYTE_READ_ALL_DATA) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.  
                                    switch(u8Page) // Checks for the u8Page.   
                                    {
                                        case 0 : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.  
                                            fnHatrixSlaveReadingAllData(); // Read and run one full loop in the slave Board.
                                            break;
                                        case 1 : case 2 : case 3 : case 4 : case 5 : case 6 : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.  
                                            fnHatrixSlaveGettingDataAndReadingAllData(); // Recivieing the data from the Master after that reading and running one full loop in the slave board. 
                                            break;
                                        default : // if the above mentioned "switch" condition is false all the cases then the this default case will be proccessed.

                                            break;
                                    }
                                    break;
                                case (CONTROLBYTE_MASTER_REQUESTING_DATA | CONTROLBYTE_READ_ALL_DATA) : // if the above mentioned "switch" condition is true for this case then the this case will be proccessed.  
                                    fnHatrixSlaveSendingDataAfterReadingAllData(); // Reading and running one full loop in the slave board and then sending the requested data to the Master. 
                                    break;
                                default : // if the above mentioned "switch" condition is false all the cases then the this default case will be proccessed.  

                                    break;
                            }
                        }
                    }
                }
            }
            break;
        default : // if the above mentioned "switch" condition flag is not 0 and 1 then this default case will be proccessed.
            u8SlaveResponseAfterFullReading = 0; // The flag is cleard here. 
            break;
    }
}

void HatrixSlave::fnHatrixSlaveRespondingBusScan() // Protected Function of Hatrix Slave Class.
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint8_t  u8BusResponse[3]; // Creating a variable to proceess the response to the Master for the Bus Scan.
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
    u8LengthOfTheFrame = 3; // In Hatrix Protocol all frames start with length of the frame to be transmitted. excluding the Length of the frame in the frame.
    u8BusResponse[0] = (uint8_t)u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][TYPE_OF_THE_BOARD]; // The first byte of the BusResponse will be the type of the Slave Board.
    u8BusResponse[1] = (uint8_t)u16PagesConcept[CURRENT_WORKING_BOARD][CONTROLLER_CONFIGURATION_PAGE][ADDRESS_OF_THE_BOARD]; // The second byte of the BusResponse will be the address of the Slave Board.
    u8BusResponse[2] = fnHatrixComputeCRC8(u8BusResponse, (u8LengthOfTheFrame-1)); // The third byte of the BusResponse will be the u8CRC for the Bus Response.
    UART_1.write(u8LengthOfTheFrame); // Then writes the length of the frame in system bus.
    UART_1.write(u8BusResponse[0]); // Then writes first byte of the Bus Response in to the system bus.
    UART_1.write(u8BusResponse[1]); // Then writes second byte of the Bus Response in to the system bus.
    UART_1.write(u8BusResponse[2]); // Then writes third byte of the Bus Response in to the system bus.
    UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.  
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Again we go back to Listening state, by making the UART_1 Enable pin to LOW.
}

void HatrixSlave::fnHatrixSlaveGettingData() // Protected Function of Hatrix Slave Class.
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    while(UART_1.available() == 0) // Wait for the data frame from the master.
    {

    }
    u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
    /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer. 
    for(uint8_t i = 0; i < (u8LengthOfTheFrame/2); i++)
    {
        for(uint8_t j = 0; j < 2; j++)
        {
            if(j == 0)
            {
                u16DataFrame[i] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
            }
            else
            {
                u16DataFrame[i] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
            }
        }
    }
    uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable.
    if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC) // Check for this condition. If this is true, then the following steps will be done.
    {
        for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++)
        {
            u16PagesConcept[CURRENT_WORKING_BOARD][u8Page][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective memory page of the slave board.
        }
        if(u8Page == 3) // Check for this condition. If this is true, then the following steps will be done.
        {
            u8SlaveUpdateFlag = 1; // This flag is set to update the slave board.
        }
    }
}

void HatrixSlave::fnHatrixSlaveGettingDataAndReadingAllData() // Protected Function of Hatrix Slave Class.
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    while(UART_1.available() == 0) // Wait for the data frame from the master.
    {

    }
    u8LengthOfTheFrame = UART_1.read(); // In our Hatrix Protocol, all the frames will start with length of the frame. So, we read the first availble data in the buffer and store it in u8LengthOfTheFrame.
    /**/ delay(5); // Giving some spare time, so, That the buffer will have all the neccessary data wich is needed to be read from buffer. 
    for(uint8_t i = 0; i < (u8LengthOfTheFrame/2); i++)
    {
        for(uint8_t j = 0; j < 2; j++)
        {
            if(j == 0)
            {
                u16DataFrame[j] = UART_1.read() << 8; // Then reads the MSB of the Data from the system bus of two byte data.
            }
            else
            {
                u16DataFrame[j] |= UART_1.read(); // Then reads the LSB of the Data from the system bus of two byte data.
            }
        }
    }
    uint16_t u16CRC = fnHatrixComputeCRC16(u16DataFrame, ((u8LengthOfTheFrame/2)-1)); // After Creating a varaiable for u16CRC. Calculating CRC from the u16DataFrame Variable.
    if(u16DataFrame[((u8LengthOfTheFrame/2)-1)] == u16CRC) // Check for this condition. If this is true, then the following steps will be done.
    {
        for(uint8_t k = 1; k < (u8LengthOfTheFrame/2); k++)
        {
            u16PagesConcept[CURRENT_WORKING_BOARD][u8Page][k] = u16DataFrame[k-1]; // Then values from u16DataFrame varaible is stored in the respective memory page of the slave board.
        }
        if(u8Page == 3) // Check for this condition. If this is true, then the following steps will be done.
        {
            u8SlaveUpdateFlag = 1; // This flag is set to update the slave board.
        }
        u8SlaveFullLoopRunFlag = 1; // This flag is set to run one full loop in the slave board.
    }
}

void HatrixSlave::fnHatrixSlaveReset() // This should not be done any changes here. This is exacltly dame as main.cpp of the stm32core official core. So, this works better in the software reset. // NVIC_SystemReset(); // the below steps work better then the NVIC_SystemReset. // Protected Function of Hatrix Slave Class.
{
    // Required by FreeRTOS, see http://www.freertos.org/RTOS-Cortex-M3-M4.html
    #ifdef NVIC_PRIORITYGROUP_4
        HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    #endif
    #if (__CORTEX_M == 0x07U)
        // Defined in CMSIS core_cm7.h
        #ifndef I_CACHE_DISABLED
            SCB_EnableICache();
        #endif
        #ifndef D_CACHE_DISABLED
            SCB_EnableDCache();
        #endif
    #endif

    init();

    initVariant();

    setup();

    for (;;) 
    {
        #if defined(CORE_CALLBACK)
            CoreCallback();
        #endif
        loop();
        serialEventRun();
    }
}

void HatrixSlave::fnHatrixSlaveSendingData() // Protected Function of Hatrix Slave Class.
{
    uint8_t  u8LengthOfTheFrame; // Creating a variable to indicate the length of the frame.
    uint16_t u16DataFrame[30 + 1]; // This +1 is for two byte CRC. // Creating a variable for Data frame that is needed to send to be send to the slaves.
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, HIGH); // So, now we Come out from Listening state by making the UART_1 Enable pin to High.
    u8LengthOfTheFrame = u16PagesConcept[CURRENT_WORKING_BOARD][u8Page][ZEROTH_VALUE_OF_EACH_PAGE] + 1; // This +1 is for two bytes crc. Note: All the data in the Data frame is two bytes. // This will store the 0th value from the u8PageAccess to know the length of the data to be send in data frame.
    for(uint8_t j = 0; j < (u8LengthOfTheFrame-1); j++)
    {
        u16DataFrame[j] = u16PagesConcept[CURRENT_WORKING_BOARD][u8Page][j+1]; // untill the length of the data this will be proccessed.
    }
    u16DataFrame[u8LengthOfTheFrame-1] = fnHatrixComputeCRC16(u16DataFrame, (u8LengthOfTheFrame-1)); // Computes the CRC for two byte data, which contains the Check Sum.
    while(UART_1.availableForWrite() < 30); // Checks for available for write is atleast 30. If not, this will wait untill available for write is atleast 30.
    UART_1.write(u8LengthOfTheFrame * 2); // Then writes the length of the frame in system bus. // This is multiplied by two becase here each data is two bytes long.
    for(uint8_t j = 0; j < u8LengthOfTheFrame; j++)
    {
        for(uint8_t k = 0; k < 2; k++)
        {
            if(k == 0)
            {
                UART_1.write(u16DataFrame[j] >> 8); // Then writes the MSB of the Data in to the system bus of two byte data.
            }
            else
            {
                UART_1.write(u16DataFrame[j] & 0xFF); // Then writes the LSB of the Data in to the system bus of two byte data.
            }
        }                
    }
    UART_1.flush(); // Then we flush the UART_1. That is wait untill the tranmission is complete.    
    digitalWrite(UART_1_Ennable_Pin.u8EnablePin, LOW); // Again we go back to Listening state, by making the UART_1 Enable pin to LOW. 
}

void HatrixSlave::fnHatrixSlaveSendingDataAfterReadingAllData() // Protected Function of Hatrix Slave Class.
{
    u8SlaveFullLoopRunFlag = 1; // This flag is set to run one full loop in the slave board.
    u8SlaveResponseAfterFullReading = 1; // This flag is set to run one full loop in the slave board and the respond to the Master as requested.
}

void HatrixSlave::fnHatrixSlaveReadingAllData() // Protected Function of Hatrix Slave Class.
{
    u8SlaveFullLoopRunFlag = 1; // This flag is set to run one full loop in the slave board.
}

/*********************************************************************************************************************************************/
/**********************************-----SLAVE---END-------************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/