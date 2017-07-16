#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include <Adafruit_NeoPixel.h>
#include <Enerlib.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include<EEPROM.h>
#include "configuration.h"

#define SIGNAL_IRQ_EC11SW 2
#define SIGNAL_IRQ_WDT 3
#define SIGNAL_IRQ_EC11A 4
#define POWER_STATE_AWAKE 1
#define MODE_STATE_POWER_OFF 0
#define MODE_STATE_LIGHTING 1
#define MODE_STATE_BREATHE 2
#define MODE_STATE_WATERFALL 3


struct led_color{
   unsigned char r;
   unsigned char g;
   unsigned char b;
   unsigned char w;
};
struct key_para{
   unsigned long edge_down_time;
   unsigned long edge_up_time;
   unsigned char key_times;   //记录按键单击、双击、或是其他行为
};

#ifndef EXT

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, LED2_DATA_PIN, NEO_RGBW + NEO_KHZ800);
Energy energy;
unsigned char mcu_state_wake_up_by = POWER_STATE_AWAKE;  //0 sleeping,1 awake,2 EC11_SW irq from sleeping, 
                    //3 WDT_ISR irq from sleeping,4 EC11_A irq from sleeping
unsigned char led_work_mode = MODE_STATE_POWER_OFF;///0 power off, 1 lighting mode, 2 breathe mode, 3 waterfall mode
key_para ec11_switch;

#else

EXT Adafruit_NeoPixel pixels ;
EXT Adafruit_NeoPixel pixels2 ;
EXT Energy energy;
EXT unsigned char mcu_state_wake_up_by; 
EXT unsigned char led_work_mode;
EXT key_para ec11_switch;

#endif  //EXT

#endif //GLOBAL_VAR_H
