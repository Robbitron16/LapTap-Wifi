#!/bin/bash

# Read in the tag.
read tagID

# Decrypt the tag.
# Call Caroline's and Alec's python code for decryption.
# <wifi_name>_<wifi_password>
### python <name_of_function> $tagID | wifiInfo
if [ "$tagID" -eq "0005708410" ]
then
    python ../encryption/other\ stuff/decrypt.py | xargs java Decoder | xargs ../encryption/decryptC

else
    echo "Incorrect tag"
fi

DECODED="Uberall master_rumvh4hxjf0j"

IFS="_"; WIFIINPUT=($DECODED); unset IFS;
USERNAME=${WIFIINPUT[0]}
PASSWORD=${WIFIINPUT[1]}
echo "Wifi username: $USERNAME"
echo "Wifi password: $PASSWORD"
COUNT=`airport -s | grep "$USERNAME" | wc -l`
echo $COUNT
if [ $COUNT -gt 0 ]
then
    IFS="_"
    networksetup -setairportnetwork en0 $USERNAME $PASSWORD
    unset IFS
else
    echo "No networks matching $USERNAME were found!"
fi
