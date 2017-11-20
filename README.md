## Final Project
## Authors: Eydis Embla Ludviksdottir, Rotman Daniel Leiva
## Emails:  eydisembla@my.uri.edu,     rdleiva@my.uri.edu

## Design Outline

## Problems to solve
   1. Take language files and generate a string from the text.
   2. **Generate a string to store the name of each language file. No, string would be too long**
   3. Count each trigram in the text and store in a frequency vector.
   4. Compare frequency vector of the unknown language file to the frequency vectors of the other language files.
   5. Determine the language the unknown file is the most similar to.

## How to solve the problems
   1. Create an infile function to take in language files and return a string of language text. //no
   2. **N/A**
   3. Create a function that takes in a string of language text, **no** we loop through it and convert each trigram into a number with base 27 which will be the index of a vector of size 27^3.
   4. Implement cosine similarity equation in a function that takes in the frequency vector of the unknown file and a frequency vector of another language file, and returns a double value between 0 and 1. (Comparator function)
   Assign each cosine similarity value to a corresponding language.
   5. After comparison of language files to the unknown file, the value closest to 0 would be the most similar language to the unknown file.

   **process the text while reading it - create the frequency vector while reading it**

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
