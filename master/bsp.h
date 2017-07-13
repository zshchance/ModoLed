#ifndef BSP_H
#define BSP_H

void setup_watchdog(int ii);
void set_pin_mcu_into_sleep();
int get_temp_ad_value();
int get_bat_ad_value();

#endif //BSP_H
