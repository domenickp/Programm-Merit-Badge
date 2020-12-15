// Constants are defined here.  They do not change.
const int redLedPin    = 3;
const int blueLedPin   = 4;
const int whiteLedPin  = 6;
const int orangeLedPin = 5;
const int internalLed  = 13;
const int button1Pin   = 1;
const int button2Pin   = 2;
const int msDelay      = 1000;

// Variables are declared here.  Their values to change.
int button1State = 0;
int button2State = 0;

void setup() {
  // Initialize the pins we're going to use into the correct mode (input or output)
  pinMode(redLedPin,    OUTPUT);
  pinMode(blueLedPin,   OUTPUT);
  pinMode(whiteLedPin,  OUTPUT);
  pinMode(orangeLedPin, OUTPUT);
  pinMode(internalLed,  OUTPUT);
  pinMode(button1Pin,   INPUT);
  pinMode(button2Pin,   INPUT);
}

void loop()
{
  // read the state of the pushbutton value
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  // check if pushbutton #1 is pressed.  if it is, the
  // button1State is HIGH
  if (button1State == HIGH) {
    // turn LEDs on
    digitalWrite(internalLed, HIGH);
    digitalWrite(redLedPin,   HIGH);
    digitalWrite(blueLedPin,  HIGH);
  } else if (button1State == LOW) {
    // if the state it LOW, turn LEDs off
    digitalWrite(internalLed, LOW);
    digitalWrite(redLedPin,   LOW);
    digitalWrite(blueLedPin,  LOW);
  }
  
  switch (button2State) {
  case HIGH:
    digitalWrite(orangeLedPin, HIGH);
    digitalWrite(whiteLedPin,  HIGH);
    break;
  case LOW:
    digitalWrite(orangeLedPin, LOW);
    digitalWrite(whiteLedPin,  LOW);
    break;
  default:
    digitalWrite(orangeLedPin, LOW);
    digitalWrite(whiteLedPin,  LOW);
    break;
  }
  
  delay(msDelay); // Delay a little bit to improve simulation performance
}
