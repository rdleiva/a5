a5
## Assignment #5
## Authors: Eydis Embla Ludviksdottir, Rotman Daniel Leiva
## Emails:  eydisembla@my.uri.edu,     rdleiva@my.uri.edu

## Design Outline

## Problems to solve
   1. Take language files and generate a string from the text.
   2. **Generate a string to store the name of each language file.**
   3. Count each trigram in the text and store in a frequency vector.
   4. Compare frequency vector of the unknown language file to the frequency vectors of the other language files.
   5. Determine the language the unknown file is the most similar to.

## How to solve the problems
   1. Create an infile function to take in language files and return a string of language text.
   2. **N/A**
   3. Create a function that takes in a string of language text, we loop through it and convert each trigram into a number with base 27 which will be the index of a vector of size 27^3.
   4. Implement cosine similarity equation in a function that takes in the frequency vector of the unknown file and a frequency vector of another language file, and returns a double value between 0 and 1. (Comparator function)
   Assign each cosine similarity value to a corresponding language.
   5. After comparison of language files to the unknown file, the value closest to 0 would be the most similar language to the unknown file.

## Classes needed
   1. Language class to represent a text and it's language
      - private instance variables for text and name of the language
          - both are `std::string`s
      - Needs a constructor method that allows creating an object from a file
      - Needs accessors for the instance variables

## Other functions
    - `trigFreq()` that generates a vector of trigram frequency for the language, each trigram is converted into a number which represents an index in the vector
                - takes a string of one language as an argument
                - returns a vector of integers, frequency of each trigram in the string
    - `similarity()` that calculates the similarity of two frequency vectors using the cosine similarity equation
                - takes two vectors as arguments
                - returns a double, a value that represents the similarity of the two vectors
    - function

    - **how to determine the smallest value?? we don't know how many values we will have
                - return/output the name of the language which has the smallest value**
    - comparison function which compares the similarity values??
                - returns true if ..

## Milestone 1 `main()` structure
   - Test for generation of trigram frequencies.
   - Takes in only one string argument. Exits with an error otherwise.
   - Generate trigram frequency vector from string argument.
   - Output frequency vector values in indexed order from `___` to `zzz` (0-19,683).

## Milestone 2 `main()` structure
   - Test for known language text files language similarity to unknown file.
   - Takes multiple arguments. Exits with an error if only one argument is provided.
   - Generate trigram frequencies of all arguments given.
   - The first n number of arguments will be compared to the n-1th arguments.
   - n-1th argument will be assigned the most similar nth argument's language name
   - Output name of n-1th argument.

## Files needed
  - `language.h` and `language.cpp` for language Class.
  - `main.cpp` to test the language detection.

## Libraries needed
  - vector
  - string
  - iostream (and fstream)

## Compile script
  - Will need to compile language.cpp and main.cpp
  - flag?
