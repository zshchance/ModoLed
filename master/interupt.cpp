#define EXT extern
#include "global_var.h"
//WDT interrupt
ISR(WDT_vect) {
  if (energy.WasSleeping())
  {
    mcu_state = 3;
  }
}

//中断0调用函数
void EncoderA_ISR(){
   if (energy.WasSleeping())
  {
    
  }
  if ((millis() - time_anti_sens) > 3){ //防抖动处理
      //change_color_value_by_sensor(digitalRead(Sen1B));
        //suspend_eeprom_action(2);
  }
  //time_anti_sens = time_record;
  time_anti_sens = millis();
}

void EncoderSW_ISR(void)
{
  if (energy.WasSleeping())
  {
    
  }
}

