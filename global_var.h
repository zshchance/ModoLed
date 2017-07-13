#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include <Adafruit_NeoPixel.h>
#include <Enerlib.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include<EEPROM.h>

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS  30

#ifndef EXT

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);
Energy energy;
int mcu_state = 1;  //0 sleeping,1 awake,2 EC11_SW irq from sleeping, 
                    //3 WDT_ISR irq from sleeping,4 EC11_A irq from sleeping
unsigned long time_anti_sens = 0; 
unsigned long time_anti_sw = 0;

#else

EXT Adafruit_NeoPixel pixels ;
EXT Energy energy;
EXT int mcu_state; 
EXT unsigned long time_anti_sens; 
EXT unsigned long time_anti_sw;

#endif  //EXT

#endif //GLOBAL_VAR_H
