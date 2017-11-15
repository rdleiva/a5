a5

Assignment #5
Authors: Eydis Embla Ludviksdottir
         Rotman Daniel Leiva

Design Outline.

Problems to solve:
   1. Take language files and generate a string from the text.
   2. Generate a string to store the name of each language file.
   3. Count the trigrams in the text and store in a frequency vector.
   4. Compare frequency vector of the unknown language file to the frequency      vectors of the other language files.
   5. Determine the language the unknown file is the most similar to.

How to solve the problems:
   1. Create an infile function to take in language files and return a string of language text.
   2. N/A
   3. Create a function that takes in a string of language text, we loop through it and convert each trigram into a number with base 27 which will be the index of a vector of size 27^3.
   4. Implement cosine similarity equation in a function that takes in the frequency vector of the unknown file and a frequency vector of another language file, and returns a double value between 0 and 1. (Comparator function)
   Assign each cosine similarity value to a corresponding language.
   5. After comparison of language files to the unknown file, the value closest to 0 would be the most similar language to the unknown file.

Classes:
   1. 
