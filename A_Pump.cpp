#include "A_Pump.h"

// constructor

A_Pump::A_Pump(int pump_id, int pump_pin, Watertank* tank_p, int speed, int pump_pwm_Channel, int pump_pwm_Freq, int pump_pwm_Resolution)
{
    set_id(pump_id);
    pwm_Channel = pump_pwm_Channel;
    pwm_Freq = pump_pwm_Freq;
    pwm_Resolution = pump_pwm_Resolution;
    ledcSetup(pwm_Channel, pwm_Freq, pwm_Resolution);
    set_pin(pump_pin);
    set_tank_p(tank_p);
    set_speed(speed);    
}

// private

void A_Pump::set_id(int pump_id)
{
    id = pump_id;
}

void A_Pump::set_pin(int pump_pin)
{
    pin = pump_pin;
    ledcAttachPin(pin, pwm_Channel);
    pinMode(pin, OUTPUT);
    set_state(0);
}

void A_Pump::set_state(int pump_state)
{
    state = pump_state;
    if(pump_state)
    {
        ledcWrite(pwm_Channel, speed);
    }
    else
    {
        ledcWrite(pwm_Channel, 0);
    }
    
}

// public

int A_Pump::get_id()
{
    return id;
}

int A_Pump::get_pin()
{
    return pin;
}

int A_Pump::get_state()
{
    return state;
}

Watertank* A_Pump::get_tank_p()
{
    return tank_p;
}

int A_Pump::get_speed()
{
    return speed;
}

String A_Pump::get_return_string(int ret)
{
    String ret_str;
    switch(ret)
    {
        case 0:
            ret_str = "Pump_" + (String)this->get_id() + " was turned off.";
        case 1:
            ret_str = "Pump_" + (String)this->get_id() + " was turned on.";
        case 2:
            ret_str = "ALERT: Watertank_" + (String)this->get_tank_p()->get_id() + " should be refilled, but pump_" + (String)this->get_id() + " was still turned on!";
        case 3:
            ret_str = "ERROR: Watertank_" + (String)this->get_tank_p()->get_id() + " is empty, pump_" + (String)this->get_id() + " was not turned on!";
    }
    return ret_str;
}

void A_Pump::set_tank_p(Watertank* tank_p)
{
    this->tank_p = tank_p;
}

void A_Pump::set_speed(int speed)
{
    this->speed = speed;
}

int A_Pump::act_on()
{
    if(act_check_tank() == 2)
    {
        set_state(0);
        return 3;
    }
    else
    {
        set_state(1);
        if(act_check_tank() == 1)
        {
            return 2;
        }
        return 1;
    }
}

int A_Pump::act_off()
{
    set_state(0);
    return 0;
}

int A_Pump::act_change()
{
    if(state)
    {
        return act_off();
    }
    else
    {
        return act_on();
    }    
}

int A_Pump::act_check_tank()
{
    return tank_p->act_check();
}