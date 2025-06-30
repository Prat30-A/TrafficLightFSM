#pragma once
#include <string>

//create an enum class to define named states for the traffic light FSM
enum class State{
    NS_Green,
    NS_Yellow,
    EW_Green,
    EW_Yellow,
    Emergency
};

class TrafficFSM {
public:
  TrafficFSM();
  void update();
  State getState() const;                
private:
//define a variable for the current state of the signal
  State current;
//define a flog for the emergency vehicle
  bool emergency;
  void delay(int seconds);
  void checkEmergencyFlag();
  void printState();
  void saveState(const std::string& s);
};