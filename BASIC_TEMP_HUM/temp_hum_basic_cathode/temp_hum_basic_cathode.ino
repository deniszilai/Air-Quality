#include "DHT.h"
#define DHT11_PIN A0    
#define DHTTYPE DHT11   
DHT dht(DHT11_PIN, DHTTYPE);

const int ledGreen = A2;
const int ledYellow = A3;
const int ledPin = A1;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

const int touchPin = 13;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 12;
int f = 7;
int g = 8;

int GND1 = 6;
int GND2 = 11;
int GND3 = 10;
int GND4 = 9;

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

int Temp;
int Humi;

void setup()
{
  dht.begin();
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  pinMode(touchPin, INPUT);
}

void loop()
{
  Temp = dht.readTemperature();
  Humi = dht.readHumidity();
  
  digitalWrite(ledGreen, HIGH);

  while (Temp >= 24) {
    Cald();

    digitalWrite(ledGreen, LOW);
    //led
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
    }

    //touch sensor
    if (digitalRead(touchPin) == HIGH) {
      Pause();
    }
    digitalWrite(ledYellow, LOW);
    Temp = dht.readTemperature();
  }

  ledState = LOW;
  
  while (Humi >= 80) {
    Humid();

    digitalWrite(ledGreen, LOW);
    //led
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
    }

    //touch sensor
    if (digitalRead(touchPin) == HIGH) {
      Pause();
    }
    digitalWrite(ledYellow, LOW);
    Humi = dht.readHumidity();
  }
  ledState = LOW;  
  
  Temp = dht.readTemperature();
  for (int i = 1; i <= 500; i++) {
    dig1 = Temp / 10;
    dig2 = Temp - (dig1 * 10);
    dig3 = 10;
    dig4 = 11;

    digitalWrite( GND4, LOW);    //digit 4
    DisplayNumber(dig4);
    delay(4);
    digitalWrite( GND4, HIGH);

    digitalWrite( GND3, LOW);    //digit 3
    DisplayNumber(dig3);
    delay(4);
    digitalWrite( GND3, HIGH);

    digitalWrite( GND2, LOW);   //digit 2
    DisplayNumber(dig2);
    delay(4);
    digitalWrite( GND2, HIGH);

    digitalWrite( GND1, LOW);   //digit 1
    DisplayNumber(dig1);
    delay(4);
    digitalWrite( GND1, HIGH);
  }

  Humi = dht.readHumidity();
  for (int i = 1; i <= 500; i++) {
    dig1 = Humi / 10;
    dig2 = Humi - (dig1 * 10);
    dig3 =  12;
    dig4 = 12;

    digitalWrite( GND4, LOW);    //digit 4
    DisplayNumber(dig4);
    delay(4);
    digitalWrite( GND4, HIGH);

    digitalWrite( GND3, LOW);    //digit 3
    DisplayNumber(dig3);
    delay(4);
    digitalWrite( GND3, HIGH);

    digitalWrite( GND2, LOW);   //digit 2
    DisplayNumber(dig2);
    delay(4);
    digitalWrite( GND2, HIGH);

    digitalWrite( GND1, LOW);   //digit 1
    DisplayNumber(dig1);
    delay(4);
    digitalWrite( GND1, HIGH);
  }
}

void Cald() {
  dig1 = 11;
  dig2 = 13;
  dig3 = 14;
  dig4 = 15;

  digitalWrite( GND4, LOW);    //digit 4
  DisplayNumber(dig4);
  delay(4);
  digitalWrite( GND4, HIGH);

  digitalWrite( GND3, LOW);    //digit 3
  DisplayNumber(dig3);
  delay(4);
  digitalWrite( GND3, HIGH);

  digitalWrite( GND2, LOW);   //digit 2
  DisplayNumber(dig2);
  delay(4);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND1, LOW);   //digit 1
  DisplayNumber(dig1);
  delay(4);
  digitalWrite( GND1, HIGH);
}

void Humid() {
  dig1 = 16;
  dig2 = 17;

  digitalWrite( GND2, LOW);   //digit 2
  DisplayNumber(dig2);
  delay(4);
  digitalWrite( GND2, HIGH);

  digitalWrite( GND1, LOW);   //digit 1
  DisplayNumber(dig1);
  delay(4);
  digitalWrite( GND1, HIGH);
}

void Pause() {
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
}

void DisplayNumber(int x) {
  switch (x) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 10: o(); break;
    case 11: C(); break;
    case 12: oo(); break;
    case 13: A(); break;
    case 14: L(); break;
    case 15: dd(); break;
    case 16: hh(); break;
    case 17: uu(); break;
  }
}

void zero()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void one()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void two()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void three()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void four()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void five()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void six()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void seven()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void eight()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void nine()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}
void o()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void C()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void oo()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void A()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}
void L()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void dd()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void hh()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void uu()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}
