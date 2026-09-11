/*#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_SDA 5
#define OLED_SCL 4
#define OLED_RST 16

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);

void setup() {
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }
}

void loop() {
  display.clearDisplay();   
  display.setTextSize(2);      
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("Screen      test"); 
  display.display();          
  delay(1000);   
}
*/

#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_SDA 5
#define OLED_SCL 4
#define OLED_RST 16
#define Button_Pin 5

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);

void setup() {
  pinMode(Button_Pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(Button_Pin), printButtonInterrupt, RISING);

  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }
}

void loop() {
  digitalWrite(Button_Pin, HIGH);
  display.clearDisplay();   
  display.setTextSize(2);      
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("sreen test?"); 
  display.display();
}

void printButtonInterrupt(){
  display.clearDisplay();   
  display.setTextSize(2);      
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("Interrupt!"); 
  display.display();      
  delay(3000);     
}