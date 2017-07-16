#define EXT extern
#include "pins.h"
#include "configuration.h"
#include "global_var.h"

//WDT interrupt
ISR(WDT_vect) {
  if (energy.WasSleeping())
  {
    mcu_state_wake_up_by = SIGNAL_IRQ_WDT;
  }
}

//中断0调用函数
void EncoderA_ISR(){
   if (energy.WasSleeping())
  {
    mcu_state_wake_up_by=SIGNAL_IRQ_EC11A;
  }
}

void EncoderSW_ISR(void)
{
  unsigned char key_state =digitalRead(EC11W_PIN);
  if(key_state==LOW){
      if(millis()-ec11_switch.edge_down_time>ANTI_SW_NOISE_THRESHOLD){          //防抖条件成立
        if(millis()-ec11_switch.edge_down_time>DOUBLE_HIT_KEY_INTERVAL_TIME){
          ec11_switch.key_times=0;;
        }
      }
      ec11_switch.edge_down_time=millis();
  }else{
      if(millis()-ec11_switch.edge_up_time>ANTI_SW_NOISE_THRESHOLD  ){      //防抖条件成立
        if( millis()-ec11_switch.edge_up_time<DOUBLE_HIT_KEY_INTERVAL_TIME){ //双击操作以按键抬起为触发
          ec11_switch.key_times++;
        }else{
          ec11_switch.key_times=1;
        }
      }
      ec11_switch.edge_up_time=millis();
  }
  if (energy.WasSleeping()){
    mcu_state_wake_up_by=SIGNAL_IRQ_EC11SW;
  }
}

