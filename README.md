# IoT-Enabled Parking Availability Tracker Powered by ESP8266

This project is designed to monitor parking space availability using infrared (IR) sensors and display the information on a web interface served from an ESP8266 microcontroller. The system tracks the status of multiple parking slots in real-time, providing users with up-to-date information on parking availability.

## Key Features
- Real-time tracking of parking slots
- Web-based interface for easy access
- Utilizes ESP8266 microcontroller
- Responsive design for various devices

## Components Used
- **ESP8266 NodeMCU**: Microcontroller with built-in Wi-Fi capabilities
- **IR Sensors**: Detect whether a parking slot is occupied or available
- **Jumper Wires**: For connections
- **Breadboard**: For circuit assembly

## Pin Configuration
| Component  | ESP8266 Pin | Description                       |
|------------|-------------|-----------------------------------|
| IR Sensor 1| D3          | Detects availability for Slot 1   |
| IR Sensor 2| D4          | Detects availability for Slot 2   |
| IR Sensor 3| D0          | Detects availability for Slot 3   |

## Software Libraries Required
- `ESP8266WiFi.h`
- `ESP8266WebServer.h`

## Setup and Configuration
1. **Connect the IR Sensors**:
   - Connect the output pin of IR Sensor 1 to pin D3 of the ESP8266.
   - Connect the output pin of IR Sensor 2 to pin D4 of the ESP8266.
   - Connect the output pin of IR Sensor 3 to pin D0 of the ESP8266.
   - Connect the ground and power pins of each sensor appropriately.

2. **Update Wi-Fi Credentials**:
   - Replace the `ssid` and `password` variables in the code with your Wi-Fi network's credentials.

3. **Upload the Code**:
   - Upload the provided code to your ESP8266 using the Arduino IDE.

## Usage
- After uploading the code, open the Serial Monitor to check the ESP8266's IP address.
- Access the parking availability system by entering the IP address in a web browser.
- The web interface will refresh every 5 seconds to update the parking slot statuses.

## Conclusion
This IoT-Enabled Parking Availability Tracker efficiently monitors parking space availability using IR sensors and provides real-time updates via a web interface. It helps in improving parking management and user experience.


![parking11](https://github.com/pratz222/IoT-Enabled-Parking-Availability-Tracker-Powered-by-ESP8266/assets/53640877/ddd43e7d-9495-4e24-aeea-63cd6a7224e1)
