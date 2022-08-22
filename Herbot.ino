#include "Config.h"
#include "Herbpatch.h"
#include "Watertank.h"
#include "A_Valve.h"
#include "A_Pump.h"
#include "S_Water.h"
#include "S_Distance.h"
#include "S_Temperatur.h"
#include "Timer.h"

#include <vector>


std::vector<Herbpatch*> herbpatch_vec;
std::vector<S_Distance*> s_distance_vec;
std::vector<Watertank*> watertank_vec;
std::vector<A_Valve*> a_valve_vec;
std::vector<std::vector<A_Valve*>> a_valve_vec_vec;
std::vector<A_Pump*> a_pump_vec;
std::vector<S_Water*> s_water_vec;
std::vector<S_Temperatur*> s_temperatur_vec;


String prt_str;


void setup()
{
  Serial.begin(9600); 

  for(int i = 0; i < S_DISTANCE_NUM; i ++)
  {
    s_distance_vec.push_back(new S_Distance(i, s_distance_pin[i]));
  }
  for(int i = 0; i < WATERTANK_NUM; i ++)
  {
    watertank_vec.push_back(new Watertank(i, s_distance_vec[watertank_sensor_id[i]], watertank_cal_low[i], watertank_cal_high[i]));
  }
  for(int i = 0; i < A_VALVE_NUM; i ++)
  {
    a_valve_vec.push_back(new A_Valve(i, a_valve_pin[i]));
  }
  for(int i = 0; i < A_PUMP_NUM; i ++)
  {
    a_pump_vec.push_back(new A_Pump(i, a_pump_pin[i], watertank_vec[a_pump_tank_id[i]]));
  }
  for(int i = 0; i < S_WATER_NUM; i ++)
  {
    s_water_vec.push_back(new S_Water(i, s_water_pin[i], s_water_cal_low[i], s_water_cal_high[i]));
  }
  for(int i = 0; i < S_TEMPERATUR_NUM; i ++)
  {
    s_temperatur_vec.push_back(new S_Temperatur(i, s_temperatur_pin[i]));
  }
  for(int i = 0; i < HERBPATCH_NUM; i ++)
  {
    std::vector<A_Valve*> a_valve_vec_temp;
    for(int j = 0; j < herbpatch_valve_id_vec[i].size(); j++)
    {
      a_valve_vec_temp.push_back(a_valve_vec[herbpatch_valve_id_vec[i][j]]);
    }
    a_valve_vec_vec.push_back(a_valve_vec_temp);
  }
  for(int i = 0; i < HERBPATCH_NUM; i ++)
  {
    herbpatch_vec.push_back(new Herbpatch(i, s_water_vec[herbpatch_sensor_id[i]], a_pump_vec[herbpatch_pump_id[i]], a_valve_vec_vec[i], herbpatch_water_need[i], herbpatch_water_dur[i], herbpatch_plants_vec[i]));
  }
}

void loop()
{
  /*
  for(int i = 0; i < A_VALVE_NUM; i ++)
  {
    if(i%2 == 0)
    {
      a_valve_vec[i]->act_change();
    }
    prt_str = "valve_" + (String)i + " - id: " + (String)a_valve_vec[i]->get_id() + " - pin: " + (String)a_valve_vec[i]->get_pin() + " - state: " + (String)a_valve_vec[i]->get_state();
    Serial.println(prt_str);
    Serial.println("--");
  }
  */

  /*
  for(int i = 100; i > 0; i --)
  {
    watertank_vec[0]->set_val(i);
    prt_str = "watertank_0 - val: " + (String)watertank_vec[0]->act_read_sensor();
    Serial.println(prt_str);
    try
    {
      a_pump_vec[0]->act_on();
    }
    catch(const int alrt)
    {
      if(alrt == 1)
      {
        Serial.println("ALERT: Watertank_0 should be refilled but pump_0 was still activated!");
      }
      else if(alrt == 2)
      {
        Serial.println("ERROR: Watertank_0 is empty, pump_0 was not actived!");
      }
    }
    prt_str = "pump_" + (String)a_pump_vec[0]->get_id() + " - state: " + (String)a_pump_vec[0]->get_state();
    Serial.println(prt_str);
  }
  */

  /*
  int i = 0;
  prt_str = "pump_" + (String)s_temperatur_vec[i]->get_id() + " @ pin_" + (String)s_temperatur_vec[i]->get_pin() +  " - T: " + (String)s_temperatur_vec[i]->act_read_t_c() + " °C - H: " + (String)s_temperatur_vec[i]->act_read_h() + " %";
  Serial.println(prt_str);
  */

  /*
  std::vector<String> output = herbpatch_vec[0]->get_plants_vec();
  for(int i = 0; i < output.size(); i++)
  {
    Serial.println(output[i]);
  }
  Serial.println(herbpatch_vec[0]->act_check_water_need());
  */

  for(int i = 0; i < herbpatch_vec.size(); i++)
  {
    try
    {
      Serial.println(herbpatch_vec[i]->get_return_string(herbpatch_vec[i]->act_water()));
    }
    catch(const int alrt)
    {
      // TODO: ERROR HANDLING
    }
  }

  delay(1000);
}
