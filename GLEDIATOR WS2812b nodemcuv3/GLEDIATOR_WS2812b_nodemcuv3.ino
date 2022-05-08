// Glediator Arduino UNO sketch by Jens Andrée / https://politisktinkorrektpappa.wordpress.com/
// changed for a nodemcu v3 without SD by Werner Kallas
// 1000000 bauds with 768 pixels no problem
// colororder in Jinx! = RGB ! not GRB !
 
#include <FastLED.h>
#define NUM_LEDS 768 // LED number
#define DATA_PIN D1    // your data pin
#define CMD_NEW_DATA 1
#define BAUD_RATE 1000000  
CRGB leds[NUM_LEDS];
 
void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); 
  Serial.begin(BAUD_RATE); 
 
  for(int y = 0 ; y < NUM_LEDS ; y++)
  {
    leds[y] = CRGB::Black; 
  }
  FastLED.show();
}
 
int serialGlediator ()
{
  return Serial.read();
}
void loop()
{
while (serialGlediator () != CMD_NEW_DATA) {}
Serial.readBytes((char*)leds, NUM_LEDS*3);
 
     FastLED.show();
 
}
