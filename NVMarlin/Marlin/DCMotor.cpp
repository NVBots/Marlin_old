/*
  Add support for dc motor with 2 limit switches
*/

#include "Marlin.h"
#include "DCMotor.h"
#include "temperature.h"

void dcmotor_init()
{
    //Initialize endstops
    #if DCMOTOR_MIN_PIN > -1
        pinMode(DCMOTOR_MIN_PIN,INPUT);
        #ifdef ENDSTOPPULLUPS
            digitalWrite(DCMOTOR_MIN_PIN,HIGH);
        #endif
    #endif

    #if DCMOTOR_MAX_PIN > -1
        pinMode(DCMOTOR_MAX_PIN,INPUT);
        #ifdef ENDSTOPPULLUPS
            digitalWrite(DCMOTOR_MAX_PIN,HIGH);
        #endif
    #endif

    //Initialize Motor pins
    #if DCMOTOR_PIN1 > -1
        pinMode(DCMOTOR_PIN1,OUTPUT);
        digitalWrite(DCMOTOR_PIN1,LOW);
    #endif

    #if DCMOTOR_PIN2 > -1
        pinMode(DCMOTOR_PIN2,OUTPUT);
        digitalWrite(DCMOTOR_PIN2,LOW);
    #endif

    //Initialize enable pin
    #if DCMOTOR_ENABLE_PIN > -1
        pinMode(DCMOTOR_ENABLE_PIN,OUTPUT);
        digitalWrite(DCMOTOR_ENABLE_PIN,LOW);
    #endif
}

void dcmotor_enable()
{
    DCMOTOR_ENABLE(HIGH);
}

void dcmotor_disable()
{
    DCMOTOR_ENABLE(LOW);
}
/*
    LCD_MESSAGEPGM(MSG_DWELL);
      codenum = 0;
      if(code_seen('P')) codenum = code_value(); // milliseconds to wait
      if(code_seen('S')) codenum = code_value() * 1000; // seconds to wait
      
      st_synchronize();
      codenum += millis();  // keep track of when we started waiting
      previous_millis_cmd = millis();
      while(millis()  < codenum ){
        manage_heater();
        manage_inactivity();
		LCD_STATUS;
      }
*/

void dcmotor_move(bool dir, const unsigned long &time, const unsigned long &sample_period)
{  int l=0.0;
  //st_synchronize();
    unsigned long t = time + millis();
    WRITE_DCMOTOR(dir);
    int pin = (dir == DCMOTOR_FORWARD) ? DCMOTOR_MAX_PIN : DCMOTOR_MIN_PIN;
    unsigned long now = millis();
    unsigned long start = now;
    unsigned long next_sample = now + sample_period;
//    if (dir == DCMOTOR_FORWARD) {
//    SERIAL_PROTOCOL("Removal started dir=");
//    SERIAL_PROTOCOL(dir);
//    SERIAL_PROTOCOL(" time=");
//    SERIAL_PROTOCOL(time);
//    SERIAL_PROTOCOL(" sample_period=");
//    SERIAL_PROTOCOL(sample_period);
//    SERIAL_PROTOCOL(" now=");
//    SERIAL_PROTOCOL(now);
//    SERIAL_PROTOCOL(" t=");
//    SERIAL_PROTOCOLLN(t);
        while ( READ_DCMOTOR(pin) ) {
            now = millis();
            if (now >= t) {
                SERIAL_PROTOCOL("timeout now=");
                SERIAL_PROTOCOLLN(now);
                break; 
            }
            if (sample_period > 0) {
                if ( next_sample <= now  ) {
                    // print motor current
                    SERIAL_PROTOCOL(now - start);
                    SERIAL_PROTOCOL(",");
                    SERIAL_PROTOCOLLN(analogRead(DCMOTOR_CURRENT_PIN));
                    next_sample += sample_period;
                }
            }
            manage_heater();
            manage_inactivity();
        }
//    }
//    else if (dir == DCMOTOR_BACKWARD) {
//        while ( (READ_DCMOTOR(DCMOTOR_MIN_PIN)) && (millis() < t) ) {
//            manage_heater();
//            manage_inactivity();
//        }
//    }
    

    WRITE_DCMOTOR_OFF;
}

void finishAndDisableEjector()
{
    dcmotor_disable();
    //Do something maybe...
}
