#include "A_Valve.h"

// constructor

A_Valve::A_Valve(int valve_id, int valve_pin)
{
    set_id(valve_id);
    set_pin(valve_pin);
}

// private

void A_Valve::set_id(int valve_id)
{
    id = valve_id;
}

void A_Valve::set_pin(int valve_pin)
{
    pin = valve_pin;
    pinMode(pin, OUTPUT);
    set_state(0);
}

void A_Valve::set_state(int valve_state)
{
    state = valve_state;
    digitalWrite(pin, state);
}

// public

int A_Valve::get_id()
{
    return id;
}

int A_Valve::get_pin()
{
    return pin;
}

int A_Valve::get_state()
{
    return state;
}

void A_Valve::act_open()
{
    set_state(1);
}

void A_Valve::act_close()
{
    set_state(0);
}

void A_Valve::act_change()
{
    if(state)
    {
        set_state(0);
    }
    else
    {
        set_state(1);
    }    
}