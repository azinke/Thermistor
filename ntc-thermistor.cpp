/*
 * @author: AMOUSSOU Z. Kenneth
 * @date: 16-04-2019
 * @version: 1.0
 */

#include <ntc-thermistor.h>

/* @func Thermistor: constructor
 * @param: none
 * @return: none
 */
Thermistor::Thermistor(uint8_t pin){
    _pin = pin;     // analog pin
    _vref = 5.0;    // volt
    // _r0 = 10000;     // ohm
    // _r = 10000;      // ohm - fixe resistor for sensor conditioning
    _B_coef = 3380.;
    _t0 = 25.;      // °C

}

/* @func read: read and process temperature data
 * @param unit: unit of the temperature data
 * @return: none
 */
float Thermistor::read(uint8_t unit = DEG_C){
    _data = 0.;
    for(uint8_t i = 0; i < 10; i++){
        _data += analogRead(_pin);
        delay(10);
    }
    _data /= 10;                        // mean of analog value
    _data = (_data * _vref / 1023.);    // compute sensor voltage
    _data = (_vref/_data) - 1.;   // compute thermistor resistance
    _temp = 1./(_t0 + 273.15 ) + log(_data)/_B_coef;    
    _temp = 1/_temp; // temperature in °Kelvin
    if(unit == DEG_K) return _temp;
    if(unit == DEG_C) return (_temp - 273.15);
    else return (9. * (_temp - 273.15) / 5.) + 32.;
}

/* @func setB: set the dimensionless B coef of the sensor
 * @param value: new value of B coef. to set
 * @return: none
 */
void Thermistor::setB(float value){
    _B_coef = value;
}

/* @func setReferenceTemperatue: set the ref. temperarure
 * @param value: new value of reference temperature to set
 * @return: none
 */
void Thermistor::setReferenceTemperature(float value){
    _t0 = value;
}

/* @func setADCReferenceVoltage: set ref. voltage
 * @param value: new value for vref
 * @return: none
 */
void Thermistor::setADCReferenceVoltage(float value){
    _vref = value;
}
