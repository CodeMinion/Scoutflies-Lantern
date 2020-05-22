

// Note: These steps assume you used the sketch directory as the destination directory when creating the pattern. 
// If you selected a different directory then simply copy the generated files over and into the sketch directory. 

// 1 - Include at the top of Arduino sketch under your other #include statements.
#include <Adafruit_NeoPixel.h>
#include "Pattern_SCOUTFLIE_WARNING.h"

// 2 - Paste on top of setup().
// Note: This assumes you named your pixel strip 'strip' as in the Adafruit sample
// from: https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all#arduino-library-installation
// If you named it differently used that name here instead of 'strip'
#define LED_PIN    7
#define LED_COUNT 14
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
GimpLedPattern * pattern_scoutflie_warning = new Pattern_SCOUTFLIE_WARNING(strip);

// 3 - Paste inside loop() to run the pattern.
pattern_scoutflie_warning->playPattern();  
  
// 4 - Optional: Use this to stop the pattern while it is in the middle of running.
//pattern_scoutflie_warning->stopPattern();


/////////////////////////////////////////////////////////////////////
//// Optionally if you are just starting out with a clean sketch you 
//// may just copy this entire section below and replace the content 
//// of the sketch with it.  
////////////////////////////////////////////////////////////////////
#include <Adafruit_NeoPixel.h>
// 1 - Include at the top of Arduino sketch under your other #include statements.
#include "Pattern_SCOUTFLIE_WARNING.h"

#define LED_PIN    7
#define LED_COUNT 14


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// 2 - Paste on top of setup() and under Adafruit NeoPixel declaration.
// Note: This assumes you named your pixel strip 'strip' as in the Adafruit sample
// from: https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all#arduino-library-installation
// If you named it differently used that name here instead of 'strip'
GimpLedPattern * pattern_scoutflie_warning = new Pattern_SCOUTFLIE_WARNING(strip);

void setup() {
  // put your setup code here, to run once:
  // Setup Neopixels
  // Reduce brigthness 0-255
  strip.setBrightness(4);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:

  // 3 - Paste inside loop() to run the pattern.
  pattern_scoutflie_warning->playPattern();  

  // 4 - Optional: Use this to stop the pattern while it is in the middle of running.
  //pattern_scoutflie_warning->stopPattern();
}

////// END OF SKETCH 



		