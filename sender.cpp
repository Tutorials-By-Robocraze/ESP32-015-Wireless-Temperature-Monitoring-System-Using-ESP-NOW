#include <ESP8266WiFi.h>
#include <espnow.h>
#include <DHT.h>

#define DHTPIN D3
#define DHTTYPE DHT11
#define BUZZER D2

uint8_t rxMac[] = {0x24, 0xD7, 0xEB, 0xFB, 0xA7, 0x31};

DHT dht(DHTPIN, DHTTYPE);

typedef struct SensorData {
  float temperature;
  float humidity;
} SensorData;

SensorData data;

void OnSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Delivery Status: ");
  Serial.println(sendStatus == 0 ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  dht.begin();
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  if (esp_now_init() != 0) {
    Serial.println("ESPNOW Init Failed!");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnSent);
  esp_now_add_peer(rxMac, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  data.temperature = dht.readTemperature();
  data.humidity = dht.readHumidity();

  Serial.print("Temp: "); Serial.print(data.temperature);
  Serial.print("  Hum: "); Serial.println(data.humidity);

  esp_now_send(rxMac, (uint8_t *)&data, sizeof(data));

  if (data.temperature > 28) {
    tone(BUZZER, 2000, 500);
  } else {
    noTone(BUZZER);
  }

  delay(2000);
}

