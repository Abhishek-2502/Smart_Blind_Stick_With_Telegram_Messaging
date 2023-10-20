#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


const char* ssid = "Galaxy";
const char* password = "prem3562951413";


#define BOTtoken "5849425913:AAFqswlMBhVxvxLoKkiqCpW6XGH6PbsHjhg"
#define CHAT_ID "1093493235"


X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int button = 5;
const int trigPin = 13;
const int echoPin = 12;
const int buzzer = 1;
const int motorPin = 3;
long duration;
int distance;
int safetyDistance;

void setup() {
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int a = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    a++;
  }

  pinMode(button, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motorPin, OUTPUT);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Wifi Connected!", "");
  bot.sendMessage(CHAT_ID, "System has Started!!", "");
}
void loop() {

  int state = digitalRead(button);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  safetyDistance = distance;

  if (state == 0) {
    bot.sendMessage(CHAT_ID, "Blind Stick Emergency Detected!", "");
  }

  if (safetyDistance <= 10) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(motorPin, LOW);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}