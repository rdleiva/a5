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

const int VEC_LENGTH = pow(27,3);

//FIGURE OUT READING FROM THE COMMAND LINE, IT'S NOT IN QUOTES SO IT'S LIKE A LINKED LIST
int main(int argc, char *argv[]){
    int size = argc;
    if (size < 2) error("Must provide more at least 2 files!");

    for (int i = 1; i < size-2; i++){
        std::vector<std::string> languageNames[i-1] = argv[i];
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
Reads one character at a time from a file, and stores three letters at a time in a trigram string str
Calls getIndex() for each trigram and adds one to the element in the frequency vector vec with the corresponding index
Creates a frequency vector vec, and makes the number represent an index in the vector.

returns the frequency vector.
*/
std::vector<int> freqVec(std::ifstream &infile){
    /*
    initialize a zero vector of size 27^3.
    */
    std::vector<int> vec(VEC_LENGTH, 0);
    std::string str = "000";
    if (!infile.fail()){
        while (infile.get(ch)){
            if (ch == '\0') continue; //does continue make it skip that reding and go to the next loop of the while
            else if (str[0] == '0') str[0] = ch;
            else if (str[1] == '0') str[1] = ch;
            else {
                str[2] = ch;
                int index = getIndex(str);
                vec[index] += 1;
                str[0] = str[1];
                str[1] = str[2];
            }
        } //end of while loop
        infile.close();
    } else {
        error("Could not open file");
    }

    return vec;
} //end of freqVec

/*
Converts the trigram that is passed to the function as a string into a number with base 27,
which will represent the index for that specific trigram.

returns the index.
*/

int getIndex (std::string str){
    for (int i = 0; i < 3; i++){
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
        */
        index = (str[i] - 96) * pow(27, 2) + (str[i+1] - 96) * 27 + (str[i+2] - 96);
    }//end of for loop

    return index;
}

double similarity(std::vector<int> vec1, std::vector<int> vec2){

    double nom = 0.0, denA = 0.0, denB = 0.0;
    for (int i = 0; i < VEC_LENGTH; i++){ //++i?
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
