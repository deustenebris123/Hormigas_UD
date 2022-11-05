

#include <LiquidCrystal.h>
int rs = 2;
int e = 3;
int d4 = 4;
int d5 = 5;

int dTime = 500;
//LCD
int d6 = 6;
int d7 = 7;
int numero = 0;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//DHT11

#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 8;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;

const int ideal=9;
const int noIdeal=10;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  HT.begin();
  pinMode(ideal,OUTPUT);
  pinMode(noIdeal,OUTPUT);
 
  
}

void loop() {
 
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  //tempF = HT.readTemperature(true);
  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");


  while(tempC>45){
    digitalWrite(ideal,LOW);
    digitalWrite(noIdeal,HIGH);
    tempC = HT.readTemperature();
    //tempF = HT.readTemperature(true);
    Serial.print("Humedad Relativa: ");
    Serial.print(humidity);
    Serial.print("% / Temperatura: ");
    Serial.print(tempC);
    Serial.print("ºC / ");
    Serial.print(tempF);
    Serial.println("ºF");
  }
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");

  delay(dTime);
  lcd.clear();
}