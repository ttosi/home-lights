// #include <FastLED.h>

// #define NUM_LEDS 150
// #define DATA_PIN 6
// #define LED_PIN D5
// #define BUTTON_PIN 7

// bool buttonState = false;
// bool ledState = false;
// int currentColor = 0;

// CRGB color[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
// CRGB leds[NUM_LEDS];

// void fadeall()
// {
// 	for (int i = 0; i < NUM_LEDS; i++)
// 	{
// 		leds[i].nscale8(250);
// 	}
// }

// void setup()
// {
// 	// pinMode(LED_PIN, OUTPUT);
// 	// digitalWrite(LED_PIN, LOW);
// 	// delay(1000);
// 	// pinMode(BUTTON_PIN, INPUT);
// 	// button.setup(BUTTON_PIN);

// 	//FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
// 	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
// 	// FastLED.setBrightness(255);
// 	// LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
// 	// FastLED.setBrightness(BRIGHTNESS);
// }

// void loop()
// {
// 	// leds[40] = CRGB::Red;
// 	// fill_solid(leds, NUM_LEDS, CRGB::Blue);
// 	// FastLED.show();

// 	static uint8_t hue = 0;
// 	// First slide the led in one direction
// 	for (int i = 0; i < NUM_LEDS; i++)
// 	{
// 		// Set the i'th led to red
// 		leds[i] = CHSV(hue++, 255, 255);
// 		// Show the leds
// 		FastLED.show();
// 		// now that we've shown the leds, reset the i'th led to black
// 		// leds[i] = CRGB::Black;
// 		fadeall();
// 		// Wait a little bit before we loop around and do it again
// 		delay(10);
// 	}

// 	// Now go in the other direction.
// 	for (int i = (NUM_LEDS)-1; i >= 0; i--)
// 	{
// 		// Set the i'th led to red
// 		leds[i] = CHSV(hue++, 255, 255);
// 		// Show the leds
// 		FastLED.show();
// 		// now that we've shown the leds, reset the i'th led to black
// 		// leds[i] = CRGB::Black;
// 		fadeall();
// 		// Wait a little bit before we loop around and do it again
// 		delay(10);
// 	}

// 	// if (digitalRead(BUTTON_PIN))
// 	// {
// 	// 	ledState = !ledState;
// 	// 	digitalWrite(LED_PIN, ledState);
// 	// }

// 	// delay(30);

// 	// fill_solid(leds, NUM_LEDS, CRGB::Red);

// 	// int pos = beatsin16(5, 0, 192);					  // generating the sinwave
// 	// fill_solid(leds, NUM_LEDS, CHSV(gHue, 255, pos)); // CHSV (hue, saturation, value);
// 	// FastLED.show();
// 	// EVERY_N_MILLISECONDS(100) { gHue++; }

// 	// for (int dot = 0; dot < NUM_LEDS; dot++)
// 	// {
// 	// 	leds[dot] = CRGB::Blue;
// 	// 	FastLED.show();
// 	// 	// clear this led for the next time around the loop
// 	// 	leds[dot] = CRGB::Black;
// 	// 	delay(30);
// 	// }

// 	// digitalWrite(LED_PIN, HIGH);
// 	// delay(500);

// 	// digitalWrite(LED_PIN, LOW);
// 	// delay(500);
// }
