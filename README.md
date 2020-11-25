# word-counter
A C++ program I made to count the frequency of characters in a text file.

## Compiling the program
In order to compile the program for use, run the following command:

`cd word-counter/src

clang++ wordCount.cpp -o word -std=c++17`

If you do not have clang++ installed on your machine, g++ should be:

`g++ wordCount.cpp -o word -std=c++17`

## Running the program
After compiling the program, there will be a file in the directory along the lines of 'word'.
To run, you can type:

`./word ../data/frankenstein.txt`

The program will then output the results onto the terminal screen.
