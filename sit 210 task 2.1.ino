////const int ledPin = 13; // Built-in LED pin
////
////const char *morseCode = " ..- -.. .- -.--"; // Morse code for "RAKSHIT"
////
////void setup() {
////  pinMode(LED_BUILTIN, OUTPUT);
////}
////
////void loop() {
////  blinkMorseCode(morseCode);
////  delay(3000); // Pause between repetitions
////}
////
////void blinkMorseCode(const char *code) {
////  for (int i = 0; code[i]; i++) {
////    if (code[i] == '.') {
////      digitalWrite(LED_BUILTIN, HIGH);
////      delay(200); // Dot duration
////    } else if (code[i] == '-') {
////      digitalWrite(LED_BUILTIN, HIGH);
////      delay(600); // Dash duration
////    }
////
////    digitalWrite(LED_BUILTIN, LOW);
////    delay(200); // Gap between dots and dashes
////  }
////  delay(800); // Gap between characters
////}
//
//const int buttonPin = 2;  // Pin for the push button
//const int ledPin = LED_BUILTIN;     // Pin for the LED
//
//bool isBlinking = false;
//const char *morseCode = ".-..--.-........-"; // Replace with your Morse code
//
//void setup() {
//  pinMode(buttonPin, INPUT);
//  pinMode(ledPin, OUTPUT);
//}
//
//void loop() {
//  int buttonState = digitalRead(buttonPin);
//
//  if (buttonState == HIGH) {
//    if (!isBlinking) {
//      blinkMorseCode(morseCode);
//      isBlinking = true;
//    }
//  } else {
//    isBlinking = false;
//    digitalWrite(ledPin, LOW);
//  }
//}
//
//void blinkMorseCode(const char *code) {
//
//   for (int i = 0; code[i]; i++) {
//    if (code[i] == '.') {
//      digitalWrite(LED_BUILTIN, HIGH);
//      delay(200); // Dot duration
//    } else if (code[i] == '-') {
//      digitalWrite(LED_BUILTIN, HIGH);
//      delay(600); // Dash duration
//    }
//
//    digitalWrite(LED_BUILTIN, LOW);
//    delay(200); // Gap between dots and dashes
//  }
//  delay(2000); // Gap be
//}


const int ledPin = LED_BUILTIN; // Built-in LED pin
const int buttonPin = 2;       // Push button pin

const long dotDuration = 250;  // Duration of a dot in milliseconds
const long dashDuration = dotDuration * 3; // Duration of a dash

const char morseCode[][7] = {
  
  ".-.",   // R
  ".-",    // A
  "-.-.",  // K
  "...",   // S
  "....",  // H
  "..",    // I
  "-" //T
};

int currentLetter = 0;
bool blinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Button pressed
    if (!blinking) {
      blinking = true;
      blinkName();
    }
    else {
      blinking = false;
      digitalWrite(ledPin, LOW); // Turn off LED
    }
    delay(300); // Debounce delay
  }
}

void blinkName() {
  while (blinking) {
    char letter = morseCode[currentLetter][0];
    if (letter == '\0') {
      currentLetter = 0;
      delay(1000); // Pause between repetitions
    } else {
      for (int i = 1; morseCode[currentLetter][i] != '\0'; i++) {
        digitalWrite(ledPin, HIGH); // Turn on LED
        if (morseCode[currentLetter][i] == '.') {
          delay(dotDuration);
        } else if (morseCode[currentLetter][i] == '-') {
          delay(dashDuration);
        }
        digitalWrite(ledPin, LOW); // Turn off LED
        delay(dotDuration); // Inter-element gap
      }
      delay(dashDuration); // Inter-letter gap
      currentLetter++;
    }
  }
}
