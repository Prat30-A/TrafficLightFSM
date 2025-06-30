#include <iostream>
#include "traffic_fsm.hpp"


int main()
{
    //declare an fsm which calls the basic values described in the constructor
    TrafficFSM fsm;

    //loop infinitely and keep updating the signal states using the update functions
    while(true){
        fsm.update();
    }

    return 0;
}