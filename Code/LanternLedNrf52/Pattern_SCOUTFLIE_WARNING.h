
/****
 * Pattern file Generated from a Gimp Image file using the Gimp LEDs plug-in.
 * Gimp LEDs Plug-in Download: https://bit.ly/GimpLeds
 * Gimp Download: https://www.gimp.org
 ****/ 
 
#ifndef SCOUTFLIE_WARNING_H
#define SCOUTFLIE_WARNING_H
#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>
#include "GimpLedPattern.h"

#define SCOUTFLIE_WARNING_DELAY 300

#define SCOUTFLIE_WARNING_TOTAL_LEDS 14

namespace NS_SCOUTFLIE_WARNING {

	const uint32_t FRAME_2_5[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
	0x000000, 0x000000, 0xfffc00, 0xfffc00
	};

	const uint32_t FRAME_2_4[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
	0xfffc00, 0xfffc00, 0x000000, 0x000000
	};

	const uint32_t FRAME_2_3[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xfffc00, 0xfffc00, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t FRAME_2_2[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xfffc00, 0xfffc00, 0x000000, 0x000000, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t FRAME_2_1[] PROGMEM = { 
	0x000000, 0x000000, 0x000000, 0x000000, 0xfffc00, 0xfffc00, 0x000000, 0x000000, 0x000000, 0x000000, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t FRAME_2[] PROGMEM = { 
	0x000000, 0x000000, 0xfffc00, 0xfffc00, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t BACKGROUND[] PROGMEM = { 
	0xfffc00, 0xfffc00, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 
	0x000000, 0x000000, 0x000000, 0x000000
	};

	const uint32_t *const SCOUTFLIE_WARNING[] PROGMEM = { 
	FRAME_2_5,
	FRAME_2_4,
	FRAME_2_3,
	FRAME_2_2,
	FRAME_2_1,
	FRAME_2,
	BACKGROUND,
	};

	const uint32_t SCOUTFLIE_WARNING_SIZES[] PROGMEM = { 
	14,
	14,
	14,
	14,
	14,
	14,
	14,
	};

}

using namespace NS_SCOUTFLIE_WARNING;

		
class Pattern_SCOUTFLIE_WARNING : public GimpLedPattern 
{

  public:
    Pattern_SCOUTFLIE_WARNING(Adafruit_NeoPixel& strip): GimpLedPattern(strip){}

    ~Pattern_SCOUTFLIE_WARNING(){}

    void playPattern() 
    {
      int totalFrames = sizeof(SCOUTFLIE_WARNING) / sizeof(uint32_t*);
      for (int framePos = 0; framePos < totalFrames; framePos ++)
      {
        int frameTotalLeds = pgm_read_dword(&(SCOUTFLIE_WARNING_SIZES[framePos]));
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
		  uint32_t * frameAddress = (uint32_t *)pgm_read_dword(&(SCOUTFLIE_WARNING[framePos]));
		  uint32_t ledColor = pgm_read_dword(&(frameAddress[ledPos]));
		  
          int blue = ledColor & 0x00FF;
          int green = (ledColor >> 8) & 0x00FF;
          int red = (ledColor >>  16) & 0x00FF;
          mStrip.setPixelColor(ledPos + ledOffset, red, green, blue);

        }
        mStrip.show();
        delay(SCOUTFLIE_WARNING_DELAY);
      }
    }

    
    void stopPattern() 
    {
      mInterrupt = true;
    }
};
		
#endif //SCOUTFLIE_WARNING_H

