/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 8 Sep 2016
  by Colby Newman
*/
float x = -8888;
int fan = 8;
int ledPin = 7;

void ledOn () {
  digitalWrite(ledPin, HIGH);
  delay (100);
  digitalWrite(ledPin, LOW);
  delay (100);
  }

void powerOn () {
  digitalWrite(fan, HIGH);
}

void powerOff () {
  digitalWrite(fan, LOW);
  digitalWrite(ledPin, LOW);
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200); // bit per second
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(fan, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

String serialHttpGet(String url) {
  Serial.print("GET ");
  Serial.println(url);
  return Serial.readStringUntil('\n');
}

float serialHttpGetFloat(String url) {
  String s = serialHttpGet(url);
  return s.toFloat();
}

// the loop function runs over and over again forever
void loop() {
  x = serialHttpGetFloat("http://one.api.botbook.com/last/JCaA7Sysv91");
  if (x > 3) {
    powerOn();
      while (x > 3){
        ledOn();
  }
  }

  else {
    powerOff();
  }
  delay(500); // milliseconds
}
