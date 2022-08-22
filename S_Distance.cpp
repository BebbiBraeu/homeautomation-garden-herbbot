#include "S_Distance.h"

// constructor

S_Distance::S_Distance(int dist_id, int dist_pin)
{
    set_id(dist_id);
    set_pin(dist_pin);
}

// private

void S_Distance::set_id(int dist_id)
{
    id = dist_id;
}

void S_Distance::set_pin(int dist_pin)
{
    pin = dist_pin;
    pinMode(pin, INPUT);
}

// public

int S_Distance::get_id()
{
    return id;
}

int S_Distance::get_pin()
{
    return pin;
}

int S_Distance::act_read()
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