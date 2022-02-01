/**
 * @file HATRIX.h
 * @author Mustaq Ahmed Althaf Hussain
 * @version 2.4
 * @date 12.01.2022 (Wednesday)
 * @pre Include the correct Hardware Config File in Hatrix_HW.h file.
 * @bug ("Mention any bug here if needed or found.")
 * @warning Any Changes to this file must be taken in to note with board version for version management and with respect to Smooth communication of via UART_1.
 * @copyright Copyright (c) 2022.
 * @brief It is header file with Hatrix Communication protocol.
 * @details This will contain the classess for Hatrix Communication protocol between the Boards and storing and working arround with the useful values.
 */

#ifndef Hatrix_H
#define Hatrix_H

#include "Hatrix_HW.h" // Adding this to utilize the functionalities of all the functional blocks of the Hardware.
                       // **Note: Do not forget to navigate to this file and include the correct header file for the respective Heardware**.
                       // /*******IMPORTANT**************IMPORTANT**************IMPORTANT***************IMPORTANT**********IMPORTANT*********/

#define CONTROLBYTE_MASTER_SENDING_DATA    0b00000000 // MSB of the Control byte. BIT_7. This refers master is sending a data frame.
#define CONTROLBYTE_MASTER_REQUESTING_DATA 0b10000000 // MSB of the Control byte. BIT_7. This refers master is requesting a data frame.
#define CONTROLBYTE_DO_NOT_RESET           0b00000000 // BIT_6. This refers not to reset the software.
#define CONTROLBYTE_RESET                  0b01000000 // BIT_6. This refers to reset the software.
#define CONTROLBYTE_NOT_BUS_SCAN           0b00000000 // BIT_5. This refers to not to respond to the Master with Board Address and Type.
#define CONTROLBYTE_BUS_SCAN               0b00100000 // BIT_5. This refers to respond to the Master with Board Address and Type.
#define CONTROLBYTE_DO_NOT_READ_ALL_DATA   0b00000000 // BIT_4. This refers not to read all the data in the board.
#define CONTROLBYTE_READ_ALL_DATA          0b00010000 // BIT_4. This refers to read all the data in the board.
#define CONTROLBYTE_RESERVED_BIT3          0b00001000 // BIT_3. Reserved.
#define CONTROLBYTE_RESERVED_BIT2          0b00000100 // BIT_2. Reserved.
#define CONTROLBYTE_RESERVED_BIT1          0b00000010 // BIT_1. Reserved.
#define CONTROLBYTE_RESERVED_BIT0          0b00000001 // LSB of the Control byte. BIT_0. Reserved.

#define NUMBER_OF_BOARDS 01 // If it is standalone board or If it is a Slave board then leave it as "1". If this is master board and have "n" number of slaves then "n+1".
                            // For Example: we can given there as "3". If, we have two slave board, with wich we are going to programme in the master board.

#define NUMBER_OF_PAGES_EACH_BOARD 07 // This means we can access upto page 6.
#define NUMBER_OF_VALUES_IN_EACH_PAGE 030 // This means we can access upto value 29.

#define CONTROLLER_CONFIGURATION_PAGE       00
#define SENSOR_HYSTERESIS_LIMIT_PAGE        01
#define SENSOR_LIMIT_PAGE                   02  
#define BOARD_CONTROL_PAGE                  03  
#define BOARD_CONTROL_CONFIGURATION_PAGE    04
#define IMPORTANT_DATA_PAGE                 05 
#define MISCELLANEOUS_DATA_PAGE             06

#define CURRENT_WORKING_BOARD               00
#define ZEROTH_VALUE_OF_EACH_PAGE           00
#define TYPE_OF_THE_BOARD                   01
#define ADDRESS_OF_THE_BOARD                02

extern uint16_t u16PagesConcept[NUMBER_OF_BOARDS][NUMBER_OF_PAGES_EACH_BOARD][NUMBER_OF_VALUES_IN_EACH_PAGE]; // The memory is allocated to store the values from different functional blocks.

class Hatrix       ; // This class is used if the it is Standalone Board.
class HatrixMaster ; // This class is used if the it is Master Board.
class HatrixSlave  ; // This class is used if the it is Slave Board.

/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------HATRIX---START-----**********************************************************************************/
/**
 * @brief Hatrix Class.
 * Manly for Standalone boards.
 * 
 */
class Hatrix
{
    public : 
        /**
         * @brief Construct a new Hatrix object.
         *  
         */
        Hatrix()                                                                                                         ; 
        /**
         * @brief Destroy the Hatrix object.
         * 
         */
        ~Hatrix()                                                                                                        ;

        /**
         * @brief This function is used Set the preorities. And begin all the necessary and basic functions. 
         * The preority is given in this order: I2C1, I2C2, SPI2, USART1, USART2, TIM1, TIM2, TIM3, and TIM4. 
         * I2C1, I2C2, SPI2, USART1, and USART2 has begin with begin function. 
         * PC13 (LED_BUILTIN) is given as OUTPUT using pinMode. 
         * Then, except Version 2 board; The watchdog is initialized.
         * This function can be accessed from HatrixMaster Class and HatrixSlave Class.
         * 
         */
        void fnHatrixBegin()                                                                                             ;

        #if defined(V3_Hatrix_HW_H) || defined(VCO2_Hatrix_HW_H)
            /**
             * @brief This function is used to reload the watchdog timer to prevent the software reset unnecessarily.
             * This function can be accessed from HatrixMaster Class and HatrixSlave Class.
             * 
             */
            void fnHatrixReloadWatchdogToReset()                                                                         ;
        #endif  

    protected : 
        /**
         * @brief This function is used to compute CRC for two bytes long data.
         * 
         * @param u16DataToSend The arary of two bytes data is given here.
         * @param u8LengthofData Length of the array is given here.
         * @return uint16_t u16CRC will be returned.
         */
        uint16_t fnHatrixComputeCRC16(uint16_t u16DataToSend[], uint8_t u8LengthofData)                                  ;
        /**
         * @brief This function is used to compute CRC for single byte data.
         * 
         * @param u8DataToSend The arary of single byte data is given here.
         * @param u8LengthofData Length of the array is given here.
         * @return uint8_t u8CRC will be returned.
         */
        uint8_t fnHatrixComputeCRC8(uint8_t u8DataToSend[], uint8_t u8LengthofData)                                      ;
        
};
/**********************************-----HATRIX-----END-----***********************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------MASTER---START-----**********************************************************************************/
/**
 * @brief HatrixMaster Class.
 * Manly for communication portocol via UART and RS485 as Master.
 * 
 */
class HatrixMaster : public Hatrix
{
    public : 
        /**
         * @brief Construct a new Hatrix Master object
         * 
         */
        HatrixMaster()                                                                                                                                                                              ; 
        /**                                     
         * @brief Destroy the Hatrix Master object                                     
         *                                      
         */                                     
        ~HatrixMaster()                                                                                                                                                                             ;
        
        /**
         * @brief This function used to begin the Uart Communication from Master. So, the UART_1 Enable pin will be kept HIGH.
         * Then there will be delay of 500ms. So, that the Master Board Make sure all the slave boards are initialized and 
         * waiting for the command frame from Master
         * 
         */
        void fnHatrixMasterUARTCommunicationBegin();
        /**
         * @brief This function is used to do Bus Scan in the Master. This will be useful to make sure the known available slaves are present the system.
         * 
         * @param u8NumberofSlavesAttached Number of Connected slaves to the Master has to be given here.
         * @param u8ListOfSlaveTypesInOrder Type of all the slaves in order has to given here in a array format.
         * @param u8ListOfSlaveAddressesInSameOrderAsSlaveTypesOrder Address of all the slaves in order has to given here in a array format. 
         *                                                           The order must be same as the u8ListOfSlaveTypesInOrder order.
         */
        void fnHatrixMasterBusScan(uint8_t u8NumberofSlavesAttached, std::array<uint8_t, 32> u8ListOfSlaveTypesInOrder, std::array<uint8_t, 32> u8ListOfSlaveAddressesInSameOrderAsSlaveTypesOrder) ;
        /**
         * @brief This function is used to Send Data to the slaves.
         * 
         * @param u8PageAccess The page has to be given here. So, all the values present in this page will be sent to the slave.
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "254". 
         *                    Note: u8SlaveID: Address of the slave also must be left with default "254".
         *                    The default will send data to each available slave one by one, with respect to slave page, type and address.
         *                    The "255" will send the data to all the slave at once irrespective of page, type, and address.
         *                    Note: u8SlaveID: Address of the slave also must be "255".
         *                    If you want to send to the only one, then the exact type of the slave has to be given here. 
         *                    Note: u8SlaveID: Address of the slave also must be exact address of the slave.
         * @param u8SlaveID Slave address has to be given here correctly. Else, it can be left to default "254". 
         *                  Note: u8SlaveType: Type of the slave also must be left with default "254".
         *                  The default will send data to each available slave one by one, with respect to slave page, type and address.
         *                  The "255" will send the data to all the slave at once irrespective of page, type, and address.
         *                  Note: u8SlaveType: Type of the slave also must be "255".
         *                  If you want to send to the only one, then the exact address of the slave has to be given here. 
         *                  Note: u8SlaveType: Type of the slave also must be exact type of the slave.
         */
        void fnHatrixMasterSendingData(uint8_t u8PageAccess, uint8_t u8SlaveType = 254, uint8_t u8SlaveID = 254)                                                                                    ;
        /**
         * @brief This function is used to Send Data to the slaves and then run one loop in the Slave Board.
         * 
         * @param u8PageAccess The page has to be given here. So, all the values present in this page will be sent to the slave.
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "254". 
         *                    Note: u8SlaveID: Address of the slave also must be left with default "254".
         *                    The default will send data to each available slave one by one, with respect to slave page, type and address.
         *                    The "255" will send the data to all the slave at once irrespective of page, type, and address.
         *                    Note: u8SlaveID: Address of the slave also must be "255".
         *                    If you want to send to the only one, then the exact type of the slave has to be given here. 
         *                    Note: u8SlaveID: Address of the slave also must be exact address of the slave.
         * @param u8SlaveID Slave address has to be given here correctly. Else, it can be left to default "254". 
         *                  Note: u8SlaveType: Type of the slave also must be left with default "254".
         *                  The default will send data to each available slave one by one, with respect to slave page, type and address.
         *                  The "255" will send the data to all the slave at once irrespective of page, type, and address.
         *                  Note: u8SlaveType: Type of the slave also must be "255".
         *                  If you want to send to the only one, then the exact address of the slave has to be given here. 
         *                  Note: u8SlaveType: Type of the slave also must be exact type of the slave.
         */
        void fnHatrixMasterSendingDataToReadAllData(uint8_t u8PageAccess, uint8_t u8SlaveType = 254, uint8_t u8SlaveID = 254)                                                                       ;
        /**                                     
         * @brief This function is used to send Reset Command to the slave.                                     
         *                                      
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "255".                                      
         *                    Note: u8SlaveID: Address of the slave also must be left with default "255".                                     
         *                    The "255" will send the data to all the slave at once irrespective of type, and address.                                     
         *                    If you want to send to the only one, then the exact type of the slave has to be given here.                                      
         *                    Note: u8SlaveID: Address of the slave also must be exact address of the slave.                                     
         *                    Note* : It is not recommended to use the "254" as slave type to send the reset command to all the slaves one by one.                                     
         *                    it is waste of time. Note: u8SlaveID: Address of the slave also must be "254".                                     
         * @param u8SlaveID Slave address has to be given here correctly. Else, it can be left to default "255".                                      
         *                  Note: u8SlaveType: Type of the slave also must be left with default "255".                                     
         *                  The "255" will send the data to all the slave at once irrespective of type, and address.                                     
         *                  If you want to send to the only one, then the exact address of the slave has to be given here.                                      
         *                  Note: u8SlaveType: Type of the slave also must be exact type of the slave.                                     
         *                  Note* : It is not recommended to use the "254" as slave address to send the reset command to all the slaves one by one.                                     
         *                  it is waste of time. Note: u8SlaveType: Type of the slave also must be "254".                                     
         */                                     
        void fnHatrixMasterReset(uint8_t u8SlaveType = 255, uint8_t u8SlaveID = 255)                                                                                                                ;
        /**
         * @brief This function is used to request data from the Slave.
         * 
         * @param u8PageAccess The page has to be given here mentiong which page is requested from slave to master board.
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "254". 
         *                    Note: u8SlaveID: Address of the slave also must be left with default "254".
         *                    The default will reuest data to each available slave one by one, with respect to slave page, type and address.
         *                    If you want to reuest to the only one, then the exact type of the slave has to be given here. 
         *                    Note: u8SlaveID: Address of the slave also must be exact address of the slave.
         *                    Note* : It is not recommended to use the broadcast mode that is "255" while requesting from Slave, we might end up in 
         *                    communication error or false communication or system error.
         * @param u8SlaveID Slave address has to be given here correctly. Else, it can be left to default "254". 
         *                  Note: u8SlaveType: Type of the slave also must be left with default "254".
         *                  The default will reuest data to each available slave one by one, with respect to slave page, type and address.
         *                  If you want to reuest to the only one, then the exact address of the slave has to be given here. 
         *                  Note: u8SlaveType: Type of the slave also must be exact type of the slave.
         *                  Note* : It is not recommended to use the broadcast mode that is "255" while requesting from Slave, we might end up in 
         *                  communication error or false communication or system error.
         */
        void fnHatrixMasterRequestingData(uint8_t u8PageAccess, uint8_t u8SlaveType = 254, uint8_t u8SlaveID = 254)                                                                                 ;
        /**
         * @brief This function is used to request data from the Slave after running one loop in the slave board.
         * So, this will have a delay of 500 miili second or maximum of 1000 milli second.
         * 
         * @param u8PageAccess The page has to be given here mentiong which page is requested from slave to master board.
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "254". 
         *                    Note: u8SlaveID: Address of the slave also must be left with default "254".
         *                    The default will reuest data to each available slave one by one, with respect to slave page, type and address.
         *                    The "255" will reuest the data to all the slave at once irrespective of page, type, and address.
         *                    Note: u8SlaveID: Address of the slave also must be "255".
         *                    Note* : It is not recommended to use the broadcast mode while requesting from Slave, we might end up in 
         *                    communication error or false communication or system error.
         *                    If you want to reuest to the only one, then the exact type of the slave has to be given here. 
         *                    Note: u8SlaveID: Address of the slave also must be exact address of the slave.
         * @param u8SlaveID Slave address has to be given here correctly. Else, it can be left to default "254". 
         *                  Note: u8SlaveType: Type of the slave also must be left with default "254".
         *                  The default will reuest data to each available slave one by one, with respect to slave page, type and address.
         *                  The "255" will reuest the data to all the slave at once irrespective of page, type, and address.
         *                  Note: u8SlaveType: Type of the slave also must be "255".
         *                  Note* : It is not recommended to use the broadcast mode while requesting from Slave, we might end up in 
         *                  communication error or false communication or system error.
         *                  If you want to reuest to the only one, then the exact address of the slave has to be given here. 
         *                  Note: u8SlaveType: Type of the slave also must be exact type of the slave.
         */
        void fnHatrixMasterRequestingDataAndReadAllData(uint8_t u8PageAccess, uint8_t u8SlaveType = 254, uint8_t u8SlaveID = 254)                                                                   ;
        /**
         * @brief This function is used to send read all data command to the Slave.
         * 
         * @param u8SlaveType Slave type has to be given here correctly. Else, it can be left to default "255". 
         *                    Note: u8SlaveAddress: Address of the slave also must be left with default "255".
         *                    The "255" will send the data to all the slave at once irrespective of type, and address.
         *                    If you want to send to the only one, then the exact type of the slave has to be given here. 
         *                    Note: u8SlaveAddress: Address of the slave also must be exact address of the slave.
         *                    Note* : It is not recommended to use the "254" as slave type to send the reset command to all the slaves one by one.
         *                    it is waste of time. Note: u8SlaveAddress: Address of the slave also must be "254".
         * @param u8SlaveAddress Slave address has to be given here correctly. Else, it can be left to default "255". 
         *                       Note: u8SlaveType: Type of the slave also must be left with default "255".
         *                       The "255" will send the data to all the slave at once irrespective of type, and address.
         *                       If you want to send to the only one, then the exact address of the slave has to be given here. 
         *                       Note: u8SlaveType: Type of the slave also must be exact type of the slave.
         *                       Note* : It is not recommended to use the "254" as slave address to send the reset command to all the slaves one by one.
         *                       it is waste of time. Note: u8SlaveType: Type of the slave also must be "254".
         */
        void fnHatrixMasterReadAllData(uint8_t u8SlaveType = 255, uint8_t u8SlaveID = 255)                                                                                                          ;
                                     
        uint8_t  u8ConnectedNumberOfSlaves                                                                                                                                                          ; // This will store the number of slave present in the Hatrix system in Master Board.
        uint8_t  u8SlaveAddress[32]                                                                                                                                                                 ; // This will store all the available slave types in order with respect to the u8ConnectedNumberOfSlaves.
        uint8_t  u8SlaveTypes[32]                                                                                                                                                                   ; // This will store all the available slave address in order with respect to the u8ConnectedNumberOfSlaves.
    
    protected : 

        // There is no protected functions or variables.
};
/**********************************-----MASTER-----END-----***********************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/



/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/**********************************------SLAVE---START-----***********************************************************************************/
/**
 * @brief HatrixSlave Class.
 * Manly for communication portocol via UART and RS485 as Slave.
 * 
 */
class HatrixSlave : public Hatrix
{
    public : 
        /**
         * @brief Construct a new Hatrix Slave object
         * 
         */
        HatrixSlave()                                                  ; 
        /**
         * @brief Destroy the Hatrix Slave object
         * 
         */
        ~HatrixSlave()                                                 ;
        
        /**
         * @brief This function used to begin the Uart Communication 
         * from Slave. So, the UART_1 Enable pin will be kept LOW.
         * 
         */
        void fnHatrixSlaveUARTCommunicationBegin()                     ;
        /**
         * @brief This is the only funtion used to be in the slave.
         * This function waits for the for the commad frame from 
         * the Master board. If this function gets the Command frame 
         * then it will accordingly by the Hatrix Protocol.
         * 
         */
        void fnHatrixSlaveWaitingForCommandFrame()                     ;
        
    
        uint8_t u8SlaveFullLoopRunFlag                                 ; // This is used as flag to indicate whether the slave needs to run one full loop or not.

        uint8_t u8SlaveResponseAfterFullReading                        ; // This is used as flag to indicate whether the slave needs to run one full loop and then responding for request from the Master or not.

        uint8_t u8SlaveUpdateFlag                                      ; // This is used as flag to indicate whether the slave needs to update the value in the slave board or not.
    
    protected : 

        /**
         * @brief This function used to respond for the BusScan from 
         * the Master according to Hatrix protocol.
         * 
         */
        void fnHatrixSlaveRespondingBusScan()                          ;
        /**
         * @brief This function is used to recieve the data frame from 
         * the Master according to Hatrix protocol.
         * 
         */
        void fnHatrixSlaveGettingData()                                ; 
        /**
         * @brief This function is used to recieve the data frame from 
         * the Master according to Hatrix protocol. 
         * And then sets the flag to run one loop in the slave board.
         * 
         */
        void fnHatrixSlaveGettingDataAndReadingAllData()               ; 
        /**
         * @brief This function is used to do softare reset in the 
         * slave board.
         * 
         */
        void fnHatrixSlaveReset()                                      ;
        /**
         * @brief This function is used to send the requested data by 
         * the Master according to Hatrix protocol.
         * 
         */
        void fnHatrixSlaveSendingData()                                ;
        /**
         * @brief This function is used to send the requested data by 
         * the Master according to Hatrix protocol after running 
         * one loop in the slave board.
         * 
         */
        void fnHatrixSlaveSendingDataAfterReadingAllData()             ;
        /**
         * @brief This function is used to set the flag to run one 
         * loop in the slave board.
         * 
         */
        void fnHatrixSlaveReadingAllData()                             ;

        uint8_t  u8Page                                                ; // This will store the page from the command frame recieved from Master.
        uint8_t  u8ControlByte                                         ; // This will store the control byte from the commad frame recieved from Master.
        
};
/**********************************-----SLAVE-----END-----************************************************************************************/
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/

#endif
