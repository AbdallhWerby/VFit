# VFit
VFit is a biomedical engineering project that focuses on developing a smart monitor shirt.


VFit is a biomedical engineering technology brand focused on creating innovative solutions for healthcare and fitness. Our project revolves around the development of a smart monitor shirt that can sense and measure 12+ indications in real-time. These indications include vital signs, environmental parameters, and movement. The smart shirt is designed for use by patients with chronic diseases, athletes, elderly individuals, and anyone who wants to monitor their health. It features a removable pouch at the back for easy cleaning without damaging the electronics. This technology allows for instantaneous recording, parameter extrapolation, and inter-signal elaboration, leading to better well-being assessment, prevention of misdiagnosis, and early detection of underlying health issues.


# VFit: Smart Monitoring Shirt 👕🩺

VFit is a biomedical innovation that combines wearable sensors, IoT, and AI to enable real-time monitoring of vital signs and environmental conditions through a smart shirt. Designed for patients, athletes, and health-conscious users, it bridges the gap between personal wellness and remote healthcare.

---

## 🚀 Features

- Real-time tracking of heart rate, SPO2, skin temperature, ECG, humidity, and motion
- Remote monitoring via Arduino IoT Cloud
- Built-in machine learning for health status prediction
- App Inventor mobile interface for live viewing
- Removable electronics module for ease of washing

---

## 💡 Use Cases

- 🏥 Chronic disease monitoring
- 🧘 Health & stress tracking
- 🏃 Athlete performance analysis
- 👵 Elderly care and fall detection

---

## 🧠 Components & Architecture

### Hardware
- Arduino Portenta H7 + Nicla Sense ME
- MAX30102 – Heart rate & SPO2
- MAX30205 – Skin temperature
- AD8232 – ECG
- LiPo battery with ~7hr operation
- Custom PCB with washable shirt

### Software & IoT
- Arduino Cloud integration
- App Inventor mobile app
- Machine Learning (XGBoost, Lasso, etc.)
- Synthetic data generation for training

---

## 📊 Machine Learning

We generated synthetic vitals data for sprint, alert, and rest conditions and trained multiple ML models:

| Model             | Accuracy (R²) |
|------------------|---------------|
| XGBoost          | 0.93          |
| Random Forest    | 0.91          |
| Decision Tree    | 0.87          |

---

## 📸 Screenshots

![System Diagram](media/diagrams/system_flow.png)
![App Layout](software/app_inventor_mockup.png)

---

## 💵 Cost & Manufacturing

| Component            | Price (EGP) |
|----------------------|-------------|
| Arduino Portenta H7  | 2850        |
| Nicla Sense ME       | 1600        |
| Sensors, PCB, Vest   | 2955        |
| **Total**            | **7405 EGP** per unit

🛒 Selling price: 8500 EGP → **20% Profit**

---

## 📲 Mobile App

Our MIT App Inventor-based app provides live monitoring and control over Bluetooth/Cloud.

---

## 📦 How to Run

### Arduino
1. Open `firmware/main_firmware.ino` in Arduino IDE
2. Install dependencies from `libraries.txt`
3. Flash it to your board

### Python (ML & data)
```bash
pip install -r requirements.txt
jupyter notebook software/prediction_notebook.ipynb
