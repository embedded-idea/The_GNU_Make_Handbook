#include "uart.h"

int main(void) {
    uart_init();
    uart_send_string("Hello from ARM bare-metal!\n");

    while (1) {
    }

    return 0;
}