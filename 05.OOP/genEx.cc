#include <iostream>

// Base Class (Super Class)
class GPIO {
protected:
    int pinNumber;  // GPIO pin number

public:
    GPIO(int pin) : pinNumber(pin) {}  // Constructor

    void initialize() {
        std::cout << "Initializing GPIO pin " << pinNumber << std::endl;
    }

    void setHigh() {
        std::cout << "GPIO pin " << pinNumber << " set HIGH" << std::endl;
    }

    void setLow() {
        std::cout << "GPIO pin " << pinNumber << " set LOW" << std::endl;
    }
};

// Derived Class (Child Class)
class LED : public GPIO {
public:
    LED(int pin) : GPIO(pin) {}  // Constructor calling base class constructor

    void turnOn() {
        std::cout << "LED on GPIO pin " << pinNumber << " is turned ON" << std::endl;
        setHigh();  // Use base class method
    }

    void turnOff() {
        std::cout << "LED on GPIO pin " << pinNumber << " is turned OFF" << std::endl;
        setLow();  // Use base class method
    }
};

int main() {
    LED myLED(13);  // Create an LED object on GPIO pin 13
    myLED.initialize();  // Initialize the GPIO
    myLED.turnOn();  // Turn on the LED
    myLED.turnOff(); // Turn off the LED

    return 0;
}

