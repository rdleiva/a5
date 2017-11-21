# Design Document for Final Project
### Authors: Eydis Embla Ludviksdottir, Rotman Daniel Leiva
### Emails:  eydisembla@my.uri.edu,     rdleiva@my.uri.edu


## Milestone 1
### Problems to solve
    1. Test how many command arguments there are.
    2. Count how many times each trigram appears in a string from the command line and stores it in a vector.
    3. Output the frequency vector in the correct order, from `   ` to `zzz`, separated by space.

### How to solve the problems
    1. Store command line argument in a string, if there is less than, or more than one argument, EXIT_FAILURE.
    2. Create a function that takes a string, loops through it and converts each trigram into a number with base 27, which will be the index that represents the trigram in the frequency vector.
    3. Output each element in the vector through a for loop and place a space between each element.

### Classes needed:
    - None

### Other functions:
    - `freqVec()` converts each trigram that appears in a string into a number and counts how many times each number appears, by creating a vector and making the number represent an index in the vector.
        - takes a string as an argument.
        - returns a vector of integers, frequency of each trigram in the string.
    - `main()`
        - takes the command line as an argument, argv, and its size, argc.
        - tests if the command line is only one argument, if not throws an error.
        - calls `freqVec()` and passes the string from the command line to it.
        - output each element in the vector through a for loop and place a space between each element.

### Files needed
    - `main.cpp` to calculate the frequency vector

### Libraries needed
    - vector
    - string
    - iostream
    - cmath - for powers
    - cstdlib - for EXIT_FAILURE

### Compile script
    - Will need to compile `main.cpp`
    - Will make an executable called *frequencies*

********************************

## Milestone 2
### Problems to solve
    1. Make a vector of string with the names of the language files.
    2. Read from a file by reference, while reading count each trigram in the text and store in a frequency vector for each training language file.
    3. Compare frequency vector of the unknown language file to the frequency vectors of the training language files, by implementing the cosine similarity equation.
    4. Determine the language the unknown file is the most similar to.

### How to solve the problems
    1. Create a vector of strings with all of the names of training language files.
    2. Create a function that takes an ifstream. Converts each trigram that appears in the text file into a number and counts how many times each number appears, by creating a vector for each training language file and making the number represent an index in the vector.
    3. Create a function that takes in the frequency vector of the unknown test file and a frequency vector of a training language file, calculates the cosine similarity and returns a double value between 0 and 1.
    In `main()`, store all of the cosine similarity values in a vector, in the same order as the language string.
    4. After comparison of training language files to the unknown file, the value closest to 0 would be the most similar language to the unknown file.

### Classes needed:
    - None

### Other functions:
    - `freqVec()` reads the text from a file and converts each trigram that appears into a number and counts how many times each number appears, by creating a vector and making the number represent an index in the vector.
        - takes an ifstream of one language file.
        - returns a vector of integers, frequency of each trigram in the string.
    - `similarity()` calculates the similarity of two frequency vectors using the cosine similarity equation
        - takes two vectors as arguments.
        - returns a double, a value that represents the similarity of the two vectors
    - `main()`
        - test if command arguments are more than 2, if not throw an error.
        - creates a vector of strings with all of the names of the training language files.
        - calls `freqVec()` on every file (both training files and the test file)
        - calls `similarity()` in a loop for each of the training file and compare it to the test file and stores it in a vector of doubles
        - determines the index of the smallest value of the similarity vector and outputs the element with the corresponding index in the training languages  vector.

### Files needed
    - `main.cpp`

### Libraries needed
    - vector
    - string
    - iostream
    - fstream
    - cmath - for mathematical calculations
    - cstdlib - for EXIT_FAILURE

### Compile script
    - Will need to compile `main.cpp`
    - Will make an executable called *language*
