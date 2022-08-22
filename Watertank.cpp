#include "Watertank.h"

// constructor

Watertank::Watertank(int wt_id, S_Distance* sensor_p, int wt_cal_low, int wt_cal_high, int wt_val_alert, int wt_val_stop)
{
    set_id(wt_id);
    set_sensor_p(sensor_p);
    set_cal_low(wt_cal_low);
    set_cal_high(wt_cal_high);
    set_val_alert(wt_val_alert);
    set_val_stop(wt_val_stop);
}

// private

void Watertank::set_id(int wt_id)
{
    id = wt_id;
}

void Watertank::set_cal_low(int wt_cal_low)
{
    cal_low = wt_cal_low;
}

void Watertank::set_cal_high(int wt_cal_high)
{
    cal_high = wt_cal_high;
}

int Watertank::calc_percent(int val_raw)
{
    return 100 - ((val_raw - get_cal_low()) * 100 / (get_cal_high()- get_cal_low()));
}

// public

int Watertank::get_id()
{
    return id;
}

int Watertank::get_cal_low()
{
    return cal_low;
}

int Watertank::get_cal_high()
{
    return cal_high;
}

int Watertank::get_val_alert()
{
    return val_alert;
}

int Watertank::get_val_stop()
{
    return val_stop;
}

S_Distance* Watertank::get_sensor_p()
{
    return sensor_p;
}

void Watertank::set_sensor_p(S_Distance* sensor_p)
{
    this->sensor_p = sensor_p;
}

void Watertank::set_val_alert(int wt_val_alert)
{
    val_alert = wt_val_alert;
}

void Watertank::set_val_stop(int wt_val_stop)
{
    val_stop = wt_val_stop;
}

void Watertank::act_calibrate_low(int wt_cal_low)
{
  if(wt_cal_low == -1)
  {
      set_cal_low(act_read_sensor());
  }
  else
  {
      set_cal_low(wt_cal_low);
  }  
}

void Watertank::act_calibrate_high(int wt_cal_high)
{
  if(wt_cal_high == -1)
  {
      set_cal_high(act_read_sensor());
  }
  else
  {
      set_cal_high(wt_cal_high);
  }  
}

int Watertank::act_read_sensor_raw()
{
    return sensor_p->act_read();
}

int Watertank::act_read_sensor()
{
    return calc_percent(act_read_sensor_raw());
}

int Watertank::act_check()
{
    int val = act_read_sensor();
    if(val > val_alert)
    {
        return 0;
    }
    else if(val > val_stop)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}