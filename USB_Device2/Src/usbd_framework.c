#include "usbd_framework.h"

void usbd_init(void) {
	init_usb_pins();
	init_usb_core();
	usbd_connect_to_bus();
}
