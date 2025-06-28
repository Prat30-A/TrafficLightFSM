#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>

using namespace std;

//create an enum class to define named states for the traffic light FSM
enum class State{
    NS_Green,
    NS_Yellow,
    EW_Green,
    EW_Yellow,
    Emergency
};

class TrafficFSM{
private:
//define a variable for the current state of the signal
    State current;

//define a flog for the emergency vehicle
    bool emergency;

//define a function to create a delay in between the state transitions
    void delay(int seconds){
        this_thread::sleep_for(chrono::seconds(seconds));
    }

//function to check a file to see if the emergency flag should be on or off
    void checkEmergencyFlag(){
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
public:
//constructor to set the starting values 
    TrafficFSM() : current(State::NS_Green), emergency(false) {}

    void update(){
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
    void printState(){
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
    
};

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