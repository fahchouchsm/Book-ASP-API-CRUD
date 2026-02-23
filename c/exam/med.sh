#!/usr/bin/bash
# if with [ ]
num1=1
num2=1
if [ $num1 -eq $num2 ]; then
    echo "[ ]: 1 equals 1"
fi


# if with (())
if (( 2 > 1 )); then
    echo "(( )): 2 is greater than 1"
fi


# if with command (e.g., grep)
if echo "hello" | grep -q "hello"; then
    echo "command: found 'hello'"
fi

$0