/*
  Control a DC motor with 2 endstops

  Requires a full bridge driver such as STM's L6202

  Supports timed moves with endstop detection

*/

#ifndef dcmotor_h
#define dcmotor_h

#define DCMOTOR_FORWARD  0
#define DCMOTOR_BACKWARD 1

//Ejector macros
#define DCMOTOR_ENABLE(v) digitalWrite(DCMOTOR_ENABLE_PIN, v)

#define WRITE_DCMOTOR(y) {DCMOTOR_ENABLE(HIGH); digitalWrite(DCMOTOR_PIN1, y); digitalWrite(DCMOTOR_PIN2, (!y)); }
//#define WRITE_DCMOTOR(y) { digitalWrite(DCMOTOR_PIN1,y); digitalWrite(DCMOTOR_PIN2, (!y)); }
//#define WRITE_DCMOTOR_FORWARD { WRITE(DCMOTOR_PIN1,HIGH); WRITE(DCMOTOR_PIN2,LOW); }
//#define WRITE_DCMOTOR_BACKWARD { WRITE(DCMOTOR_PIN1,LOW); WRITE(DCMOTOR_PIN2,HIGH);}
#define WRITE_DCMOTOR_OFF { digitalWrite(DCMOTOR_PIN1,LOW); digitalWrite(DCMOTOR_PIN2,LOW); }

#define READ_DCMOTOR(p) (digitalRead(p) == ((p==DCMOTOR_MIN_PIN & DCMOTOR_MIN_INVERTING) | (p==DCMOTOR_MAX_PIN & DCMOTOR_MAX_INVERTING)))
//#define READ_DCMOTOR_MAX (READ(DCMOTOR_MAX_PIN) != DCMOTOR_ENDSTOPS_INVERTING)
//#define READ_DCMOTOR_MIN (READ(DCMOTOR_MIN_PIN) != DCMOTOR_ENDSTOPS_INVERTING)

//initialize and start dcmotor motor subsystem
void dcmotor_init();

void dcmotor_enable();

void dcmotor_disable();

//run motor until endstop is hit or time (ms) runs out
void dcmotor_move(bool dir, const unsigned long &time, const unsigned long &sample_pe);

//turn of the dcmotor subsystem
void finishAndDisableEjector();

#endif
