# Smart Stick with Telegram Messaging

This project is a smart stick that uses an ultrasonic sensor to detect nearby objects and sends Telegram messages to the user in case of emergencies. It leverages the ESP8266 module and utilizes the UniversalTelegramBot library for Telegram integration.

## Features

- **Object Detection**: Uses an ultrasonic sensor to detect objects in front of the stick.
- **Emergency Alerts**: Sends Telegram messages to the user when the emergency button is pressed.
- **Buzzer and Motor Control**: Activates a buzzer and motor when an object is detected within a safety distance.

## Requirements

- ESP8266 Wi-Fi module
- Ultrasonic sensor
- Buzzer
- Motor
- UniversalTelegramBot library
- Telegram bot token
- Telegram chat ID
- Wi-Fi credentials (SSID and password)

## Setup

1. Clone this repository to your local machine.
2. Install the necessary libraries, including the UniversalTelegramBot library.
3. Replace the placeholder values (`ssid`, `password`, `BOTtoken`, and `CHAT_ID`) in the code with your Wi-Fi credentials, Telegram bot token, and Telegram chat ID.
4. Upload the code to your ESP8266 module.

## How It Works

- Upon starting, the smart stick connects to Wi-Fi and sends a message to the user indicating that the system has started.
- The ultrasonic sensor measures the distance to objects in front of the stick.
- If an object is detected within a safety distance, the buzzer and motor are activated to alert the user.
- An emergency button allows the user to send an emergency message to their Telegram chat.

## Usage

- Walk with the smart stick as you normally would.
- If you encounter an object within a safety distance, the stick will alert you using the buzzer and motor.
- In case of an emergency, press the button on the stick to send a message to your Telegram chat.

## Notes

- Ensure your Telegram bot token and chat ID are kept secure and not shared publicly.
- Adjust the safety distance as needed in the code to fit your preference.

## Author

- Abhishek Rajput
