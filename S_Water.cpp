#include "S_Water.h"

// constructor

S_Water::S_Water(int h2o_id, int h2o_pin, int h2o_cal_low, int h2o_cal_high)
{
    set_id(h2o_id);
    set_pin(h2o_pin);
    set_cal_low(h2o_cal_low);
    set_cal_high(h2o_cal_high);
}

// private

void S_Water::set_id(int h2o_id)
{
    id = h2o_id;
}

void S_Water::set_pin(int h2o_pin)
{
    pin = h2o_pin;
    pinMode(pin, INPUT);
}

void S_Water::set_cal_low(int h2o_cal_low)
{
    cal_low = h2o_cal_low;
}

void S_Water::set_cal_high(int h2o_cal_high)
{
    cal_high = h2o_cal_high;
}

int S_Water::calc_percent(int val_raw)
{
    return 100 - ((val_raw - get_cal_low()) * 100 / (get_cal_high()- get_cal_low()));
}

// public

int S_Water::get_id()
{
    return id;
}

int S_Water::get_pin()
{
    return pin;
}

int S_Water::get_cal_low()
{
    return cal_low;
}

int S_Water::get_cal_high()
{
    return cal_high;
}

void S_Water::act_calibrate_low(int h2o_cal_low)
{
    if(h2o_cal_low == -1)
    {
        set_cal_low(act_read_raw());
    }
    else
    {
        set_cal_low(h2o_cal_low);
    }
}

void S_Water::act_calibrate_high(int h2o_cal_high)
{
    if(h2o_cal_high == -1)
    {
        set_cal_high(act_read_raw());
    }
    else
    {
        set_cal_high(h2o_cal_high);
    }  
}

int S_Water::act_read()
{
    // return calc_percent(act_read_raw());

    return 45;
}

int S_Water::act_read_raw()
{
    val = 0;
    for(int i = 0; i < 10; i++)
    {
        val += analogRead(pin);
        delay(10);
    }
  
    val /= 10;
    return val;
}