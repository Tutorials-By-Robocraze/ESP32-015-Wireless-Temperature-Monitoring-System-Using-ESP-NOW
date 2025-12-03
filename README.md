# **ESP-NOW Temperature & Humidity Monitoring System 🌡️📡**

A fast, secure, and Wi-Fi–free wireless system using **ESP-NOW** to transmit temperature & humidity data from a **TX board** to an **RX board**. The receiver displays data on an LCD and activates a buzzer alert if the temperature exceeds **28°C**!

---

## 📌 **Project Features**

### **TX Board (Sender)**

* Reads Temperature & Humidity using **DHT11 Sensor**
* Sends values wirelessly via **ESP-NOW**
* Has a **buzzer alert**
* Buzzer beeps if **Temperature > 28°C**

### **RX Board (Receiver)**

* Receives Temp & Humidity via **ESP-NOW**
* Displays values on **I2C 16×2 LCD**
* Includes **buzzer alert**

### **General**

* Fast, secure communication
* Works **without Wi-Fi router**
* Ideal for IoT sensor networks

---

## 🔧 **Components Required**

| Qty | Component             |
| --- | --------------------- |
| 2   | NodeMCU ESP8266       |
| 1   | DHT11 Sensor          |
| 1   | I2C 16×2 LCD          |
| 1   | Buzzer                |
| –   | Jumper Wires          |
| –   | Breadboard (optional) |

---

## 🔌 **Connections**

### **🔹 TX Board (DHT11 + Buzzer)**

| NodeMCU Pin | Component    |
| ----------- | ------------ |
| D3          | DHT11 Signal |
| 3V3         | DHT11 VCC    |
| GND         | DHT11 GND    |
| D2          | Buzzer +     |
| GND         | Buzzer –     |

---

### **🔹 RX Board (LCD + Buzzer)**

| NodeMCU Pin | Component |
| ----------- | --------- |
| SDA (D2)    | LCD SDA   |
| SCL (D1)    | LCD SCL   |
| 3V3         | LCD VCC   |
| GND         | LCD GND   |
| D3          | Buzzer +  |
| GND         | Buzzer –  |

---

## 👉 **MAC Addresses**

| Board | MAC Address           |
| ----- | --------------------- |
| TX    | **24:D7:EB:F2:44:09** |
| RX    | **24:D7:EB:FB:A7:31** |

---

## 🚀 **How It Works**

1. TX reads temperature & humidity from **DHT11**.
2. TX sends the sensor data to RX using **ESP-NOW**.
3. RX receives the values and updates the **I2C 16×2 LCD**.
4. If **temp > 28°C**, both TX & RX buzzers activate.
5. System works continuously—**no Wi-Fi or internet needed**.

---

## 🧪 **Testing Tips**

| Test                   | Expected Result                               |
| ---------------------- | --------------------------------------------- |
| Power both NodeMCUs    | LCD shows *“Waiting data”* then sensor values |
| Heat DHT11 with finger | Temperature increases                         |
| Temp > 28°C            | Buzzer beeps on **both TX & RX**              |
| Remove heat            | Buzzer stops                                  |

---

## 📌 **Advantages of ESP-NOW**

✓ Extremely fast communication
✓ Very low power usage
✓ No router or internet required
✓ Range up to **90 meters** in open area

---
