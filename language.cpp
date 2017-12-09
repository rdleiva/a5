/*
CSC 211
Final Project   12/11/2017
Professor:  Noah Daniels
Authors:    Eydis Embla Ludviksdottir, eydisembla@my.uri.edu
            Rotman Daniel, rdleiva@my.uri.edu
File: language.cpp
      Compares one unknown language file to at least one known language file,
      and determines which file the unknown one is most similar to.
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

    /*
    looping through the command line arguments except the first and the last one,
    and store them in a vector, langNames.
    */
    std::vector<char*> langNames;
    for(int i = 1; i < size-1; i++){
        char* str = argv[i];
        langNames.push_back(str);
    }

    /*
    making a freguency vector for the last command line argument file, test file.
    */
    char* testFile = argv[size-1];
    std::ifstream f;
    f.open(testFile);
    std::vector<int> v1 = freqVec(f);
    f.close();

    /*
    looping through the langNames vector, opening each file and making a trigram frequency vector.
    Then calculating the cosine similarity of that vector and the test file vector, and store it in a similarity vector.
    */
    std::vector<double> similarityVec;
    for(size_t i = 0; i < langNames.size(); i++){
        std::ifstream fi;
        fi.open(langNames[i]);
        std::vector<int> v2 = freqVec(fi);
        similarityVec.push_back(similarity(v1, v2));
        fi.close();
    }

    /*
    looping through the similarityVec to find greatest value,
    storing the index of the greatest value as n.
    */
    double m = similarityVec[0];
    int n = 0;
    for(size_t i = 1; i < similarityVec.size(); i++){
        if (similarityVec[i] > m){
            m = similarityVec[i];
            n = i;
        } //end of if statement
    } //end of for loop

    /*
    outputting the file name with the index that represented the greatest value in the similarity vector.
    */
    std::cout<< langNames[n] << std::endl;;

    return 0;
} //end of main

/*
Reads one character at a time from a file, and stores three letters at a time in a trigram string str
Calls getIndex() for each trigram and adds one to the element in the frequency vector vec with the corresponding index
Creates a frequency vector vec, and makes the number represent an index in the vector.

returns the frequency vector.
*/
std::vector<int> freqVec(std::ifstream &infile){
    /*
    initialize a zero vector of size 27^3,
    and a basecase trigram string of three zeros.
    */
    std::vector<int> freqVec(VEC_LENGTH, 0);
    std::string trigram = "000";
    char ch;

    /*
    Reading one character at a time from the file,
    */
    if (!infile.fail()){
        /*
        While reading from infile move the trigram "000" one character at a time along the infile,
        starting from the first character of the language file all the way to the last one.
        Get the index of each trigram, if there are no zeros in the trigram,
        and add one to the element of the frequency vector with the corresponding index.
        */
        while (infile.get(ch)){
          if (ch == '\n') break;
          trigram.push_back(ch);
          trigram.erase(trigram.begin());
          if (trigram[0] != '0'){
              int index = getIndex(trigram);
              freqVec[index] += 1;
            }
        } //end of while loop
    } else {
        error("Could not open file");
    }

    return freqVec;
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
double similarity(std::vector<int> vec1, std::vector<int> vec2){

    /*
    looping through the frequency vector, computing the numerator and the two parts of the denominator.
    */
    unsigned long long num = 0, den1 = 0, den2 = 0;
    for (size_t i = 0; i < VEC_LENGTH; i++){
        num += vec1[i] * vec2[i];
        den1 += vec1[i] * vec1[i];
        den2 += vec2[i] * vec2[i];
    } //end of for loop

    return ((double) num / ((double)(sqrt(den1) * sqrt(den2))));
} //end of similarity

/*
Outputs errors to cerr and exits program.
Takes in a string message.
*/
void error(std::string msg){
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}
