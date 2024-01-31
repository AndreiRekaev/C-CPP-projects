#/bin/bash

chmod +x getsysinfo.sh

status=$(./getsysinfo.sh)
cat <<< $status
echo
echo "Write data in file (Y/N)? File DD_MM_YY_HH_MM_SS.status will be created"

read answer

if [ $answer = y ] || [ $answer = Y ];
then
    file="$(date +"%d_%m_%g_%H_%M_%S").status"
    touch $file
    cat <<< $status > $file
fi