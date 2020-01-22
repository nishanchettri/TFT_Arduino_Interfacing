#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include "ACS712.h"

ACS712 sensor(ACS712_30A, A10);

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define BLACK   0x0000
#define BLUE    0x061D
#define RED     0xF800
#define GREEN   0x36CE
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x73AE
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


//Current sensor
float V = 230;
float I;
float P;
void setup() 
{
  
  Serial.begin(9600);
  pinMode(A8,OUTPUT);
  pinMode(A9,OUTPUT);
  digitalWrite(A8,LOW);
  digitalWrite(A9,HIGH);
  sensor.calibrate();
  tft.reset();
  tft.begin(0x9341); // SDFP5408
  tft.setRotation(0);            
  tft.fillScreen(GREY);
  tft.drawRect(0,0,240,320,WHITE);
  
  //HEADING
  //tft.drawRect(10,30, 220,50,WHITE);
  tft.fillRect(10,30, 220,50,GREEN);
  tft.setTextSize(3);
  tft.setCursor(20,45);//X,Y
  tft.println("POWER METER");

  //BOX1
  tft.setTextSize(2);
  tft.fillRect(10, 100, 120, 40,BLUE);
  //tft.drawRect(130, 100, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,115);
  tft.println("VOLTAGE");

  //BOX2
  tft.fillRect(10, 150, 120, 40,BLUE);
  //tft.drawRect(130, 150, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,165);
  tft.println("CURRENT");

  //BOX3
  tft.fillRect(10, 200, 120, 40,BLUE);//(X,Y,XLENGTH,YLENGTH,COLOR) For rect
  //tft.drawRect(130, 200, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,215);
  tft.println("POWER");

}

void loop()
{
  I = sensor.getCurrentAC();
  I=constrain(I,0,50);
  P=V*I;
  P=constrain(P,0,1000);
  tft.setTextSize(2);
  //BOX1
  tft.setTextColor(WHITE);
  tft.setCursor(145, 115);
  tft.println(V);
  //BOX2
  tft.setCursor(145, 165);
  tft.println(I);
  tft.setCursor(145, 215);
  tft.println(P);
  tft.fillRect(130, 150, 100, 40,GREY);
  tft.fillRect(130, 200, 100, 40,GREY);
  
  
}

