#include <FastLED.h>

#define LED_PIN 18     // WS2811のDINを接続したESP32ピン
#define NUM_LEDS 1     // WS2811チップ1個のみ使用

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.show();
  Serial.begin(115200);
  Serial.println("WS2811 motor test start");
}

void loop() {
  // Bを常に点灯状態に（LED点灯用）
  uint8_t blue_level = 100;

  // --- 正転 ---
  leds[0] = CRGB(255, 0, blue_level);  // R=ON, G=OFF, B=ON
  FastLED.show();
  delay(1000);

  // --- 逆転 ---
  leds[0] = CRGB(0, 255, blue_level);  // R=OFF, G=ON, B=ON
  FastLED.show();
  delay(1000);

  // --- 停止 ---
  leds[0] = CRGB(0, 0, blue_level);    // R=OFF, G=OFF, B=ON
  FastLED.show();
  delay(1000);
}
