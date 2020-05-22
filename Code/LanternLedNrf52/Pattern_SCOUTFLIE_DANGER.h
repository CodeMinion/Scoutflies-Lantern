
/****
 * Pattern file Generated from a Gimp Image file using the Gimp LEDs plug-in.
 * Gimp LEDs Plug-in Download: https://bit.ly/GimpLeds
 * Gimp Download: https://www.gimp.org
 ****/ 
 
#ifndef SCOUTFLIE_DANGER_H
#define SCOUTFLIE_DANGER_H
#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>
#include "GimpLedPattern.h"

#define SCOUTFLIE_DANGER_DELAY 150

#define SCOUTFLIE_DANGER_TOTAL_LEDS 14

namespace NS_SCOUTFLIE_DANGER {

	const uint32_t FRAME_2_2[] PROGMEM = { 
	0x000000, 0x660000, 0xcc0000, 0xff0000, 0xcc0000, 0x660000, 0x000000, 0x000000, 0x000000, 0x660000, 
	0xcc0000, 0xff0000, 0xcc0000, 0x660000
	};

	const uint32_t MIDDLE[] PROGMEM = { 
	0x000000, 0x400000, 0x800000, 0xff0000, 0x800000, 0x400000, 0x000000, 0x400000, 0x000000, 0x400000, 
	0x800000, 0xff0000, 0x800000, 0x400000
	};

	const uint32_t FRAME_2[] PROGMEM = { 
	0x000000, 0x000000, 0x400000, 0x800000, 0x400000, 0x000000, 0x400000, 0x800000, 0x400000, 0x000000, 
	0x400000, 0x800000, 0x400000, 0x000000
	};

	const uint32_t FRAME_0[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x400000, 0x000000, 0x400000, 0x800000, 0xff0000, 0x800000, 0x400000, 
	0x000000, 0x400000, 0x000000, 0x000000
	};

	const uint32_t FRAME_2_1[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x660000, 0xcc0000, 0xff0000, 0xcc0000, 0x660000, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t *const SCOUTFLIE_DANGER[] PROGMEM = { 
	FRAME_2_2,
	MIDDLE,
	FRAME_2,
	FRAME_0,
	FRAME_2_1,
	};

	const uint32_t SCOUTFLIE_DANGER_SIZES[] PROGMEM = { 
	14,
	14,
	14,
	14,
	14,
	};

}

using namespace NS_SCOUTFLIE_DANGER;

		
class Pattern_SCOUTFLIE_DANGER : public GimpLedPattern 
{

  public:
    Pattern_SCOUTFLIE_DANGER(Adafruit_NeoPixel& strip): GimpLedPattern(strip){}

    ~Pattern_SCOUTFLIE_DANGER(){}

    void playPattern() 
    {
      int totalFrames = sizeof(SCOUTFLIE_DANGER) / sizeof(uint32_t*);
      for (int framePos = 0; framePos < totalFrames; framePos ++)
      {
        int frameTotalLeds = pgm_read_dword(&(SCOUTFLIE_DANGER_SIZES[framePos]));
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
		  uint32_t * frameAddress = (uint32_t *)pgm_read_dword(&(SCOUTFLIE_DANGER[framePos]));
		  uint32_t ledColor = pgm_read_dword(&(frameAddress[ledPos]));
		  
          int blue = ledColor & 0x00FF;
          int green = (ledColor >> 8) & 0x00FF;
          int red = (ledColor >>  16) & 0x00FF;
          mStrip.setPixelColor(ledPos + ledOffset, red, green, blue);

        }
        mStrip.show();
        delay(SCOUTFLIE_DANGER_DELAY);
      }
    }

    
    void stopPattern() 
    {
      mInterrupt = true;
    }
};
		
#endif //SCOUTFLIE_DANGER_H

