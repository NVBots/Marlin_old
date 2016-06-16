BUILD_CMD = platformio
BUILD_DIR = build
NV_CONFIGURATIONS_DIR = $(realpath ./Marlin/nv_configurations)
NV_CONFIGURATIONS = $(shell ls $(NV_CONFIGURATIONS_DIR))
.PHONY: clean clean-all all
.DEFAULT_GOAL:= all
FLAGS=$(if $(findstring PR100,$(@)),-D MAD,)

all: clean-all $(NV_CONFIGURATIONS)

%:
	ls $(NV_CONFIGURATIONS_DIR)/$@
	$(BUILD_CMD) run -t clean
	export "PLATFORMIO_BUILD_FLAGS=-I$(NV_CONFIGURATIONS_DIR)/$@ $(FLAGS)";$(BUILD_CMD) run -e printerbot
	SW_VERSION=$$(./get_nv_software_version.sh $@); cp .pioenvs/printerbot/firmware.hex $(BUILD_DIR)/$@_$$SW_VERSION.hex

clean:
	$(BUILD_CMD) run -t clean

clean-all: clean
	rm -f ./$(BUILD_DIR)/*.hex
