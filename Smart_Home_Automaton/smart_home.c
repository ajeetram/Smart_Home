// Voice based home automation

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "L76bSPqJ2T4OTSqH47gWjHVT8mHuv9PG";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "realme3pro";
char pass[] = "12345678";
const int SENSOR_PIN = D5;
const int RELAY_PIN = D6;
int flag=0;

BLYNK_WRITE(V2)
{ int pinValue = param.asInt();
  digitalWrite(D1,pinValue); 
 }
BLYNK_WRITE(V3)
{ int pinValue = param.asInt();
  digitalWrite(D0,pinValue); 
 }

 
void notifyOnButtonPress()
{
  int isButtonPressed = digitalRead(D7);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Someone Opened the door");
    Blynk.notify("Alert : Someone Opened the door");
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
}

void setup()
{
  // Debug console
  
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(SENSOR_PIN,INPUT);
  pinMode(D7,INPUT_PULLUP);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(16000L,notifyOnButtonPress); 
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  timer.run();

  int motion  = digitalRead(SENSOR_PIN);

  if (motion == 1)
  { digitalWrite(RELAY_PIN,LOW);
  }
  else
  {digitalWrite(RELAY_PIN,HIGH);
   }
 
}
