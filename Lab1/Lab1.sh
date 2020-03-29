#!/bin/bash
# Name: Dan Sedano
# Date: 03/03/2020
# Title: Lab1 - Task
# Description: This program shows how some of the basic commands
# in Linux opperate. Additionally, the program computes the areas 
# of a square and a circle

echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
echo='whoami'
numusers=$(who | wc -l)
echo "Hi $USER! There are $numusers user(s) logged on."
if [ $USER = "dandano" ]
then
    echo "Now you can proceed!"
else
    echo "Check who logged in!"
    exit 1
fi

# Calculate the area of a circle
response="Yes"
while [ $response != "No" ]
do
    echo "Enter height of rectangle:"
    read height
    echo "Enter width of rectangle:"
    read width
    area=$(expr $height \* $width)
    echo "The area of the rectangle is $area"

    echo "Would you like to repeat for another rectangle[Yes/No]?"
    read response
    
done

# Calculate the area of a circle
PI=3.14
response="Yes"
while [ $response != 'No' ]
do  
    echo "Enter the radius of a circle:"
    read radius
    # Sleep for dramatic effect
    sleep 1
    echo "Calculating..."
    area=$(expr "$PI * ($radius * $radius)" | bc)
    # Another Sleep 
    sleep 1
    echo "The area of the circle is $area"

    echo "Would you like to repeat for another circle[Yes/No]?"
    read response

done 