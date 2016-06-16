#!/bin/bash

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
SRC_DIR="$BASE_DIR/Marlin"
NV_CONF_DIR="$SRC_DIR/nv_configurations"

function usage {
    echo "Usage: get_nv_software_version.sh [list] <hardware configuration>"
    exit 1
}

function list_configurations {
    configurations=`ls $NV_CONF_DIR`
    for configuration in $configurations
    do
        echo $configuration
    done
}

if [ $# -ne 1 ];
then
  usage
fi

case "$1" in
    list)
        list_configurations
        ;;
    *)
        if [ -d "$NV_CONF_DIR/$1" ]; then
            if  [ ! -f $NV_CONF_DIR/$1/NVConfiguration.h ]; then
                echo "$NV_CONF_DIR/$1/NVConfiguration.h does not exist! Aborting."
                exit 1
            fi
           	echo `grep -s -Po '(?<=STRING_NV_SOFTWARE_VERSION \").*(?=\")' $NV_CONF_DIR/$1/NVConfiguration.h || grep -s -Po '(?<=STRING_NV_SOFTWARE_VERSION \").*(?=\")' $SRC_DIR/Configuration.h`
           	exit 0
        else
            echo "$1 is not a valid configuration. Try the list command to get a list of configurations."
        fi
        ;;
esac