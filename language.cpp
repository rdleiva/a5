/*
Final Project
Authors: Eydis Embla Ludviksdottir
         Rotman Daniel rdleiva
File: language.cpp converts a string into a sparse frequency vector and outputs it.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>


/*
Function Prototypes
*/
std::vector<int> freqVec(std::ifstream &infile);
void error(std::string msg);
double similarity(std::vector<int> vec1, std::vector<int> vec2);

int main(int argc, char *argv[]){
    int size = argc;
    if (size < 2) error("Must provide more at least 2 files!");

    for (int i = 1; i < size-2; i++){
        std::string languageNames[i-1] = argv[i];
    }

    std::vector<double> similarityVec(size-2);
    for (int i = 0; i < size-2; i++){
        /*call similarity() for each of the training file and
        compare it to the test file and stores it in a vector of doubles

        Can I pass two different freqVec functions to the similarity function?
        */
    }//end of for loop
    return 0;
}//end of main

/*
Converts each trigram that appears in a string into a number index and counts how many times each number appears.
Creates a frequency vector vec, and makes the number represent an index in the vector.
Loops through each trigram until the last trigram, when the index is length - 2.

returns the frequency vector.
*/
std::vector<int> freqVec(std::ifstream &infile){
    /*
    initialize a zero vector of size 27^3.
    */

    std::vector<int> vec(pow(27,3), 0);
    if (!infile.fail()){
        while (infile.get(ch)){

            for (int i = 0; i < length - 2; i++){
                int index = 0;
                /*
                check if an element in the string is a space,
                if so set equal to 96 to reset the value of space.
                */
                if ((str[i] - 96) < 0) str[i] = 96;
                if ((str[i+1] - 95) < 0) str[i+1] = 96;
                if ((str[i+2] - 94) < 0) str[i+2] = 96;
                /*
                Since we are only using the lower case alphabet we reset the decimal values for each letter,
                so it starts at one and increments with each letter.
                Before, space is set equal to 96 which makes space equal to zero after we reset everything.
                After converting the trigram to a number, one is added to the vector with the corresponding index.
                */
                index = (str[i] - 96) * pow(27, 2) + (str[i+1] - 96) * 27 + (str[i+2] - 96);
                vec[index] += 1;
            } //end of for loop
        } //end of while loop
        infile.close();
    } else {
        error("Could not open file")
    }

    return vec;
} //end of freqVec

double similarity(std::vector<int> vec1, std::vector<int> vec2){

    double nom = 0.0, denA = 0.0, denB = 0.0;
    for (int i = 0; i < pow(27,3); i++){ //++i?
        nom += vec1[i] * vec2[i];
        denA += pow(vec1[i], 2);
        denB += pow(vec2[i], 2);
    } //end of for loop

    return nom / (sqrt(denA) * sqrt(denB));
} //end of similarity

/*
Outputs errors to cerr and exits program.
Takes in a string message.
*/
void error(std::string msg){
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}
