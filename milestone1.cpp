#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> freqVec(std::string str);

int main(int argc, char *argv[]){
    int size = argc;
    if (size != 2) throw std::runtime_error("Only takes one command-line argument")
    std::string str = argv[1];

    std::vector<int> v = freqVec(str);
/*
    for (std::vector<std::string>::const_iterator i = vec1.begin(); i != vec1.end(); ++i)
      std::cout << *i << " ";
*/
    return 0;
}

std::vector<int> freqVec(std::string str){
    std::std::vector<int> vec(27);


    return vec;
}
