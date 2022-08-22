#ifndef WATERTANK_H
#define WATERTANK_H
#include <Arduino.h>
#include "S_Distance.h"

class Watertank
{
    private:
        int id;
        S_Distance* sensor_p;
        int cal_low;
        int cal_high;
        int val_alert;
        int val_stop;
        
        void set_id(int wt_id);
        void set_cal_low(int wt_cal_low);
        void set_cal_high(int wt_cal_high);
        int calc_percent(int val_raw);

    public:
        Watertank(int wt_id, S_Distance* sensor_p, int wt_cal_low, int wt_cal_high, int wt_val_alert = 10, int wt_val_stop = 5);
        int get_id();
        int get_cal_low();
        int get_cal_high();
        int get_val_alert();
        int get_val_stop();
        S_Distance* get_sensor_p();
        void set_sensor_p(S_Distance* sensor_p);
        void set_val_alert(int wt_val_alert);
        void set_val_stop(int wt_val_stop);
        void act_calibrate_low(int wt_cal_low = -1);
        void act_calibrate_high(int wt_cal_high = -1);
        int act_read_sensor_raw();
        int act_read_sensor();
        int act_check();
};

#endif