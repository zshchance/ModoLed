#ifndef PINS_H
#define PINS_H

//EC11 PINS
#define EC11A_PIN 2  //中断0 编码器A引脚
#define EC11B_PIN 4  //编码器B引脚
#define EC11W_PIN 3  //中断1 编码器KEY引脚

#define LED1_POWER_PIN 7  //灯条1的供电控制引脚 置1开启供电
#define LED2_POWER_PIN 10  //灯条2的供电控制引脚 置1开启供电
#define LED_DATA_PIN    5  //LED灯条的数据控制引脚 VER1版本设计硬件中两个灯条共享数据引脚

#define TEMPERATURE_PIN A3   //温度传感器AD输入引脚
#define  TEMPERATURE_EN_PIN  9  //温度传感器取电引脚
#define  BATTERY_VOLTAGE_PIN  A0  //电池电压采集引脚
#define  USB_VOLTAGE_PIN  A2    //USB充电状态电压采集引脚

#endif //PINS_H
