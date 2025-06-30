#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include "traffic_fsm.hpp"

using namespace std;

//constructor to set the starting values 
TrafficFSM :: TrafficFSM() : current(State::NS_Green), emergency(false) {}

//define a function to create a delay in between the state transitions
void TrafficFSM::delay(int seconds){
    this_thread::sleep_for(chrono::seconds(seconds));
}

//function to check a file to see if the emergency flag should be on or off
void TrafficFSM::checkEmergencyFlag(){
    //create an input file stream and opens the file at the specified data path to read. 
    ifstream in("../data/input.txt");
    //define a variable to hold a line of text from the file
    string line;
    //resets the flag to false by default
    emergency = false;
    //checks if the file is opened properly by reading the first line and if the line is 1, then emergency vehicle is passing
    if(in && getline(in,line)){
        //if 1 - emergency vehicle is present
        if(line=="1") {
            emergency = true;
            //reset the file contents to 0 after the emergency vehicle has passed
            ofstream out("../data/input.txt");
            out<<"0";
        }            
    }
}



void TrafficFSM::update(){
    //check for emergency trigger
    checkEmergencyFlag();
    //print the current state
    printState();

    //use switch statements to help cycle through the different states
    switch(current){
        case State::NS_Green:
            //create a delay
            delay(5);
            //check for an emergency or else just proceed to the next state
            current = emergency ? State::Emergency : State::NS_Yellow;
            //break out of the case
            break;
        
        case State::NS_Yellow:
            delay(2);
            current = emergency ? State::Emergency : State ::EW_Green;
            break;
        
        case State::EW_Green:
            delay(5);
            current = emergency ? State::Emergency : State ::  EW_Yellow;
            break;

        case State::EW_Yellow:
            delay(2);
            current = emergency ? State::Emergency : State::NS_Green;
            break;
        
        case State::Emergency:
            cout << "[EMERGENCY] ALL DIRECTIONS RED\n";
            delay(4);
            emergency = false;
            current = State::NS_Green;
            break;
    }


}
//create a function to print out whats happening at each case
void TrafficFSM::printState(){
    switch(current){
        case State::NS_Green:
            cout << "[NS:GREEN] [EW:RED]\n";
            break;
        
        case State::NS_Yellow:
            cout << "[NS:YELLOW] [EW:RED]\n";
            break;
        
        case State::EW_Green:
            cout << "[NS:RED] [EW:GREEN]\n";
            break;
        
        case State::EW_Yellow:
            cout <<"[NS:RED] [EW:YELLOW]\n";
            break;
        
        case State::Emergency:
            //handled directly in the void update function
            break;
    }

}

