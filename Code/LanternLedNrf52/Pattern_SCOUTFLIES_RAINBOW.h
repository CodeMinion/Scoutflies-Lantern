
/****
 * Pattern file Generated from a Gimp Image file using the Gimp LEDs plug-in.
 * Gimp LEDs Plug-in Download: https://bit.ly/GimpLeds
 * Gimp Download: https://www.gimp.org
 ****/ 
 
#ifndef SCOUTFLIES_RAINBOW_H
#define SCOUTFLIES_RAINBOW_H
#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>
#include "GimpLedPattern.h"

#define SCOUTFLIES_RAINBOW_DELAY 200

#define SCOUTFLIES_RAINBOW_TOTAL_LEDS 14

namespace NS_SCOUTFLIES_RAINBOW {

	const uint32_t FRAME_2_7[] PROGMEM = { 
	0xff9900, 0xff9900, 0xfffc00, 0xfffc00, 0x00ff00, 0x00ff00, 0x0000ff, 0x0000ff, 0x4b0082, 0x4b0082, 
	0x7f00ff, 0x7f00ff, 0xff0000, 0xff0000
	};

	const uint32_t FRAME_2_6[] PROGMEM = { 
	0xfffc00, 0xfffc00, 0x00ff00, 0x00ff00, 0x0000ff, 0x0000ff, 0x4b0082, 0x4b0082, 0x7f00ff, 0x7f00ff, 
	0xff0000, 0xff0000, 0xff9900, 0xff9900
	};

	const uint32_t FRAME_2_5[] PROGMEM = { 
	0x00ff00, 0x00ff00, 0x0000ff, 0x0000ff, 0x4b0082, 0x4b0082, 0x7f00ff, 0x7f00ff, 0xff0000, 0xff0000, 
	0xff9900, 0xff9900, 0xfffc00, 0xfffc00
	};

	const uint32_t FRAME_2_4[] PROGMEM = { 
	0x0000ff, 0x0000ff, 0x4b0082, 0x4b0082, 0x7f00ff, 0x7f00ff, 0xff0000, 0xff0000, 0xff9900, 0xff9900, 
	0xfffc00, 0xfffc00, 0x00ff00, 0x00ff00
	};

	const uint32_t FRAME_2_3[] PROGMEM = { 
	0x4b0082, 0x4b0082, 0x7f00ff, 0x7f00ff, 0xff0000, 0xff0000, 0xff9900, 0xff9900, 0xfffc00, 0xfffc00, 
	0x00ff00, 0x00ff00, 0x0000ff, 0x0000ff
	};

	const uint32_t FRAME_2_2[] PROGMEM = { 
	0x7f00ff, 0x7f00ff, 0xff0000, 0xff0000, 0xff9900, 0xff9900, 0xfffc00, 0xfffc00, 0x00ff00, 0x00ff00, 
	0x0000ff, 0x0000ff, 0x4b0082, 0x4b0082
	};

	const uint32_t FRAME_2_1[] PROGMEM = { 
	0xff0000, 0xff0000, 0xff9900, 0xff9900, 0xfffc00, 0xfffc00, 0x00ff00, 0x00ff00, 0x0000ff, 0x0000ff, 
	0x4b0082, 0x4b0082, 0x7f00ff, 0x7f00ff
	};

	const uint32_t *const SCOUTFLIES_RAINBOW[] PROGMEM = { 
	FRAME_2_7,
	FRAME_2_6,
	FRAME_2_5,
	FRAME_2_4,
	FRAME_2_3,
	FRAME_2_2,
	FRAME_2_1,
	};

	const uint32_t SCOUTFLIES_RAINBOW_SIZES[] PROGMEM = { 
	14,
	14,
	14,
	14,
	14,
	14,
	14,
	};

}

using namespace NS_SCOUTFLIES_RAINBOW;

		
class Pattern_SCOUTFLIES_RAINBOW : public GimpLedPattern 
{

  public:
    Pattern_SCOUTFLIES_RAINBOW(Adafruit_NeoPixel& strip): GimpLedPattern(strip){}

    ~Pattern_SCOUTFLIES_RAINBOW(){}

    void playPattern() 
    {
      int totalFrames = sizeof(SCOUTFLIES_RAINBOW) / sizeof(uint32_t*);
      for (int framePos = 0; framePos < totalFrames; framePos ++)
      {
        int frameTotalLeds = pgm_read_dword(&(SCOUTFLIES_RAINBOW_SIZES[framePos]));
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
		  uint32_t * frameAddress = (uint32_t *)pgm_read_dword(&(SCOUTFLIES_RAINBOW[framePos]));
		  uint32_t ledColor = pgm_read_dword(&(frameAddress[ledPos]));
		  
          int blue = ledColor & 0x00FF;
          int green = (ledColor >> 8) & 0x00FF;
          int red = (ledColor >>  16) & 0x00FF;
          mStrip.setPixelColor(ledPos + ledOffset, red, green, blue);

        }
        mStrip.show();
        delay(SCOUTFLIES_RAINBOW_DELAY);
      }
    }

    
    void stopPattern() 
    {
      mInterrupt = true;
    }
};
		
#endif //SCOUTFLIES_RAINBOW_H

