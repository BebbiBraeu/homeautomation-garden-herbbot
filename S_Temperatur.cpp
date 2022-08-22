#include "S_Temperatur.h"

// constructor

S_Temperatur::S_Temperatur(int temp_id, int temp_pin)
{
    set_id(temp_id);
    set_pin(temp_pin);
    dht->begin();
}

// private

void S_Temperatur::set_id(int temp_id)
{
    id = temp_id;
}

void S_Temperatur::set_pin(int temp_pin)
{
    pin = temp_pin;
    dht = new DHT(pin, DHTTYPE);
}

// public

int S_Temperatur::get_id()
{
    return id;
}

int S_Temperatur::get_pin()
{
    return pin;
}

float S_Temperatur::act_read_h()
{
    return dht->readHumidity();
}

float S_Temperatur::act_read_t_c()
{
    Serial.println(dht->readTemperature(false));
    return dht->readTemperature(false);
}

float S_Temperatur::act_read_t_f()
{
    return dht->readTemperature(true);
}

float S_Temperatur::act_read_hi_c()
{
    val_h = act_read_h();
    val_t_f = act_read_t_f();
    return dht->computeHeatIndex(val_t_f, val_h, false);
}

float S_Temperatur::act_read_hi_f()
{
    val_h = act_read_h();
    val_t_f = act_read_t_f();
    return dht->computeHeatIndex(val_t_f, val_h, true);
}