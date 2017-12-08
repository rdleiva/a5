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
#include <fstream>

/*
Function Prototypes
*/

std::vector<int> freqVec(std::ifstream &infile);
void error(std::string msg);
double similarity(std::vector<int> vec1, std::vector<int> vec2);
int getIndex (std::string str);

const int VEC_LENGTH = 27 * 27 * 27;


int main(int argc, char *argv[]){
    int size = argc;
    if (size < 2) error("Must provide at least 2 files!");

    char* testFile = argv[size-1];

    std::vector<char*> langNames;

    /*
    looping through the command line arguments except the first and the last one
    and pushing it to the vector langNames
    */
    for(int i = 1; i < size-1; i++){
        char* str = argv[i];
        langNames.push_back(str);
    }

    /*
    ifstream f(argv[i]);
    vector = getfreq(&f);
    */

    //std::cout << argv[1] << std::endl;
    //std::cout << testFile << std::endl;
    //std::cout << langNames[0] << std::endl;

    std::vector<double> similarityVec;
    std::ifstream f;
    f.open(testFile);
    //std::cout << testFile << std::endl;
    std::vector<int> v1 = freqVec(f);
    f.close();

    for(size_t i = 0; i < langNames.size(); i++){
        std::ifstream fi;
        fi.open(langNames[i]);
        //std::cout << langNames[i] << std::endl;
        std::vector<int> v2 = freqVec(fi);
        similarityVec.push_back(similarity(v1, v2));
        fi.close();
    }

    /*
    looping through the similarityVec to find the greatest value
    */
    int m = 2;
    for(size_t i = 1; i < similarityVec.size() ; i++){
        if(similarityVec[i]>m)
        m = i;
    }
    std::cout<< langNames[m] << std::endl;;

    //}//end of for loop
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
    char ch;
    if (!infile.fail()){
        while (infile.get(ch)){
            if (ch == '\0') continue;
            else if (str[0] == '0') str[0] = ch;
            else if (str[1] == '0') str[1] = ch;
            else {
                str[2] = ch;
                //std::cout << str << std::endl;
                int index = getIndex(str);
                //std::cout << index << std::endl;
                vec[index] += 1;
                str[0] = str[1];
                str[1] = str[2];
            }
        } //end of while loop
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
    int index = 0;
    /*
    check if an element in the string is a space,
    if so set equal to 96 to reset the value of space.
    */
    if ((str[0] - 96) < 0) str[0] = 96;
    if ((str[1] - 95) < 0) str[1] = 96;
    if ((str[2] - 94) < 0) str[2] = 96;
    /*
    Since we are only using the lower case alphabet we reset the decimal values for each letter,
    so it starts at one and increments with each letter.
    Before, space is set equal to 96 which makes space equal to zero after we reset everything.
    */
    index = (str[0] - 96) * pow(27, 2) + (str[1] - 96) * 27 + (str[2] - 96);

    return index;
}

/*
Computes the cosine similarity of the two vectors passed to the function,
does that by computing the numerator and each part of the denominator separately,
and then combine the values together in the end as numerator over the product of each part of the denominator.

returns the similarity value
*/

/*
use unsigned long long as long as you can!!
*/

double similarity(std::vector<int> vec1, std::vector<int> vec2){

    /*
    looping through the frequency vector,
    numerator: adds the products of the elements in the vectors with the same indexes.
    denominator 1: adds the squared element in vec1.
    denominator 2: adds the squared element in vec2.
    */
    double num = 0.0, den1 = 0.0, den2 = 0.0;
    for (int i = 0; i < VEC_LENGTH; i++){ //++i?
        num += vec1[i] * vec2[i];
        den1 += pow(vec1[i], 2);
        den2 += pow(vec2[i], 2);
    } //end of for loop

    return num / (sqrt(den1) * sqrt(den2));
} //end of similarity

/*
Outputs errors to cerr and exits program.
Takes in a string message.
*/
void error(std::string msg){
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}
