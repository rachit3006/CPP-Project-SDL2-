#!/usr/bin/bash

# A simple bash script to compile and run the game

g++ *.cpp -w -g -Wall -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o a.out
./a.out
