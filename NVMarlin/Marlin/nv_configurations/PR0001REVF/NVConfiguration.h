/*
	Hardware Notes:
        Printrboard RevF
		Single Extruder
		Thermistor: Semitec 234
*/

#ifndef NVCONFIGURATION_H
#define NVCONFIGURATION_H

// ########## General ##############
#define STRING_NV_HARDWARE_VERSION "PR0001REVF"
#define MOTHERBOARD 82

// ####### Temperature Sensors ############
#define EXTRUDERS 1

#define TEMP_SENSOR_0 234
#define TEMP_SENSOR_1 -1
#define TEMP_SENSOR_BED 1

#define MAX_BED_POWER 255

// ############# Gantry Settings ################
// Travel limits after homing
#define X_MAX_POS 206
#define X_MIN_POS 0
#define Y_MAX_POS 228
#define Y_MIN_POS 0
#define Z_MAX_POS 245
#define Z_MIN_POS 0

#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)

// ########## SERVO #############
#define NUM_SERVOS 0

// ########### DHT #########
#define NUM_DHT_SENSORS 1

#endif //__NVCONFIGURATION_H
