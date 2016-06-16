# NVBOTS Firmware 
## Overview
```
+ NVMarlin 						- NVBots version of the Marlin firmware
|-+ .pioenvs/					- PlatformIO's build environments
|-+ build/						- Where the hex files end up
|-+ nv_configurations/ 			- Contains the settings for each configuration file
|-- Makefile 					- Standard make file
|-- platformio.ini 				- Platformio configuration
```
## NVMarlin Build Instructions

```
cd ./NVMarlin
make all
```

### Make a specific target 

```make <target>```

Looke in the Makefile for a list of targets.