#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER D3
LiquidCrystal_I2C lcd(0x27, 16, 2);

typedef struct SensorData
{
    float temperature;
    float humidity;
} SensorData;

SensorData incomingData;

void OnDataRecv(uint8_t *mac, uint8_t *incomingDataBuffer, uint8_t len)
{
    memcpy(&incomingData, incomingDataBuffer, sizeof(incomingData));

    Serial.print("Received Temp: ");
    Serial.print(incomingData.temperature);
    Serial.print("  Hum: ");
    Serial.println(incomingData.humidity);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(incomingData.temperature);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(incomingData.humidity);
    lcd.print(" %");

    if (incomingData.temperature > 28)
    {
        tone(BUZZER, 2000, 600);
    }
    else
    {
        noTone(BUZZER);
    }
}

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);

    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("Waiting data");

    if (esp_now_init() != 0)
    {
        Serial.println("ESPNOW Init Failed!");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
    esp_now_register_recv_cb(OnDataRecv);
}

void loop()
{
    // No code here — data handled in callback
}
