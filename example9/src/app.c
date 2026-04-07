#include "app.h"
#include "uart.h"

void app_init(void) {
    uart_init();
    uart_send_string("app_init()\n");
}

void app_run(void) {
    uart_send_string("app_run()\n");
}