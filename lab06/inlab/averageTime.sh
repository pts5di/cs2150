#!/bin/bash

WORDS=words.txt
GRID=4x7.grid.txt
RUNNING_TIME1=`./a.out "$WORDS" "$GRID" | tail -1`
RUNNING_TIME2=`./a.out "$WORDS" "$GRID" | tail -1`
RUNNING_TIME3=`./a.out "$WORDS" "$GRID" | tail -1`
RUNNING_TIME4=`./a.out "$WORDS" "$GRID" | tail -1`
RUNNING_TIME5=`./a.out "$WORDS" "$GRID" | tail -1`
echo $((($RUNNING_TIME1+$RUNNING_TIME2+$RUNNING_TIME3+$RUNNING_TIME4+$RUNNING_TIME5)/5))
