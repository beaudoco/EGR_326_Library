#include <stdio.h>
#include <stdint.h>
#include "CommonClocks.h"
#include "msp.h"
#include "driverlib.h"

void COMMONCLOCKS_sysTick_Init()
{
    SysTick -> CTRL = 0;                            // Disable SysTick during setup
    SysTick -> LOAD = 0x00FFFFFF;                   // Max reload value
    SysTick -> VAL  = 0;                            // Clear current value
    SysTick -> CTRL = 0x00000005;                   // Enable Systick, CPU clk, no interrupts
}

void COMMONCLOCKS_sysTick_Interrupt_Init()
{
    /* Configuring SysTick to trigger at 1500000 (MCLK is 3MHz so this will make
     * it toggle every 0.5s) */
    MAP_SysTick_enableModule();
    MAP_SysTick_setPeriod(1500000);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_SysTick_enableInterrupt();
}

void COMMONCLOCKS_sysTick_delay_3MHZ(uint16_t delay)
{
    SysTick -> LOAD = ((delay*3000) - 1);           // 1 ms * delay, counts down to 0
    SysTick -> VAL  = 0;                            // clear value
    while((SysTick -> CTRL & 0x00010000) == 0);     // Wait for flag to be set
}

void COMMONCLOCKS_sysTick_delay_48MHZ(uint16_t delay)
{
    SysTick -> LOAD = ((delay*48000) - 1);           // 1 ms * delay, counts down to 0
    SysTick -> VAL  = 0;                             // clear value
    while((SysTick -> CTRL & 0x00010000) == 0);      // Wait for flag to be set
}
