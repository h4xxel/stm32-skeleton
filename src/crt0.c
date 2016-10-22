#include <stdint.h>
#include <stddef.h>

int main();

__attribute__((section(".runtime")))
void _start() {
	extern uint8_t __data_init_start__;
	extern uint8_t __data_start__;
	extern uint8_t __data_end__;
	extern uint8_t __bss_start__;
	extern uint8_t __bss_end__;
	uint8_t *dest, *source;

	/* Clear .bss */
	dest = &__bss_start__;
	while(dest != &__bss_end__)
		*dest++ = 0;
	
	/* Initialize variables with compile time defined content */
	source = &__data_init_start__;
	dest = &__data_start__;
	while(dest != &__data_end__)
		*dest++ = *source++;
	
	/* Done setting everything up! */
	main();
	for(;;);
}
