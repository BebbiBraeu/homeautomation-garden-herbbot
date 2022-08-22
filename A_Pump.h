#ifndef A_PUMP_H
#define A_PUMP_H
#include <Arduino.h>
#include "Watertank.h"

class A_Pump
{
    private:
        int id;
        int pin;
        int state;
        int speed;
        Watertank* tank_p;
        int pwm_Channel;
        int pwm_Freq;
        int pwm_Resolution;
        
        void set_id(int id_valve);
        void set_pin(int pin_valve);
        void set_state(int state_valve);

    public:
        A_Pump(int pump_id, int pump_pin, Watertank* tank_p, int speed = 245, int pump_pwm_Channel = 0, int pump_pwm_Freq = 60000, int pump_pwm_Resolution = 8);
        int get_id();
        int get_pin();
        int get_state();
        Watertank* get_tank_p();
        int get_speed();
        String get_return_string(int ret);
        void set_tank_p(Watertank* tank_p);
        void set_speed(int speed);
        int act_on();
        int act_off();
        int act_change();
        int act_check_tank();
};

#endif
