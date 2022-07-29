/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_Configure.h
 *       Module:  System Control
 *
 *  Description:  This header file contains Microcontroller System Clock Control Configurations     
 *  
 *********************************************************************************************************************/

#ifndef		SYSCTRL_CONFIGURE_H
#define 	SYSCTRL_CONFIGURE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include	"SysCtrl_Interface.h"

/**********************************************************************************************************************
 *  MCU System Clock Control Configurations
 *********************************************************************************************************************/

#define USE_RCC2					DISABLE   /*RCC2 Fields Override RCC*/

/*RCC*/
#define MAIN_OSCILLATOR				DISABLE
#define OSCILLATOR_SOURCE			PIOSC
#define CRYSTAL_VALUE				_16_MHZ
#define PLL_BYPASS					ENABLE
#define	PLL_POWER_DOWN				ENABLE
#define PWM_DIVISOR					DIV_64
#define PWM_DIVISOR_EN				DISABLE
#define SYSCLOCK_DIVIDER_EN			ENABLE
#define SYSTEM_CLOCK_DIVIDER		1			/*1 -> 16 PLL Dependent*/
#define AUTO_CLOCK_GATING			DISABLE

/*RCC2*/
#define OSCILLATOR_SOURCE_2			PIOSC
#define PLL_BYPASS_2				ENABLE
#define	PLL_POWER_DOWN_2			ENABLE
#define	PWRDN_USB_PLL				ENABLE
#define SYSTEM_CLOCK_DIVIDER_2		11			/*1 -> 64 PLL Dependent*/
#define DIVIDE_PLL_AS				_200_MHZ


#endif		/* SYSCTRL_CONFIGURE_H */