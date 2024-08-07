/*

 * Program to measure gas in ppm using MQ sensor

 * Program by: Harish K.R and Vimal

 * Dated: 27-04-2023

 */
#include<Arduino.h>

#define RL 47  //The value of resistor RL is 47K

#define m -0.263 //Enter calculated Slope 

#define b 0.42 //Enter calculated intercept

#define Ro 20 //Enter found Ro value

#define MQ_sensor A0 //Sensor is connected to A4

#include <LiquidCrystal.h> //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal

const int rs = 8, e = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2); //We are using a 16*2 LCD display

  lcd.print("NH3 in PPM"); //Display a intro message

  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1

   delay(2000); //Wait for display to show info

   lcd.clear(); //Then clean it
   Serial.begin(9600);

}

void loop() {
  
  float VRL; //Voltage drop across the MQ sensor

  float Rs; //Sensor resistance at gas concentration 

  float ratio; //Define variable for ratio

   

  VRL = analogRead(MQ_sensor)*(5.0/1023.0); //Measure the voltage drop and convert to 0-5V

  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value

  ratio = Rs/Ro;  // find ratio Rs/Ro

 

  float ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm
  
  Serial.println(ppm);

  lcd.print("NH3 (ppm) = "); //Display a ammonia in ppm

  lcd.print(ppm);

  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1

  lcd.print("Voltage = "); //Display a intro message 

  lcd.print(VRL);

   delay(200);

   lcd.clear(); //Then clean it

}


