#!/bin/bash

# Tool for flashing printrboard firmware via a remote machine

help ()
{
    echo 'usage: ./remote_flash.sh <printrboard_hex_file> <remote_host>'
}

if [ "$#" -ne 2 ]
then
	echo "Too few arguments. "
	help
	exit 1
fi

if [ ! -e "$1" ]
then
  echo "No such file: $1"
  help
  exit 1
fi

ping -c 1 -w 3 $2 2>&1 > /dev/null

if [ $? -ne 0 ]
then
    echo "Unable to pint host $2. Make sure you are on the same network and host is online"
    help
    exit 1
fi

ssh -q -o BatchMode=yes -o ConnectTimeout=3 nvbots@$2 exit

if [ $? -ne 0 ]
then
    echo "Unable to ssh to nvbots@$2. Make sure your public key has been added to authorized_keys on $2"
    help
    exit 1
fi

scp $1 nvbots@$2:/tmp/nvfw.hex

if [ $? -ne 0 ]
then
    echo "Unable to upload $1 to nvbots@$2:/tmp/nvfw.hex"
    help
    exit 1
fi

ssh nvbots@$2 'sudo bash -c  "echo M67\n > /dev/ttyACM* && sudo hid_bootloader_cli -mmcu=at90usb1286 -w -v /tmp/nvfw.hex && echo done"'

exit $?
