#ifndef S_WATER_H
#define S_WATER_H
#include <Arduino.h>

class S_Water
{
    private:
        int id;
        int pin;
        int cal_low;
        int cal_high;
        int val;
        
        void set_id(int h2o_id);
        void set_pin(int h2o_pin);
        void set_cal_low(int h2o_cal_low);
        void set_cal_high(int h2o_cal_high);
        int calc_percent(int val_raw);

    public:
        S_Water(int h2o_id, int h2o_pin, int h2o_cal_low, int h2o_cal_high);
        int get_id();
        int get_pin();
        int get_cal_low();
        int get_cal_high();
        void act_calibrate_low(int h2o_cal_low = -1);
        void act_calibrate_high(int h2o_cal_high = -1);
        int act_read();
        int act_read_raw();
};

#endif