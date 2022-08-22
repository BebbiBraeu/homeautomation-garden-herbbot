#ifndef HERBPATCH_H
#define HERBPATCH_H
#include <Arduino.h>
#include <vector>
#include "A_Pump.h"
#include "S_Water.h"
#include "A_Valve.h"

class Herbpatch
{
    private:
        int id;
        S_Water* sensor_p;
        A_Pump* pump_p;
        std::vector<A_Valve*> valve_p_vec;
        int water_need;
        int water_dur;
        int water_thresh[3] = {25, 50, 75};
        std::vector<String> plants_vec;
        unsigned long water_last;
        
        void set_id(int hp_id);
        void set_water_last(unsigned long water_last);
        int act_water_on();
        int act_water_off();

    public:
        Herbpatch(int hp_id, S_Water* sensor_p, A_Pump* pump_p, std::vector<A_Valve*> valve_p_vec, int water_need, int water_dur, std::vector<String> plants_vec);
        int get_id();
        S_Water* get_sensor_p();
        A_Pump* get_pump_p();
        std::vector<A_Valve*> get_valve_p_vec();
        int get_water_need();
        int get_water_dur();
        std::vector<String> get_plants_vec();
        unsigned long get_water_last();
        String get_return_string(int ret);
        void set_sensor_p(S_Water* sensor_p);
        void set_pump_p(A_Pump* pump_p);
        void set_valve_p_vec(std::vector<A_Valve*> valve_p_vec);
        void set_water_need(int water_need);
        void set_water_dur(int water_dur);
        void set_plants_vec(std::vector<String> plants_vec);
        int act_check_water_level();
        int act_check_water_need();
        int act_water();
};

#endif