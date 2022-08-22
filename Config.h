#ifndef HERBOT_CONF
#define HERBOT_CONF
#include <vector>

#define HERBPATCH_NUM  2
int herbpatch_sensor_id[HERBPATCH_NUM] = {0, 1};
int herbpatch_pump_id[HERBPATCH_NUM] = {0, 0};
std::vector<std::vector<int>> herbpatch_valve_id_vec {{0}, {1}};
int herbpatch_water_need[HERBPATCH_NUM] = {1, 2}; // 0: no, 1: low, 2: medium, 3: high 
int herbpatch_water_dur[HERBPATCH_NUM] = {5, 5}; // watering time in seconds
std::vector<std::vector<String>> herbpatch_plants_vec {{"Minze", "Basilikum", "Thymian"}, {"Oregano"}};
#define S_DISTANCE_NUM  1
int s_distance_pin[S_DISTANCE_NUM] = {0};
#define WATERTANK_NUM  1
int watertank_sensor_id[WATERTANK_NUM] = {0};
int watertank_cal_low[WATERTANK_NUM] = {0};
int watertank_cal_high[WATERTANK_NUM] = {100};
#define A_VALVE_NUM  3
int a_valve_pin[A_VALVE_NUM] = {0, 0, 0};
#define A_PUMP_NUM  1
int a_pump_pin[A_PUMP_NUM] = {0};
int a_pump_tank_id[A_PUMP_NUM] = {0};
#define S_WATER_NUM  3
int s_water_pin[S_WATER_NUM] = {0, 0, 0};
int s_water_cal_low[S_WATER_NUM] = {0, 10, 20};
int s_water_cal_high[S_WATER_NUM] = {100, 110, 120};
#define S_TEMPERATUR_NUM  1
int s_temperatur_pin[S_TEMPERATUR_NUM] = {27};

#endif