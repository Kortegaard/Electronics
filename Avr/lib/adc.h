/*
*         Title : ADC
*        Author : Anders S. Kortegaard
*          Date : 17/01 - 2016
*
*   Description : reading adc values
*
*       credits : http://maxembedded.com/2011/06/the-adc-of-the-avr/
*/


#ifndef __adc_h__
  #define __adc_h__

  //Setting acd registers.
  void adc_init()
  {

      // Connecting AREF, to start adc
      ADMUX = (1<<REFS0)|(0<<REFS1);

      //Enable the ADC
      ADCSRA |= (1<<ADEN);

      //For choosing prescaler, (adc, 50-200kHZ)
      //Out prescaler = 180
      //16.000.000 / 180 = 120.000 = 120 kHZ
      ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

  }

  //Reading adc value
  uint16_t adc_read(uint8_t pin)
  {
    //makeing sure that pin < 8, else our previous options can be erased
    pin &= 0b00000111;
    //Setting the pin on the registor
    ADMUX = (ADMUX & 0xF8)|pin;

    //Starting conversation with ADC, by setting ADSC = 1 (registor ADCSRA)
    ADCSRA |= (1<<ADSC);

    //Wating for conversation with adc to end (when ADSC = 0)
    while(ADCSRA & (1<<ADSC));

    //ADCH & ADCL (8 bit storing registor for 10 bit analog reading)
    //ADC is a combination of ADCH & ADCL to get full reading
    return (ADC);
  }
#endif
