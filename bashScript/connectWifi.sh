#!/bin/bash

# Read in the tag.
read tagID

# Decrypt the tag.
# Call Caroline's and Alec's python code for decryption.
# <wifi_name>_<wifi_password>
### python <name_of_function> $tagID | wifiInfo
DECODED="Harvard Secure_Vandoren7942"
IFS="_"; WIFIINPUT=($DECODED); unset IFS;
USERNAME=${WIFIINPUT[0]}
PASSWORD=${WIFIINPUT[1]}
echo "Wifi username: $USERNAME"
echo "Wifi password: $PASSWORD"
airport -s | grep "$USERNAME"
IFS="_"
networksetup -setairportnetwork en0 $USERNAME $PASSWORD
unset IFS
