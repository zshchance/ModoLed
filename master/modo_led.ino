#include "pins.h"
#include "configuration.h"
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
  //setup_watchdog(9);  //stop WDT function
  pixels.begin(); // This initializes the NeoPixel library.
  ec11_switch.key_times=0;
  ec11_switch.edge_down_time=ec11_switch.edge_up_time=0;
#ifdef DEBUG_BY_SERIAL
  Serial.begin(38400);
  Serial.println("ModoLed starting.");
#endif
  set_pin_mcu_into_sleep();
}

void power_on(){
    pinMode(LED1_POWER_PIN, OUTPUT);
    digitalWrite(LED1_POWER_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    led_work_mode=MODE_STATE_LIGHTING;
    pixels.begin(); // This initializes the NeoPixel library.

    pinMode(LED2_POWER_PIN, OUTPUT);
    digitalWrite(LED2_POWER_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    pixels2.begin(); // This initializes the NeoPixel library.
    
    int i;
    for(i=0;i<50;i++){
      set_trip_brig(i);
      set_trip2_brig(i);
      delay(5);
    }
}

void power_off(){
    int i;
    for(i=50;i>=0;i--){
      set_trip_brig(i);
      set_trip2_brig(i);
      delay(5);
    }
    set_pin_mcu_into_sleep();
}

void scan_ec11_key_state(){
  if(led_work_mode==0){ //关机状态下按的按键
    if(ec11_switch.edge_up_time>ec11_switch.edge_down_time){ //按键当前为抬起状态
      if(millis()-ec11_switch.edge_up_time<AUTO_POWER_DOWN_AFTER_WAKEUP){ //
        if(ec11_switch.key_times==2){ //按键被双击
          ec11_switch.key_times=0;
#ifdef DEBUG_BY_SERIAL
          Serial.println("power on.");
#endif
          power_on();
        }
      }else{
#ifdef DEBUG_BY_SERIAL
        Serial.println("key up sleep.");
#endif
        set_pin_mcu_into_sleep();
      }
    }else{  //按键目前还是按下状态
      if(millis()-ec11_switch.edge_down_time>AUTO_POWER_DOWN_AFTER_WAKEUP){
        ec11_switch.key_times=0;
#ifdef DEBUG_BY_SERIAL
        Serial.println("key down sleep.");
#endif
        set_pin_mcu_into_sleep();
      }
    }
  }else{//led_work_mode
    if(ec11_switch.edge_up_time<ec11_switch.edge_down_time){ //按键当前为按下状态
      if(millis()-ec11_switch.edge_down_time>LONG_PRESS_KEEP_TIME){ //发生长按事件
#ifdef DEBUG_BY_SERIAL
        Serial.println("long_pressed.");
#endif
        if(1){  //这里占位关机条件 先简略关机
          power_off();
        }      
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(led_work_mode==0){ //关机状态下设备被唤醒了
    if(mcu_state_wake_up_by == SIGNAL_IRQ_EC11SW){
      scan_ec11_key_state();
    }else if(mcu_state_wake_up_by == SIGNAL_IRQ_WDT){  //看门狗定时唤醒，要检查一下电池电量，或者直接忽略
#ifdef DEBUG_BY_SERIAL
      Serial.println("Wake up by WDT.");
#endif
      set_pin_mcu_into_sleep();
    }else{  //其他唤醒信号，将忽略
#ifdef DEBUG_BY_SERIAL
      Serial.println("Don't borther me.");
#endif
      set_pin_mcu_into_sleep();
    }
  }else{//led_work_mode
    scan_ec11_key_state();
  }
}
