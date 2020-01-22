#include <SPFD5408_Adafruit_GFX.h>   
#include <SPFD5408_Adafruit_TFTLCD.h> 

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4

//aru data lines pani hunsa so, only with uno/mega easy hunsa nava sahro hunsa.

//color ko hex codes, aru color pani halda hunsa w3schools bata hex codes herera.

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

int x=0;int y=0;int z=0;

void setup() 
{
  
  Serial.begin(9600);
  
  pinMode(A8,OUTPUT);
  pinMode(A9,OUTPUT);
  digitalWrite(A8,LOW);
  digitalWrite(A9,HIGH);
  
  tft.reset();
  tft.begin(0x9341); // SDFP5408
  tft.setRotation(0);  //yaha 0 nava 1 halera lcd ko orientation change garda hunsa          
  tft.fillScreen(GREY);
  tft.drawRect(0,0,240,320,WHITE);
  
  //HEADING 
  //tft.drawRect(10,30, 220,50,WHITE);
  tft.fillRect(10,30, 220,50,GREEN);
  tft.setTextSize(3);
  tft.setCursor(20,45);//X,Y
  tft.println("Heading");

   //BOX1 ko lagi base graphics
  tft.setTextSize(2);
  tft.fillRect(10, 100, 120, 40,BLUE);
  //tft.drawRect(130, 100, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,115);
  tft.println("x");

   //BOX2 ko lagi base graphics
  tft.fillRect(10, 150, 120, 40,BLUE);
  //tft.drawRect(130, 150, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,165);
  tft.println("y");

  //BOX3 ko lagi base graphics
  tft.fillRect(10, 200, 120, 40,BLUE);//(X,Y,XLENGTH,YLENGTH,COLOR) For rect
  //tft.drawRect(130, 200, 100, 40,WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(30,215);
  tft.println("z");

}

void loop()
{
  /*I = sensor.getCurrentAC();
  I=constrain(I,0,50);
  P=V*I;
  P=constrain(P,0,1000);
  */
  tft.setTextSize(2);
  //BOX1
  tft.setTextColor(WHITE);
  tft.setCursor(145, 115);
  tft.println(x); // j pani realtime show garnu cha yaha halnu
  //BOX2
  tft.setCursor(145, 165);
  tft.println(y);  //j pani realtime show garnu cha yaha halnu
  tft.setCursor(145, 215);
  tft.println(z); //j pani realtime show garnu cha yaha halnu
  tft.fillRect(130, 150, 100, 40,GREY);
  tft.fillRect(130, 200, 100, 40,GREY);
  x++;y++;z++;
  
}

