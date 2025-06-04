#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Reset pin not used with I2C
#define OLED_RESET    -1

// Create display object (for I2C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Wire.begin(21, 22); // SDA, SCL

  // Initialize with the I2C address of your display (usually 0x3C)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();

  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE);  
  display.setCursor(0, 0);     
  display.println("Hello, ESP32!");
  display.display();           
}

void loop() {
  // Nothing here for now
}
