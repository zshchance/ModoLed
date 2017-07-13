#define EXT extern
#include "pins.h"
#include "global_var.h"

//ii means:
// 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
// 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec
void setup_watchdog(int ii){
  byte bb;
  if (ii > 9 ) ii=9;
  bb=ii & 7;
  if (ii > 7) bb|= (1<<5);
  bb|= (1<<WDCE);
  MCUSR &= ~(1<<WDRF);
  // start timed sequence
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // set new watchdog timeout value
  WDTCSR = bb;
  WDTCSR |= _BV(WDIE);
}

void set_pin_mcu_into_sleep(){
  int i;
  for(i=0;i<20;i++){
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  }
  energy.PowerDown(); //Most power saving
}

int get_temp_ad_value(){
  int get_temp_value ;
  pinMode(TEMPERATURE_EN_PIN, OUTPUT);
  digitalWrite(TEMPERATURE_EN_PIN, HIGH);
  get_temp_value=analogRead(TEMPERATURE_PIN);
  pinMode(TEMPERATURE_EN_PIN, INPUT);
  return get_temp_value;
}

int get_bat_ad_value(){
  int get_bat_value ;
  get_bat_value=analogRead(BATTERY_VOLTAGE_PIN);
  return get_bat_value;
}

