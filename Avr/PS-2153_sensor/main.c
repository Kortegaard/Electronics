/*
 *        Title : PS-2153
 *       Author : Anders S. Kortegaard
 *         Date : 17/01 - 2016
 *
 *  Description : This code is for the temperatur sensor : PS-2153 (https://www.pasco.com/support/technical-support/technote/techIDlookup.cfm?TechNoteID=441)
 *                For calculating the temperature.
 *
 *     Partlist : - AT
 *                - 10 k ohm resistor
 *                - PS-2153
 *
 *      Circuit :    5V ----  PS-2153  ---- 10 k ohm
 *                               |             |
 *                               |          Ground
 *                               |
 *                         Analog input
 */

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "../lib/adc.h"



#define SENSOR_PIN 0
#define DELAY 250
#define CALIBRATION 0
#define VOLT 5
#define R1 10000

double temp = 0;


// PS-2153 : Calculating constants
const double A = 0.003354;
const double B = 0.0002564;
const double C = 0.000002388;
const double D = 0.00000008377;

/**
 * Calculating Temperature
 *
 * Formulas : Temperature[Celsius] = 1.0 / ( A + B ln(R) + C ln(R)^2 + D ln(R)^3 ) - 273.15
 *            R = ThermistorResistance[Ohms] / 10000
 *
 * @var sensor_resistance - Double (the resistance through the sensor)
 * @return temperature - Double
 */
double calcTemp(double sensor_resistance){
  double R = sensor_resistance / 10000;
  return 1.0 / ( A + B*log(R) + C*pow(log(R),2) + D*pow(log(R),3)) - 273.15;
}

/**
 * Calculating sensor resistanse, from the ADC
 *
 * Formula made from voltage divider
 *
 * @var sensor_in - Double (sensor input)
 * @var R1 - int (the constant resistor in circuit)
 * @var V - int (total voltage)
 * @return sensor resistance - Double
 */
double sensorToResistance(double sensor_in, int resistor1,int V){
  double V_sensor = (sensor_in * V)/1024;
  return ((V/V_sensor)-1)*resistor1;
}

/**
 * combing the two calculation functions
 *
 * @var sensor_in - Double (analogRead from sensor)
 * @var calibrate - Double (calibration const)
 * @return temperature
 */
double tempFromSensor(double sensor_in, double calibrate){
  return calcTemp(sensorToResistance(sensor_in,R1,VOLT)) + calibrate;
}


void main() {
  adc_init();
  DDRA = 1 << SENSOR_PIN;
  while (1) {
    temp = tempFromSensor(adc_read(SENSOR_PIN),CALIBRATION);
    _delay_ms(DELAY);
  }

}
