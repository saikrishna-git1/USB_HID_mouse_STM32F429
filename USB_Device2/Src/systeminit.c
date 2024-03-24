
#include <stdint.h>
#include "system_stm32f4xx.h"
#include "stm32f4xx.h"
#include "Helpers/logger.h"

LogLevel system_log_level = LOG_LEVEL_DEBUG;
uint32_t SystemCoreClock = 72000000; //HCLK = 72MHz

/*
 * HCLK = 72MHz
 *
 */


void config_clock(void) {
	//Modify Flash latency
	MODIFY_REG(FLASH->ACR,
			FLASH_ACR_LATENCY,
			FLASH_ACR_LATENCY_2WS << FLASH_ACR_LATENCY_Pos);

	//Enable HSE
	SET_BIT(RCC->CR, RCC_CR_HSEON);

	//Wait until HSE is stable
	while( !(READ_BIT(RCC->CR, RCC_CR_HSERDY)) );

	//Configure PLL: source=HSE, SYSCLK=72MHz
	MODIFY_REG(RCC->PLLCFGR,
		RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLP,
		_VAL2FLD(RCC_PLLCFGR_PLLM, 4) | _VAL2FLD(RCC_PLLCFGR_PLLN, 72) | _VAL2FLD(RCC_PLLCFGR_PLLQ, 3) | RCC_PLLCFGR_PLLSRC_HSE
	);

	// Enable PLL module
	SET_BIT(RCC->CR, RCC_CR_PLLON);

	// Wait until PLL is stable
	while (!READ_BIT(RCC->CR, RCC_CR_PLLRDY));

	// Switch system clock to PLL
	MODIFY_REG(RCC->CFGR,
		RCC_CFGR_SW,
		_VAL2FLD(RCC_CFGR_SW, RCC_CFGR_SW_PLL)
	);

	//AHB, APB pre-scalars - Configure PPRE1 = 2, (PPRE2 = 1, HPRE = 1 by default)
	MODIFY_REG(RCC->CFGR,
		RCC_CFGR_PPRE1,
		_VAL2FLD(RCC_CFGR_PPRE1, 4)
	);

	//Wait until PLL is used
	while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

	//Disable HSI - just to save power
	CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

void SystemInit(void) {
	config_clock();
}
