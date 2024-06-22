#include <iostream>
#include "header.h"

int main() {
    myVector <int> vec(1);
    for (int i = 0; i < 6; i++) {vec.push_back(i+1);}
    vec.pop_back();
    myVector <int> oth = vec;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << oth[i] << std::endl;
    }
    //std::cout << "asdads\n";
    return 0;
}
