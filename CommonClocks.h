#ifndef _COMMONCLOCKSH_
#define _COMMONCLOCKSH_

void COMMONCLOCKS_sysTick_Init();
void COMMONCLOCKS_sysTick_Interrupt_Init();
void COMMONCLOCKS_sysTick_delay_3MHZ(uint16_t delay);
void COMMONCLOCKS_sysTick_delay_48MHZ(uint16_t delay);

#endif
