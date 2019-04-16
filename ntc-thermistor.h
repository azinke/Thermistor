/* Negative temperature coeficient thermistor library
 * @author: AMOUSSOU Z. Kenneth
 * @date: 16-04-2019
 * @version: 1.0
 */
#ifndef H_NTC_THERMISTOR

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define DEG_C   0
#define DEG_K   1
#define DEG_F   2


class Thermistor{
    public:
        Thermistor(uint8_t pin);
        float read(uint8_t unit = DEG_C);
        void setReferenceResistance(float value); // value in ohm
        void setReferenceTemperature(float value); // value in °C
        void setFixeResistance(float value); // value in ohm
        void setADCReferenceVoltage(float value);
        void setB(float value);

    private:
        uint8_t _pin;
        float _data;
        float _vref;    // in volt
        float _temp;
        float _B_coef;
   //     float _r0;  // ctn thermistor reference value (R0) in ohm
        float _t0;  // ctn thermistor reference temperarure (t0) in °C

};

#endif
