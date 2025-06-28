import time

def write_command(value):
    with open("data/input.txt","w") as f:
        f.write(str(value))
    print(f"Python wrote '{value}' to input.txt")

def main():
    print("Traffic Light fsm interface (Simulated UART)")
    print("Enter '1' for EMERGENCY or '0' for Normal mode")
    print("Press Ctrl+C to exit.\n")

    try:
        while True:
            cmd = input("Command (1 or 0): ").strip()
            if cmd in ["0", "1"]:
                write_command(cmd)
            else:
                print("Invalid input. Enter 1 or 0")
            #put a small delay to ensure the commands are being updated 
            time.sleep(1)

    except KeyboardInterrupt:
        print("\nExiting interface....")

if __name__ =="__main__":
    main()