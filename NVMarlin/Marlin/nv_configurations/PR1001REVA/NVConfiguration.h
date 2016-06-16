/*
	Hardware Notes:
        Printrboard RevF
		Single Extruder
		Thermistor: ???
*/

#ifndef NVCONFIGURATION_H
#define NVCONFIGURATION_H
 
// ########## General ##############
#define STRING_NV_HARDWARE_VERSION "PR1001REVA-v1"
#define MOTHERBOARD 83

// ####### Temperature Sensors ############
#define EXTRUDERS 1

#define TEMP_SENSOR_0 234
#define TEMP_SENSOR_1 -1
#define TEMP_SENSOR_BED 103

#define HEATER_0_MINTEMP 0
#define HEATER_1_MINTEMP 0
#define HEATER_2_MINTEMP 0
#define BED_MINTEMP 0

#define HEATER_0_MAXTEMP 1000
#define HEATER_1_MAXTEMP 1000
#define HEATER_2_MAXTEMP 1000
#define BED_MAXTEMP 1000

#define MAX_BED_POWER 255


// ############# Gantry Settings ################
// Travel limits after homing
#define X_MAX_POS 188
#define X_MIN_POS 0
#define Y_MAX_POS 228
#define Y_MIN_POS 0
#define Z_MAX_POS 245
#define Z_MIN_POS 0

#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)

#define DEFAULT_AXIS_STEPS_PER_UNIT   {100.0, 100.0, 1511.811, 109.30}
#define DEFAULT_MAX_FEEDRATE          {420, 420, 6, 550}
#define DEFAULT_MAX_ACCELERATION      {10000,10000,300,10000}

#define DEFAULT_ACCELERATION          10000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
#define DEFAULT_RETRACT_ACCELERATION  4500   // X, Y, Z and E max acceleration in mm/s^2 for retracts


// ########## SERVO #############
#define NUM_SERVOS 0

// ########### DHT ###############
#define NUM_DHT_SENSORS 0

#define MAD

#endif //__NVCONFIGURATION_H
