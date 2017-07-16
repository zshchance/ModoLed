#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//comment to stop debug
#define DEBUG_BY_SERIAL

// quantities of LED in the trip
#define NUMPIXELS  30
#define ANTI_SW_NOISE_THRESHOLD 5 //检测按键噪音阀值 ms 用来消抖
#define AUTO_POWER_DOWN_AFTER_WAKEUP  1000  //关机状态下被唤醒后自动恢复为powerdown状态的时间 ms
#define DOUBLE_HIT_KEY_INTERVAL_TIME  300  //双击或多击时单次按键触发间隔的时间 ms
#define LONG_PRESS_KEEP_TIME  1500  //长按生效时间 ms

#endif //CONFIGURATION_H

