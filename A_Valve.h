#ifndef A_VALVE_H
#define A_VALVE_H
#include <Arduino.h>

class A_Valve
{
    private:
        int id;
        int pin;
        int state;
        
        void set_id(int valve_id);
        void set_pin(int valve_pin);
        void set_state(int valve_state);

    public:
        A_Valve(int valve_id, int valve_pin);
        int get_id();
        int get_pin();
        int get_state();
        void act_open();
        void act_close();
        void act_change();
};

#endif
