/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_program.c
 *       Module:  General Purpose Input Output 
 *
 *  Description:  This .c file contains functions implemntations  
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIBRARIES/Bit_Math.h"
#include "../../LIBRARIES/Std_Types.h"

#include "GPIO_Interface.h"
#include "GPIO_Configure.h"
#include "../../MCAL/MCU_hw.h"
#include "GPIO_Private.h"




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void GPIO_WritePort (GPIO_PortType PortId, GPIO_PortLevelType Level)
        
* \Description     : Sets Output Port value as desired                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId		Indicates which port to write over
*					 Level		Indicated the desired value to be written
* \Parameters (out): None                                                      
* \Return value:   : None
*                                    
*******************************************************************************/
void GPIO_WritePort (GPIO_PortType PortId, GPIO_PortLevelType Level)
{
	GPIODIR(PortId) = (GPIO_PortLevelType)PORT_OUTPUT; 
	GPIODATA(PortId).R = Level;
}


/******************************************************************************
* \Syntax          : void GPIO_WriteChannel (GPIO_ChannelType ChannelId, GPIO_LevelType Level)        
* \Description     : Sets a specific Output Pin value as desired                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   Indicates which pin to write over                    
*					 Level		 Indicated the desired value to be written
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
void GPIO_WriteChannel (GPIO_ChannelType ChannelId, GPIO_LevelType Level)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
	
	SET_BIT(GPIODIR(PORTi), ChannelId);
	GPIODATA(PORTi).R |= Level << PINi;
}


/******************************************************************************
* \Syntax          : GPIO_PortLevelType GPIO_ReadPort (GPIO_PortType PortId)
* \Description     : Receives Input from a specific port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId		Indicates the desired port 
* \Parameters (out): None                                                      
* \Return value:   : GPIO_PortLevelType  variable
*                                                                  
*******************************************************************************/
GPIO_PortLevelType GPIO_ReadPort (GPIO_PortType PortId)
{
	return GPIODATA(PortId).R;
}


/******************************************************************************
* \Syntax          : GPIO_LevelType GPIO_ReadChannel (GPIO_ChannelType ChannelId)      
* \Description     : Receives Input from a specific pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   Indicates the desired pin 
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                          
*******************************************************************************/
GPIO_LevelType GPIO_ReadChannel (GPIO_ChannelType ChannelId)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
	
	return ( GET_BIT(GPIODATA(PORTi).R ,PINi) );
}


/******************************************************************************
* \Syntax          : GPIO_LevelType GPIO_FlipChannel (GPIO_ChannelType ChannelId)
* \Description     : Toggles pin value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   Indicates the desired channel 
* \Parameters (out): None                                                      
* \Return value:   : None
*                        
*******************************************************************************/
GPIO_LevelType GPIO_FlipChannel (GPIO_ChannelType ChannelId)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
		
	return TOG_BIT(GPIODATA(PORTi).R ,PINi) ;
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO_Program.c
 *********************************************************************************************************************/








