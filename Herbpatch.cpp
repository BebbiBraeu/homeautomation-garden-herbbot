#include "Herbpatch.h"

// constructor

Herbpatch::Herbpatch(int hp_id, S_Water* sensor_p, A_Pump* pump_p, std::vector<A_Valve*> valve_p_vec, int water_need, int water_dur, std::vector<String> plants_vec)
{
    set_id(hp_id);
    set_sensor_p(sensor_p);
    set_pump_p(pump_p);
    set_valve_p_vec(valve_p_vec);
    set_water_need(water_need);
    set_water_dur(water_dur);
    set_plants_vec(plants_vec);
    set_water_last(0);
}

// private

void Herbpatch::set_id(int hp_id)
{
    id = hp_id;
}

void Herbpatch::set_water_last(unsigned long water_last)
{
    this->water_last = water_last;
}

int Herbpatch::act_water_on()
{
    for(int i = 0; i < this->valve_p_vec.size(); i++)
    {
        this->valve_p_vec[i]->act_open();
    }
    return this->pump_p->act_on();
}

int Herbpatch::act_water_off()
{
    for(int i = 0; i < this->valve_p_vec.size(); i++)
    {
        this->valve_p_vec[i]->act_close();
    }
    return this->pump_p->act_off();
}


// public

int Herbpatch::get_id()
{
    return id;
}

S_Water* Herbpatch::get_sensor_p()
{
    return sensor_p;
}

A_Pump* Herbpatch::get_pump_p()
{
    return pump_p;
}

std::vector<A_Valve*> Herbpatch::get_valve_p_vec()
{
    return valve_p_vec;
}

int Herbpatch::get_water_need()
{
    return water_need;
}

int Herbpatch::get_water_dur()
{
    return water_dur;
}

std::vector<String> Herbpatch::get_plants_vec()
{
    return plants_vec;
}

unsigned long Herbpatch::get_water_last()
{
    return millis() - water_last;
}

String Herbpatch::get_return_string(int ret)
{
    String ret_str;
    switch(ret)
    {
        case 0:
            ret_str = "Herbpatch_" + (String)this->get_id() + " does not need to be watered yet.";
        case 1:
            ret_str = "Herbpatch_" + (String)this->get_id() + " has been watered.";
        case 2:
            ret_str = "Herbpatch_" + (String)this->get_id() + " has been watered. But Watertank_" + this->pump_p->get_tank_p()->get_id() + " needs to be refilled soon.";
        case 3:
            ret_str = "Herbpatch_" + (String)this->get_id() + " could not be watered. Watertank_" + this->pump_p->get_tank_p()->get_id() + " needs to be refilled.";
    }
    return ret_str;
}

void Herbpatch::set_sensor_p(S_Water* sensor_p)
{
    this->sensor_p = sensor_p;
}

void Herbpatch::set_pump_p(A_Pump* pump_p)
{
    this->pump_p = pump_p;
}

void Herbpatch::set_valve_p_vec(std::vector<A_Valve*> valve_p_vec)
{
    this->valve_p_vec = valve_p_vec;
}

void Herbpatch::set_water_need(int water_need)
{
    this->water_need = water_need;
}

void Herbpatch::set_water_dur(int water_dur)
{
    this->water_dur = water_dur;
}

void Herbpatch::set_plants_vec(std::vector<String> plants_vec)
{
    this->plants_vec = plants_vec;
}

int Herbpatch::act_check_water_level()
{
    return this->get_sensor_p()->act_read();
}

int Herbpatch::act_check_water_need()
{
    if(water_need > 0)
    {
        int water_level = act_check_water_level();
        if(water_level < water_thresh[water_need-1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }    
}

int Herbpatch::act_water()
{
    if(act_check_water_need())
    {
        int ret = act_water_on();
        if(ret < 3)
        {
            set_water_last(millis());
        }
        else
        {
            (void) act_water_off();
        }
        return ret;
    }
    else
    {
        return 0;
    }
}