/*
    @author: AMOUSSOU Z. Kenneth
    @date: 17-04-2019
    @version:
*/
#include <ntc-thermistor.h>

Thermistor sensor(A0);  // analog input 0

void setup(){
    Serial.begin(115200);
    
}

void loop(){
    Serial.print("Temp: ");
    Serial.print(sensor.read());
    Serial.println(" °C");
    delay(500);
}
