//  Libraries

#include <SimpleTimer.h>
#include <OneWire.h>

//  print debug messages to serial or not

const boolean SerialDisplay = false;

//  pin assignments

const int photocellPin = A0; //photocell connected to analog 0
const int enableCoopDoorMotorB = 7; //enable motor b - pin 7
const int directionCloseCoopDoorMotorB = 8; //motor b direction close - pin 8
const int directionOpenCoopDoorMotorB = 9; //motor b direction open - pin 9
const int bottomSwitchPin = 26; // bottom hall sensor connected to pin 26
const int topSwitchPin = 27; // top halll sensor on pin 27

//variables

//photocell
int photocellReading; //analog reading of photocell
int photocellReadingLevel; //photocell reading levels(dark, twilight, day)

//reed switches, top and bottom

  //top reed

  int topSwitchPinVal;  //var for reading pin status
  int topSwitchPinVal2; //var for reading the pin debounce/delay status
  int topSwitchState;  //var for to hold the switch state

  //bottom reed

  int bottomSwitchPinVal;
  int bottomSwitchPinVal2;
  int bottomSwitchState;

// SimpleTimer objects
  
  SimpleTimer coopPhotoCellTimer;

//debounce delay
long lastDebounceTime = 0;
long debounceDelay = 100;


void setup() {
  Serial.begin(9600);  //intialize serial port 
  
  //welcome message
  if(SerialDisplay){
    Serial.println(" Processes running:");
    Serial.println(" Timer readPhotoCell every 10 minutes - light levels: open or close door");
  }
  //coop door

  //coop door motor
  pinMode (enableCoopDoorMotorB, OUTPUT);
  pinMode (directionCloseCoopDoorMotorB, OUTPUT);
  pinMode (directionOpenCoopDoorMotorB, OUTPUT);

  //hall switches
  
  //bottom switch
  pinMode(bottomSwitchPin, INPUT);  //switch pin is input
  digitalWrite(bottomSwitchPin, HIGH); //Activate bottom switch resistor

  //top switch
  pinMode(topSwitchPin, INPUT);  //switch pin is input
  digitalWrite(topSwitchPin, HIGH);  //Activate top switch resistor

  //timed actions setup
  coopPhotoCellTimer.setInterval(600000, readPhotoCell);  //read photocell every 10 min
  
}

//operate coop door

void readPhotoCell() {  //function to be called repeatedly - per coopPhotoCellTimer set in setup

  photocellReading = analogRead(photocellPin);
  if(SerialDisplay){
    Serial.print(" Photocell Analog Reading = ");
    Serial.println(photocellReading);
  }

  //  set photocell thresholds
  if (photocellReading >= 0 && photocellReading <= 3) {
    photocellReadingLevel = '1';

    if(SerialDisplay){
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
