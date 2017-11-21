# Design Document for Final Project
### Authors: Eydis Embla Ludviksdottir, Rotman Daniel Leiva
### Emails:  eydisembla@my.uri.edu,     rdleiva@my.uri.edu


## Milestone 1
### Problems to solve
    - Test how many command arguments there are
    - Count how many times each trigram appears in a string from the command line and stores it in a vector
    - Output the frequency vector in the correct order, from `   ` to `zzz`, separated by space.

### How to solve the problems
    - Store command line argument in a string, if there is less than, or more than one argument, EXIT_FAILURE.
    - Create a function that takes a string, loops through it and converts each trigram into a number with base 27, which will be the index that represents the trigram in the frequency vector.
    - Output each element in the vector through a for loop and place a space between each

### Classes needed:
    - None

### Other functions:
    - `freqVec()` converts each trigram that appears in a string into a number and counts how many times each number appears, by creating a vector and making the number represent an index in the vector.
        - takes a string as an argument, **by a reference**.
        - returns a vector of integers, frequency of each trigram in the string
    - `main()`
        - takes the command line as an argument, argv, and its size, argc.
        - tests if the command line is only one argument, else throws an error.
        - calls the freqVec **and passes a pointer to the string or just the string?**.
        - output each element in the vector through a for loop and place a space between each.

### Files needed
    - `frequencies.cpp` to calculate the frequency vector

### Libraries needed
    - vector
    - string
    - **iostream??**
    - cmath - for powers
    - cstdlib - for EXIT_FAILURE

### Compile script
    - Will need to compile `frequency.cpp`

    *****************************

## Milestone 2
### Problems to solve
    - Make a string with the names of the language files
    - Read from a file by reference, while reading count each trigram in the text and store in a frequency vector.
    - Compare frequency vector of the unknown language file to the frequency vectors of the other language files, by implementing the cosine similarity equation.
    - Determine the language the unknown file is the most similar to.

### How to solve the problems
    - Make a string of size argc-2 with all of the language files to compare to, start with index 1.
    - Create a function that takes an ifstream. Converts each trigram that appears in the text file into a number and counts how many times each number appears, by creating a vector and making the number represent an index in the vector.
    - Create a function that takes in the frequency vector of the unknown file and a frequency vector of another language file, and returns a double value between 0 and 1.
    Store all of the cosine similarity values in a vector, in the same order as the language string.
    - After comparison of language files to the unknown file, the value closest to 0 would be the most similar language to the unknown file.

### Classes needed:
    - None

### Other functions:
    - `freqVec()`
    - `similarity()`
    - `main()`

### Files needed
    (- `language.h` and `language.cpp` for language Class.)
    - `main.cpp` to test the language detection.

### Libraries needed
    - vector
    - string
    - iostream
    - fstream
    - cmath - for cosine
    - cstdlib - for EXIT_FAILURE

### Compile script
    - Will need to compile language.cpp and main.cpp


     **************************************


## Classes needed
**could pass a file stream**
    1. Language class to represent a text and its language
        - private instance variables for **text, no** and name of the language
        - both are `std::string`s
        - Needs a constructor method that allows creating an object from a file
        - Needs accessors for the instance variables

## Other functions
    - `trigramFreq()` **in class!!** that generates a vector of trigram frequency for the language, each trigram is converted into a number which represents an index in the vector
                **- //no , fstream? takes a string of one language as an argument**
                - returns a vector of integers, frequency of each trigram in the string
    - `similarity()` that calculates the similarity of two frequency vectors using the cosine similarity equation
                - takes two vectors as arguments
                - returns a double, a value that represents the similarity of the two vectors
    - function

    - **how to determine the smallest value?? we don't know how many values we will have
                - return/output the name of the language which has the smallest value

                dynamic array of cosine similarities
                loop through, set the first value equal to the smallest and test**

    - comparison function which compares the similarity values??
                - returns true if ..

## Milestone 1 `main()` structure

**Do we need to include the frequency vector function that takes a string (not an infile like for m2)??**
**should not have tests! we need to test everything but have it commented out (take out before submit)**
    - Test for generation of trigram frequencies.
    - Takes in only one string argument. Exits with an error otherwise.
    - Generate trigram frequency vector from string argument.
    - Output frequency vector values in indexed order from `___` to `zzz` (0-19,683). **specify**

## Milestone 2 `main()` structure
**should not have tests! we need to test everything but have it commented out**
**file io**
**cosine similarity vector?**
    - Test for known language text files language similarity to unknown file. **calls method x**

    - Takes multiple arguments **specify**. Exits with an error if only one argument is provided.
    - Generate trigram frequencies of all arguments given. **calls method y**
    - The frequency vector for the last argument (unknown Language file) is compared to the frequency vector of all of the other languages (using cosine similarity) **calling? types**
    - Output name of most similar language (smallest cosine similarity value).

## Files needed
    - `language.h` and `language.cpp` for language Class.
    - `main.cpp` to test the language detection.

## Libraries needed
    - vector
    - string
    - iostream (and fstream)
    - cmath - for cosine
    - cstdlib - for EXIT_FAILURE

## Compile script
    - Will need to compile language.cpp and main.cpp
    - flag?
