#ifndef PINS_H
#define PINS_H

#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1

/****************************************************************************************
* NVBOTS REVF
* Teensylu 0.7 / Printrboard pin assignments (AT90USB1286)
* Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
  http://www.pjrc.com/teensy/teensyduino.html
* See http://reprap.org/wiki/Printrboard for more info
****************************************************************************************/
#if MOTHERBOARD == 82 || MOTHERBOARD == 83
#define KNOWN_BOARD 1
#define AT90USB 1286  // Disable MarlinSerial etc.

#ifndef __AVR_AT90USB1286__
#error Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH        true

#define X_STEP_PIN          0
#define X_DIR_PIN           1
#define X_ENABLE_PIN       39

#define Y_STEP_PIN          2
#define Y_DIR_PIN           3
#define Y_ENABLE_PIN       38

#define Z_STEP_PIN          4
#define Z_DIR_PIN           5
#define Z_ENABLE_PIN       23

#define E0_STEP_PIN         6
#define E0_DIR_PIN          7
#define E0_ENABLE_PIN      19

#define E1_STEP_PIN         6
#define E1_DIR_PIN          7
#define E1_ENABLE_PIN      19

#define HEATER_0_PIN       21  // Extruder
#define HEATER_1_PIN       46 // was 46
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     20  // Bed - was 20
#define FAN_PIN            13  // Fan, WAS 24
// You may need to change FAN_PIN to 16 because Marlin isn't using fastio.h
// for the fan and Teensyduino uses a different pin mapping.

#ifdef NUM_SERVOS
   #if NUM_SERVOS > 0
    #define SERVO0_PIN 1
   #endif
   #if NUM_SERVOS > 1
    #define SERVO1_PIN        -1
   #endif
   #if NUM_SERVOS > 2
    #define SERVO2_PIN         -1
   #endif
   #if NUM_SERVOS > 3
    #define SERVO3_PIN         -1
   #endif
#endif

#ifdef NUM_DHT_SENSORS
  #if NUM_DHT_SENSORS > 0
    #define DHT_0_PIN 37
    #define DHT_0_TYPE 22
  #endif
  #if NUM_DHT_SENSORS > 1
    #define DHT_1_PIN 40
    #define DHT_1_TYPE 22
  #endif
#endif
/*!!!!!!!! Analog Pin Mapping !!!!!!!!*/
#define DCMOTOR_CURRENT_PIN 3

/*!!!!!!!! ALWAYS USE digitalRead FOR BOTTOM_LIMIT_PIN, DCMOTOR_MIN/MAX_PIN, or E_STOP_PIN !!!!!!!! */

//#define BOTTOM_LIMIT_PIN    10 //bottom stop
#define E_STOP_PIN          37 //E-stop

//pins for endstops
#define DCMOTOR_MIN_PIN     11 //31 //backstop
#define DCMOTOR_MAX_PIN      9 //30 //frontstop

//pins for motor control
#define DCMOTOR_ENABLE_PIN   45 //29
#define DCMOTOR_PIN1    43 //28      //This pin high moves the blade forward
#define DCMOTOR_PIN2    42 //27      //This pin high moves the blade backwards

#ifdef MAD
//pins for psu
#define STM32_NSS 8			 	//EXP2:PE0 two from bottom right
#define PSU_ENABLE_PIN 10 	// EXP2:PC0 one from bottom right
#define PSU_FIRING_PIN	18  // EXP2:PC2  bottom right (fastio pin!)
#define PSU_CONTACT_PIN 42  	//EXP1:A2 bottom left (fastio pin!)
#define PSU_STALL_PIN 43  	//EXP1:A3 one from bottom left (fastio pin!)
#endif

#define X_STOP_PIN         35
#define Y_STOP_PIN         12 //8
#define Z_MAX_PIN          16
#define Z_MIN_PIN          36
#define TEMP_0_PIN          1  // Extruder / Analog pin numbering
#if MOTHERBOARD == 83
  #define TEMP_BED_PIN 0
  #define DHT_0_PIN 37
  #define DHT_0_TYPE DHT22
  #define DHT_1_PIN 40
  #define DHT_1_TYPE DHT22
#else // MOTHERBOARD == 82
  #define TEMP_BED_PIN 2
#endif

#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1

#define SDPOWER            -1
#define SDSS                8
#define LED_PIN            -1
#define PS_ON_PIN          -1
#define KILL_PIN           -1
#define ALARM_PIN          -1

#define DAC_STEPPER_CURRENT
#define DAC_STEPPER_ADDRESS 0
#define DAC_STEPPER_ORDER   {3,2,1,0}
#define DAC_STEPPER_MAX     3520
#define DAC_STEPPER_VREF    1 //internal Vref, gain 1x = 2.048V
#define DAC_STEPPER_GAIN    0

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN           9
  #define MISO_PIN         11
  #define MOSI_PIN         10
#endif

#endif  // MOTHERBOARD == 82 (Printrboard REVF)

/****************************************************************************************
* NVBOTS REVE
* Teensylu 0.7 / Printrboard pin assignments (AT90USB1286)
* Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
  http://www.pjrc.com/teensy/teensyduino.html
* See http://reprap.org/wiki/Printrboard for more info
****************************************************************************************/
#if MOTHERBOARD == 81
#define KNOWN_BOARD 1
#define AT90USB 1286  // Disable MarlinSerial etc.

#ifndef __AVR_AT90USB1286__
#error Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH        true

#define X_STEP_PIN          0
#define X_DIR_PIN           1
#define X_ENABLE_PIN       39

#define Y_STEP_PIN          2
#define Y_DIR_PIN           3
#define Y_ENABLE_PIN       38

#define Z_STEP_PIN          4
#define Z_DIR_PIN           5
#define Z_ENABLE_PIN       23

#define E0_STEP_PIN         6
#define E0_DIR_PIN          7
#define E0_ENABLE_PIN      19

#define E1_STEP_PIN         6
#define E1_DIR_PIN          7
#define E1_ENABLE_PIN      19

#define HEATER_0_PIN       21  // Extruder
#define HEATER_1_PIN       46 // was 46
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     20  // Bed - was 20
#define FAN_PIN            24
// You may need to change FAN_PIN to 16 because Marlin isn't using fastio.h
// for the fan and Teensyduino uses a different pin mapping.

#ifdef NUM_SERVOS
   #if NUM_SERVOS > 0
    #define SERVO0_PIN 1
   #endif
   #if NUM_SERVOS > 1
    #define SERVO1_PIN        -1
   #endif
   #if NUM_SERVOS > 2
    #define SERVO2_PIN         -1
   #endif
   #if NUM_SERVOS > 3
    #define SERVO3_PIN         -1
   #endif
#endif

#if NUM_SERVOS == 0 && EXTRUDERS == 1  // Only enable DHT on servo port if there is one extruder and no servos
#ifdef NUM_DHT_SENSORS
  #if NUM_DHT_SENSORS > 0
    #define DHT_0_PIN 1
    #define DHT_0_TYPE 22
  #endif
#endif
#endif


/*!!!!!!!! Analog Pin Mapping !!!!!!!!*/
#define DCMOTOR_CURRENT_PIN 3

/*!!!!!!!! ALWAYS USE digitalRead FOR BOTTOM_LIMIT_PIN, DCMOTOR_MIN/MAX_PIN, or E_STOP_PIN !!!!!!!! */

//#define BOTTOM_LIMIT_PIN    10 //bottom stop
#define E_STOP_PIN          37 //E-stop

//pins for endstops
#define DCMOTOR_MIN_PIN     11 //31 //backstop
#define DCMOTOR_MAX_PIN      9 //30 //frontstop

//pins for motor control
#define DCMOTOR_ENABLE_PIN   45 //29
#define DCMOTOR_PIN1    43 //28      //This pin high moves the blade forward
#define DCMOTOR_PIN2    42 //27      //This pin high moves the blade backwards

#define X_STOP_PIN         35
#define Y_STOP_PIN          8
#define Z_MAX_PIN          16
#define Z_MIN_PIN          36
#define TEMP_0_PIN          1  // Extruder / Analog pin numbering
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN        2  // Bed / Analog pin numbering, was 0
#endif
#define TEMP_1_PIN         0
#define TEMP_2_PIN         -1

#define SDPOWER            -1
#define SDSS                8
#define LED_PIN            -1
#define PS_ON_PIN          -1
#define KILL_PIN           -1
#define ALARM_PIN          -1

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN           9
  #define MISO_PIN         11
  #define MOSI_PIN         10
#endif

#endif  // MOTHERBOARD == 81 (Printrboard)


#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#ifdef DISABLE_MIN_ENDSTOPS
#define X_MIN_PIN          -1
#define Y_MIN_PIN          -1
#define Z_MIN_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }
#endif

