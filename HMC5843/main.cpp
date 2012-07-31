/*
 -------------------------------------------------------------------------------
 main.cpp
 HMC5843 Project
 
 This is test code for the HMC5843 class. HMC5843 uses I2C. 
 Pins:
    VCC to 3.3V
    GND to ground
    SDA to pin 4
    SCL on pin 5
 
 Initially created by Rowland O'Flaherty on 1/13/12.
 
 Version 1.0
 -------------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
// Includes and Defines
//------------------------------------------------------------------------------
#include <Arduino.h>
#include <HMC5843.h>


//------------------------------------------------------------------------------
// Helper Function Declarations
//------------------------------------------------------------------------------
void readData();

//------------------------------------------------------------------------------
// Global Varible Declarations
//------------------------------------------------------------------------------
HMC5843 hmc;

//------------------------------------------------------------------------------
// Setup Function - Initializes Arduino
//------------------------------------------------------------------------------
void setup() {
	pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.println("");
    
    // Initialize device
    hmc.initialize();
    
    // Get & Set Mode
    Serial.print("Default Mode: ");
    Serial.println(hmc.getMode(),1);
    
    hmc.setMode((HMC5843::Mode)(0));
    Serial.print("Current Mode: ");
    Serial.println(hmc.getMode(),1);
    
    // Get & Set Sampling Time
    Serial.print("Default Sampling Time: ");
    Serial.print(hmc.getSamplingRate(),1);
    Serial.println("Hz");
    
    hmc.setSamplingRate(3);
    Serial.print("Current Sampling Time: ");
    Serial.print(hmc.getSamplingRate(),1);
    Serial.println("Hz");
    
    Serial.println("");
    
    // Get & Set Gain
    Serial.print("Default Gain: ");
    Serial.print(hmc.getGain(),1);
    Serial.println("Ga");
    
    hmc.setGain(0);
    Serial.print("Current Gain: ");
    Serial.print(hmc.getGain(),1);
    Serial.println("Ga");
    
    Serial.println("");
    
    Serial.println("X, Y, Z, Heading");
    
    readData();
}

//------------------------------------------------------------------------------
// Loop Function - Arduino Program Loop
//------------------------------------------------------------------------------
void loop() {
    readData(); 
}

//------------------------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------------------------
void readData() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    
    int x, y, z;
    //hmc.normalized(x, y, z);
    hmc.raw( x, y, z);
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.print(", ");
    Serial.print(hmc.heading());
    Serial.print("\n");
    
    
}
