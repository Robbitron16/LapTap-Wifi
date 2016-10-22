#!/bin/bash

# Read in the tag.
read tagID

# Decrypt the tag.
# Call Caroline's and Alec's python code for decryption.
# <wifi_name>_<wifi_password>
### python <name_of_function> $tagID | wifiInfo
WIFIINFO="Harvard_University__Fishface"
WIFIINPUT=($(echo $WIFIINFO | tr "__" "\n"))
USERNAME=${WIFIINPUT[0]} ${WIFIINPUT[1]}
PASSWORD=${WIFIINPUT[2]}
echo "Wifi username: $USERNAME"
echo "Wifi password: $PASSWORD"
airport -s | grep $USERNAME
