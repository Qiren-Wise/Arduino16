#include "FastLED.h"

FASTLED_USING_NAMESPACE

//#if defined(FASTLED_VERSION) && (FASTLED_VERSION<3001000)fine
//#waring "Requires FastLED 3.1 or later;check gihub for latest code"
//#endif

#define DATA_PIN  3
#define LED_TYPE  WS2811    //led灯带型号
#define COLOR_ORDER GRB
#define NUM_LEDS  64   //灯珠
//CRGB leds[NUM_LEDS];

 #define BRIGHTNESS         96
 #define FRAMES_PER_SECOND  120
 #define COLOR_ORDER GRB

 uint8_t max_bright = 128;

 CRGB leds[NUM_LEDS];  //建立光带leds

 CRGB myRGBcolor(50,0,50);  //(rValue,gValue,bValue)  0-255

 //CHSV myHSVcolor(80,255,200);//HSV方法定义颜色 ，（色调，饱和度，明亮）

 void setup()
 {
   Serial.begin(9600);
   delay(1000);

   LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);//初始化光带
   FastLED.setBrightness(max_bright);                        //设置宽带亮度  
  }



void loop() {
  // put your main code here, to run repeatedly:
  myRGBcolor.r = 0;  //rValue=0
  myRGBcolor.b = 0;  //bValue=0
  fill_solid(leds,NUM_LEDS,myRGBcolor);
  FastLED.show();
  delay(500);

  myRGBcolor.r = 50;  //rValue=50
  myRGBcolor.b = 50;  //bValue=50
  fill_solid(leds,NUM_LEDS,myRGBcolor);
  FastLED.show();
  delay(500);
}
