extern int main(void);

void Reset_Handler(void) {
    main();
    while (1) {
    }
}

/* Minimal vector table */
__attribute__((section(".vectors")))
void (* const vector_table[])(void) = {
    Reset_Handler
};