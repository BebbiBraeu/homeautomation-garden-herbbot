#ifndef S_TEMPERATUR_H
#define S_TEMPERATUR_H
#include <Arduino.h>
#include "DHT.h"

#define DHTTYPE DHT11

class S_Temperatur
{
    private:
        int id;
        int pin;
        DHT* dht;
        float val_h;
        float val_t_c;
        float val_t_f;
        
        void set_id(int temp_id);
        void set_pin(int temp_pin);

    public:
        S_Temperatur(int temp_id, int temp_pin);
        int get_id();
        int get_pin();
        float act_read_h();
        float act_read_t_c();
        float act_read_t_f();
        float act_read_hi_c();
        float act_read_hi_f();
};

#endif
