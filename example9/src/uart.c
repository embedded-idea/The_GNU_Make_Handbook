#include <stdio.h>
#include "uart.h"

void uart_init(void) {
    printf("UART initialized\n");
}

void uart_send_string(const char *s) {
    printf("UART TX: %s", s);
}