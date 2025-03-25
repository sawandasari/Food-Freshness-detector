# Smart Food Freshness Detection System

## Overview
This project is a prototype developed using Raspberry Pi, Arduino UNO, and biosensors (moisture, gas, pH) to detect food freshness, enhancing safety in food processing. It determines whether a food item is safe to consume by analyzing its pH, moisture, and gas emissions. An Android application is integrated to display the results and alert users regarding food safety.

This project was completed as a minor project during my bachelor's studies.

## Motivation
Food plays a crucial role in our health and well-being. However, food stored at room temperature undergoes rapid bacterial growth and chemical changes, leading to spoilage and potential foodborne illnesses. This project aims to ensure food safety by using biosensors to detect spoilage in household food items like dairy products, meat, and fruits.

## Features
- Detects food freshness using pH, gas, and moisture sensors.
- Displays real-time readings on an LCD screen.
- Sends alerts via GSM module with freshness status and sensor data.
- Integrated Android application for user interaction.

## Components Used
### Hardware:
- **Arduino UNO** (Microcontroller)
- **pH Sensor** (Measures acidity levels)
- **Gas Sensor** (Detects gases emitted from spoiled food)
- **Temperature Sensor** (Monitors temperature variations)
- **Soil Moisture Sensor** (Determines moisture content)
- **GSM Module** (Sends alerts via SMS)
- **LCD Display** (Shows real-time readings)

### Software:
- **Programming Language:** C++
- **Platform:** Arduino IDE
- **Android Application:** For food type selection and notifications

## How It Works
1. **Food Sample Testing:** The food item is placed near the gas sensor.
2. **Sensor Readings:** The gas sensor detects spoilage gases, the pH sensor measures acidity levels, and the moisture sensor determines water content.
3. **Data Processing:** The collected data is processed by the Arduino, which determines freshness based on predefined thresholds.
4. **Alerts & Display:** The results are displayed on an LCD screen and sent to a registered phone number via the GSM module.
5. **User Interaction:** The Android application allows users to select the type of food being tested and receive notifications.

   ![Picture1](https://github.com/user-attachments/assets/6111eedb-097e-4b63-b0e3-410fb4e04c28)


## Future Enhancements
- **Integration with IoT:** Cloud storage and real-time monitoring via mobile apps.
- **AI-Based Analysis:** Machine learning to improve freshness prediction accuracy.
- **Expanded Sensor Capabilities:** Additional sensors for detecting more parameters like bacterial growth.

## Conclusion
This smart system helps in detecting food freshness efficiently, reducing food waste and preventing health hazards. By integrating multiple sensors and real-time alerts, it provides a practical solution for households and food industries to ensure food safety.

## Installation & Usage
1. Connect the sensors to the Arduino UNO as per the circuit diagram.
2. Upload the C++ code using Arduino IDE.
3. Run the system and observe readings on the LCD display.
4. Check freshness status via the Android application or SMS alerts.

## License
This project is open-source and available for modification and enhancement.

