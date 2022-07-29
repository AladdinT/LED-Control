/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Program.c
 *        \brief  This source file initializes each GPIO pin in microcontroller
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../LIBRARIES/Bit_Math.h"
#include "../../LIBRARIES/Std_Types.h"

#include "PORT_Interface.h"
#include "GPIO_Interface.h"
#include "PORT_Configure.h"
#include "PORT_Private.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void PORT_Init (void)     
* \Description     : Initializes each port and each pin with its configured function                                   
*                                                                             
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : NONE
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                          
*******************************************************************************/
void PORT_Init (void)
{
	GPIO_PortType PORTi = 0;
	for( PORTi=PORTA ; PORTi<=PORTF ; PORTi++)
	{
		if( PortConfig[PORTi] == ENABLE)
		{	
			u8 i=0;
			GPIO_PinNo PINi = 0;
			u32 CTL_Mask	= 0x0000000f;
			/*Gate Enable*/
			SET_BIT(RCGC2.R ,   PORTi);
			SET_BIT(RCGCGPIO.R, PORTi);
			while(i<5)
			{
				i++;
			}
			/*Commit Control*/
			GPIOLOCK(PORTi) = 0x4C4F434B ;	
			GPIOCR(PORTi) 	= 0x000000ff;
			GPIODEN(PORTi)	= 0x000000ff;
			/*Mux selects port as DIO*/
			GPIOAFSEL(PORTi) = 0;
			/*Data Control*/
			
			for(PINi=PIN0 ; PINi<=PIN7 ; PINi++)
			{	
				if(PinConfig[PORTi][PINi] == OUTPUT )
				{
					SET_BIT(GPIODIR(PORTi), PINi);
					CLR_BIT(GPIODATA(PORTi).R, PINi);
				}
				else if (PinConfig[PORTi][PINi] == INPUT_OPEN_DRAIN )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOODR(PORTi), PINi);

				}
				else if (PinConfig[PORTi][PINi] == INPUT_PULL_UP )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOPUR(PORTi), PINi);
				}
				else if (PinConfig[PORTi][PINi] == INPUT_PULL_DN )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOPDR(PORTi), PINi);
				}
				else
				{
					
					SET_BIT(GPIOAFSEL(PORTi), PINi);
					GPIOPCTL(PORTi) |= (CTL_Mask << (4*PINi) ) & PinConfig[PORTi][PINi];
				}			
			}
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/






