#include "pins.h"
#include "global_var.h"
#include "interupt.h"
#include "bsp.h"
#include "led_function.h"

void setup() {
  pinMode(EC11A_PIN,INPUT); //D2脚为输入
  pinMode(EC11B_PIN,INPUT); //D3脚为输入
  pinMode(EC11W_PIN,INPUT); //D6脚为输入
  pinMode(LED1_POWER_PIN, OUTPUT);
  digitalWrite(LED1_POWER_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  attachInterrupt(0, EncoderA_ISR, LOW);  //注册中断0调用函数EncoderA
  attachInterrupt(1, EncoderSW_ISR, CHANGE);
  analogReference(EXTERNAL);
  setup_watchdog(9);
  pixels.begin(); // This initializes the NeoPixel library.
}


void loop() {
  // put your main code here, to run repeatedly:

}
