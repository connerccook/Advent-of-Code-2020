#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream fin("input.txt");
    std::string input;
    int index = 3;
    int counter = 0;
    fin >> input;
    int length = input.size();
    while(fin >> input){
        //std::cout << input << std::endl;
         if(input[index] == '#'){
            counter++;
        }
        index = (index + 3) % length;
        //std::cout << index << " " << input[index] << " " << input.size() << std::endl;
    }
    std::cout << counter << std::endl;
    return 0;
}