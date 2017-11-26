#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> freqVec(std::string str);
void error(std::string msg);

int main(int argc, char *argv[]){
    int size = argc;
    if (size != 2) error("Only take one command-line argument");
    std::string str = argv[1];

    std::vector<int> v = freqVec(str);
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
      std::cout << *i << ' ';

    std::cout << std::endl;

    return 0;
}

std::vector<int> freqVec(std::string str){
    std::vector<int> vec(pow(27,3), 0);

    int length = str.length();
    for (int i = 0; i < length - 2; i++){
        int index = 0;
        if ((str[i] - 96) < 0) str[i] = 96;
        if ((str[i+1] - 95) < 0) str[i+1] = 96;
        if ((str[i+2] - 94) < 0) str[i+2] = 96;

        index = (str[i] - 96) * pow(27, 2) + (str[i+1] - 96) * 27 + (str[i+2] - 96);
        std::cout << index << std::endl;
        vec[index] += 1;
    }
    return vec;
}

void error(std::string msg){
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}
