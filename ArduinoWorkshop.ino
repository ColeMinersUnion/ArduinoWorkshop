//Initializing variables
bool StopLight;  //this will tell us if the stop light is on or off
int SensorVal, ButtonVal;

//Two standard ways of defining pin variables.
#define REDLIGHT 13;
#define YELLOWLIGHT 12;
#define GREENLIGHT 11;
const int Buzzer = 10, Button = 7;

const int PhotoResistorPin = A0;
const int threshold; 

void setup() {
  // put your setup code here, to run once:
  //definitions
  pinMode(REDLIGHT, OUTPUT);  //sets this pin as an output
  pinMode(YELLOWLIGHT, OUTPUT);
  pinMode(GREENLIGHT, OUTPUT);
  //ints
  pinMode(Buzzer, OUTPUT);
  pinMode(Button, INPUT);  //sets ButtonPin as an input

  //defing a threshold value
  threshold = 10; //this will be way to low, I'm expecting like 200/300ish
}

void loop() {
  // put your main code here, to run repeatedly:
  if (state) {
    digitalWrite(REDLIGHT, LOW);
    digitalWrite(YELLOWLIGHT, LOW); //sets the states of the LEDs
    digitalWrite(GREENLIGHT, HIGH);
    //The light is green!
    //check for button press
    ButtonVal = digitalRead(Button);
    if(ButtonVal){
      myFunction();
      state = !state; //switching states
    }

  } else {
    //THe light is red!
    digitalWrite(REDLIGHT, HIGH);
    digitalWrite(YELLOWLIGHT, LOW); //a bit redundant but sets the states of the LEDs
    digitalWrite(GREENLIGHT, LOW);
    //Check for Someone running a redlight
    SensorVal = analogRead(PhotoResistorPin);
    if (SensorVal <= threshold){
      digitalWrite(Buzzer, HIGH);
    } else {
      digitalWrite(Buzzer, LOW);
    }
    //check for button press
    if(ButtonVal){
      state = !state; //switching states
    }
  }
}

void myFunction() {
  //the arduino compiler will automatically generate function prototypes
  digitalWrite(REDLIGHT, LOW);
  digitalWrite(YELLOWLIGHT, HIGH);
  digitalWrite(GREENLIGHT, LOW);
  delay(2000); //this function take an argument in MS, and pauses the execution of the compiler for that amount of time

  digitalWrite(REDLIGHT, HIGH);
  digitalWrite(YELLOWLIGHT, LOW);
}
