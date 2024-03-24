#include "usbd_driver.h"

void init_usb_pins() {
	// All USB pins are in GPIO-B
	// Enable GPIOB clock
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);

	// Set alt fn 12 for PB14 (D-), PB15 (D+)
	MODIFY_REG(GPIOB->AFR[1],
		GPIO_AFRH_AFSEL14 | GPIO_AFRH_AFSEL15,
		_VAL2FLD(GPIO_AFRH_AFSEL14, 0xC) | _VAL2FLD(GPIO_AFRH_AFSEL15, 0xC)
	);

	// Configure the pins to work in alt fn mode
	MODIFY_REG(GPIOB->MODER,
		GPIO_MODER_MODER14 | GPIO_MODER_MODER15,
		_VAL2FLD(GPIO_MODER_MODER14, 2) | _VAL2FLD(GPIO_MODER_MODER15, 2)
	);
}
