#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL6KwgjYnLg"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"

char auth[] = "PmprDO_1fIzZE3OM1D89TEkU6C-_JMeP";
char ssid[] = "RaphaelWiFi";
char pass[] = "ArduinoESP8266";

const int pirPin = 4;
bool motionDetected = false;

WidgetLCD lcd(V1);

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();

  int pirStatus = digitalRead(pirPin);

  if(pirStatus == HIGH){
    if(!motionDetected){
      motionDetected = true;
      lcd.clear();
      lcd.print(0, 0, "Gerakan Terdeteksi!!");
      } else {
        motionDetected = false;
        }
    }
}
