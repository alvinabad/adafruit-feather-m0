#ifndef BLINKER_H
#define BLINKER_H

#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif

#define LED9       9
#define LED11      11

#define DELAY_ON   1000
#define DELAY_OFF  1000

void init_blinker();
void led_blinker();

#endif
