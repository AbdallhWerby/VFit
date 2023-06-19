#include "arduino_secrets.h"
#include "thingProperties.h"
#include "Arduino_BHY2Host.h"
#include <Wire.h>
#include "MAX30105.h"
#include "Protocentral_MAX30205.h"

MAX30205 tempSensor;
Sensor EnvtempSensor(SENSOR_ID_TEMP);
Sensor humSensor(SENSOR_ID_HUM); 
MAX30105 particleSensor;

  // Pin Definitions
const int LO_PLUS_PIN = A0;
const int LO_MINUS_PIN = A1;
const int OUTPUT_PIN = A2;

void setup() {
  Serial.begin(9600);
  
  
  
  // 30205 BodyTemp Sensor configuration:
  
  Wire.begin();

  //scan for temperature in every 30 sec untill a sensor is found. Scan for both addresses 0x48 and 0x49
  while(!tempSensor.scanAvailableSensors()){
    Serial.println("Couldn't find the temperature sensor, please connect the sensor." );
    delay(8000);
  }

  tempSensor.begin();   // set continuos mode, active mode
  
  //////////////////////////////////////////////////////////////////////////////////////////
  
  
  // AD8232 ECG Sensor configuration:

  delay(1500);
    // Configure analog pins
  pinMode(LO_PLUS_PIN, INPUT);
  pinMode(LO_MINUS_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);


/////////////////////////////////////////////////////////////////////////////////////////////


  // 30105 Heartrate Sensor configuration:


  // Initialize sensor
  if (particleSensor.begin() == false) {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1);
  }
  particleSensor.setup();



/////////////////////////////////////////////////////////////////////////////////////////////

  // Configure the Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  Serial.println("Connecting to the Arduino IoT Cloud");
  while (!ArduinoCloud.connected()) {
    ArduinoCloud.update();
    delay(500);
  }

  Serial.println("Initialize the Nicla and the ");
  BHY2Host.begin(false, NICLA_VIA_BLE);
  EnvtempSensor.configure(1, 0);
  humSensor.configure(1, 0); 
  temperature = EnvtempSensor.value();
  humidity = humSensor.value(); // Read the initial humidity value


	bodytemp = tempSensor.getTemperature(); 
  redValue = particleSensor.getRed();
  irValue = particleSensor.getIR();
  
}

void loop() {
  BHY2Host.update();
  
  temperature = EnvtempSensor.value();
  humidity = humSensor.value(); // Update the humidity value

  ecgValue = analogRead(OUTPUT_PIN);


  
  redValue = particleSensor.getRed();
  irValue = particleSensor.getIR();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(", Humidity: ");
  Serial.print(humidity);
  Serial.print(", Red: ");
  Serial.print(redValue);
  Serial.print(", IR: ");
  Serial.println(irValue);
  Serial.println(ecgValue);

	bodytemp = tempSensor.getTemperature(); 
	Serial.print(bodytemp ,2);
	Serial.println("'c" );
	delay(100);
	
  ArduinoCloud.update();
}

void onTemperatureChange() {
  // Add your code here to act upon temperature change
}

void onHumidityChange() {
  // Add your code here to act upon humidity change
}

void onRedValueChange() {
  // Add your code here to act upon Red value change
}

void onIrValueChange() {
  // Add your code here

}
/*
  Since EcgValue is READ_WRITE variable, onEcgValueChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onEcgValueChange()  {
  // Add your code here to act upon EcgValue change
}

/*
  Since Bodytemp is READ_WRITE variable, onBodytempChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBodytempChange()  {
  // Add your code here to act upon Bodytemp change
}