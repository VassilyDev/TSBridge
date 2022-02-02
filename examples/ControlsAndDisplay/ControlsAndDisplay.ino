/*  TSBridge library by Alessandro Felicetti http://https://felicetti-a.eu/
   GitHub source code and documentation https://github.com/VassilyDev/TSBridge
*/

#include <TSBridge.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
LiquidCrystal_I2C lcd(0x27, 20, 4);
int interval = 750;

TSBridge bridge;

int io_startup = 2;
int io_pantograph = 3;
int reverserBW = 4;
int reverserFW = 5;
int io_lights = 6;
int io_horn = 7;
int io_emergency = 8;
int io_sand = 9;
int io_wipers = 10;
int io_doors = 11;
int io_vigi_aws = 12;
int io_throttle = A0;
int io_brake = A1;


void setup() {
  // Inputs and outputs configuration
  pinMode(io_startup, INPUT_PULLUP);
  pinMode(io_pantograph, INPUT_PULLUP);
  pinMode(reverserFW, INPUT_PULLUP);
  pinMode(reverserBW, INPUT_PULLUP);
  pinMode(io_lights, INPUT_PULLUP);
  pinMode(io_horn, INPUT_PULLUP);
  pinMode(io_emergency, INPUT_PULLUP);
  pinMode(io_sand, INPUT_PULLUP);
  pinMode(io_wipers, INPUT_PULLUP);
  pinMode(io_vigi_aws, INPUT_PULLUP);
  pinMode(io_doors, INPUT_PULLUP);

  // Serial port configuration
  Serial.begin(115200);
  bridge.begin(&Serial);

  // Display setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("READY");
}


void loop() {
  bridge.run();
  // Various inputs
  bridge.startup = (float)!digitalRead(io_startup);
  bridge.pantograph = (float)!digitalRead(io_pantograph);
  bridge.horn = (float)!digitalRead(io_horn);
  bridge.emergency = (float)!digitalRead(io_emergency);
  bridge.sander = (float)!digitalRead(io_sand);
  bridge.wipers = (float)!digitalRead(io_wipers);
  bridge.vigilReset = (float)!digitalRead(io_vigi_aws);
  bridge.AWSReset = (float)!digitalRead(io_vigi_aws);
  // Reverser
  if(digitalRead(reverserFW) == LOW){
    bridge.reverser = 1.0;
  }
  if(digitalRead(reverserBW) == LOW){
    bridge.reverser = -1.0;
  }
  if((digitalRead(reverserFW) == HIGH)&&(digitalRead(reverserBW) == HIGH)){
    bridge.reverser = 0.0;
  }
  // Doors
  if (digitalRead(io_doors) == LOW) {
    bridge.doorRight = 1.0;
    bridge.doorLeft = 1.0;
  }
  if (digitalRead(io_doors) == HIGH) {
    bridge.doorRight = 0.0;
    bridge.doorLeft = 1.0;
  }

  // Throttle and brake
  int temp = analogRead(io_throttle);
  bridge.throttle = (float)map(temp, 0, 1024, 0, 1000);
  temp = analogRead(io_brake);
  bridge.brake = (float)map(temp, 0, 1024, 0, 1000);

  // Lights
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(!digitalRead(io_lights)){
      if(bridge.lights == 0){
        bridge.lights = 1;
      }else if(bridge.lights == 1){
        bridge.lights = 2;
      }else if(bridge.lights == 2){
        bridge.lights = 0;
      }
    }
    lcd.clear();
    lcd.print(bridge.kph, 2);
    lcd.print(" KPH");
    lcd.setCursor(0, 1);
    lcd.print(bridge.ammeter, 2);
    lcd.print(" Amp");
  }
  delay(10);
}
