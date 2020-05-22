
/****
 * Pattern file Generated from a Gimp Image file using the Gimp LEDs plug-in.
 * Gimp LEDs Plug-in Download: https://bit.ly/GimpLeds
 * Gimp Download: https://www.gimp.org
 ****/ 
 
#ifndef SCOUTFLIE_NORMAL_H
#define SCOUTFLIE_NORMAL_H
#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>
#include "GimpLedPattern.h"

#define SCOUTFLIE_NORMAL_DELAY 300

#define SCOUTFLIE_NORMAL_TOTAL_LEDS 14

namespace NS_SCOUTFLIE_NORMAL {

	const uint32_t FRAME_2_2[] PROGMEM = { 
	0x000000, 0x006300, 0x00c700, 0x00f900, 0x00c700, 0x006300, 0x000000, 0x000000, 0x000000, 0x006300, 
	0x00c700, 0x00f900, 0x00c700, 0x006300
	};

	const uint32_t MIDDLE[] PROGMEM = { 
	0x000000, 0x003e00, 0x007c00, 0x00f900, 0x007c00, 0x003e00, 0x000000, 0x003e00, 0x000000, 0x003e00, 
	0x007c00, 0x00f900, 0x007c00, 0x003e00
	};

	const uint32_t FRAME_2[] PROGMEM = { 
	0x000000, 0x000000, 0x003e00, 0x007c00, 0x003e00, 0x000000, 0x003e00, 0x007c00, 0x003e00, 0x000000, 
	0x003e00, 0x007c00, 0x003e00, 0x000000
	};

	const uint32_t FRAME_0[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x003e00, 0x000000, 0x003e00, 0x007c00, 0x00f900, 0x007c00, 0x003e00, 
	0x000000, 0x003e00, 0x000000, 0x000000
	};

	const uint32_t FRAME_2_1[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x006300, 0x00c700, 0x00f900, 0x00c700, 0x006300, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t *const SCOUTFLIE_NORMAL[] PROGMEM = { 
	FRAME_2_2,
	MIDDLE,
	FRAME_2,
	FRAME_0,
	FRAME_2_1,
	};

	const uint32_t SCOUTFLIE_NORMAL_SIZES[] PROGMEM = { 
	14,
	14,
	14,
	14,
	14,
	};

}

using namespace NS_SCOUTFLIE_NORMAL;

		
class Pattern_SCOUTFLIE_NORMAL : public GimpLedPattern 
{

  public:
    Pattern_SCOUTFLIE_NORMAL(Adafruit_NeoPixel& strip): GimpLedPattern(strip){}

    ~Pattern_SCOUTFLIE_NORMAL(){}

    void playPattern() 
    {
      int totalFrames = sizeof(SCOUTFLIE_NORMAL) / sizeof(uint32_t*);
      for (int framePos = 0; framePos < totalFrames; framePos ++)
      {
        int frameTotalLeds = pgm_read_dword(&(SCOUTFLIE_NORMAL_SIZES[framePos]));
		int ledOffset = 0;
        for (int ledPos = 0; ledPos < frameTotalLeds; ledPos++)
        {
          if(mInterrupt)
          {
            // If we are interrupted stop the pattern. "Clean" LED pattern.
            mStrip.clear();
            mStrip.show();
            mInterrupt = false;
            return;
          }
		  uint32_t * frameAddress = (uint32_t *)pgm_read_dword(&(SCOUTFLIE_NORMAL[framePos]));
		  uint32_t ledColor = pgm_read_dword(&(frameAddress[ledPos]));
		  
          int blue = ledColor & 0x00FF;
          int green = (ledColor >> 8) & 0x00FF;
          int red = (ledColor >>  16) & 0x00FF;
          mStrip.setPixelColor(ledPos + ledOffset, red, green, blue);

        }
        mStrip.show();
        delay(SCOUTFLIE_NORMAL_DELAY);
      }
    }

    
    void stopPattern() 
    {
      mInterrupt = true;
    }
};
		
#endif //SCOUTFLIE_NORMAL_H

