# 🚦 Traffic Light FSM (Finite State Machine) Simulation
This project simulates a traffic light system using a Finite State Machine (FSM) written in C++. It includes an interface built with Python to simulate emergency overrides, mimicking UART communication for embedded system testing.

## 📁 Project Structure
TrafficLightFSM/
├── src/ # Main C++ source code for FSM logic
│ └── traffic_fsm.cpp/hpp
├── interface/ # Python interface to simulate UART input
│ └── control.py
├── data/ # Shared file for state communication (input.txt)
├── CMakeLists.txt # Build configuration
└── README.md # This file

## 🔧 Features

- Simulates North-South (NS) and East-West (EW) traffic lights with timed transitions.
- Emergency mode (all directions red) triggered by Python script.
- Designed to be compatible with embedded systems (e.g. STM32).
- Manual test interface using simulated UART via Python.

## 🛠️ How to Build and Run (C++ FSM)

### Prerequisites

- [CMake](https://cmake.org/)
- A C++ compiler (e.g. MinGW or g++)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/Prat30-A/TrafficLightFSM.git
cd TrafficLightFSM

# Create and enter build directory
mkdir build
cd build

# Run CMake and build
cmake ..
cmake --build .

# Run the FSM executable
./traffic_fsm.exe

# Run the Python Interface
cd interface
python control.py
- You'll be prompted to enter 1 (to simulate emergency) or 0 (normal mode). This writes to ../data/input.txt, which the FSM reads.

#FSM Logic
The FSM has five states:

NS_Green

NS_Yellow

EW_Green

EW_Yellow

Emergency

Each state transitions with a delay:

Green: 5s

Yellow: 2s

Emergency: 4s (all red)

The Python script can trigger Emergency state by writing 1 to data/input.txt.

#License
This project is open-source under the MIT License.