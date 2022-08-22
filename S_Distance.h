#ifndef S_DISTANCE_H
#define S_DISTANCE_H
#include <Arduino.h>

class S_Distance
{
    private:
        int id;
        int pin;
        int val;
        
        void set_id(int dist_id);
        void set_pin(int dist_pin);

    public:
        S_Distance(int dist_id, int dist_pin);
        int get_id();
        int get_pin();
        int act_read();
};

#endif
