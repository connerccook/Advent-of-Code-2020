#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(){
    std::ifstream inFile("../input.txt");
    unsigned int input;
    std::unordered_set<unsigned int> mySet;
    int target = 2020;
    int num1, num2;
    bool isFound = false;
    while(inFile >> input){
        mySet.insert(input);
    }
    for (auto& x : mySet) { 
        if(mySet.find(target-x) != mySet.end()){
            num1 = x;
            num2 = target-x;
            break;
        }
    } 
    std::cout << num1*num2 << std::endl;

    return 0; 
}