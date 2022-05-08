#ifndef SWITCH_HEADER
#define SWITCH_HEADER

void switch_init();
void switch_interrupt_handler();
extern int switches;
char switch_update_interrupt_sense();
#define SWITCHES 15

#endif
