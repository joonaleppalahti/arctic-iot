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

void setup() {
  Serial.begin(115200);
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
  delay(500);
}
