#include <stdio.h>
#include <stdlib.h>
#include "swd_load.hpp"
#include "pico/stdlib.h"

#include "pico-stick.h"

int main() {
    stdio_init_all();

    while (!stdio_usb_connected())
    {
      sleep_ms(100);
    }

    printf("SWCLK pin 2\nSWD   pin 3\n");
    printf("Press enter to reload GPU\n");
    while (true) {
        if (getchar() == '\n');
        swd_load_program(section_addresses, section_data, section_data_len, sizeof(section_addresses) / sizeof(section_addresses[0]), 0x20000001, 0x15004000, true);
        printf("Press enter to reload GPU\n");
    }
}