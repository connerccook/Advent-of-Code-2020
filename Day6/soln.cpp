#include <iostream>
#include <fstream>
#include <set> //only holds unique values
#include <unordered_map>
int main(){
    std::ifstream fin;
    std::set<char> mySet;
    std::unordered_map<char,int> myMap;
    std::string input, yes;
    unsigned int total1 = 0, total2 = 0, person_Count = 0;
    fin.open("input.txt");
    while(std::getline(fin, input)){
        if(input == ""){
            total1 += mySet.size();
            for(auto i = myMap.begin(); i != myMap.end(); i++){ //auto to make it an iterator of myMap so i is pointing to myMap[i] 
                if(i->second == person_Count){ //i -> second is the pointing to the value which is the int 
                    total2++;
                }
            }
            person_Count = 0;
            myMap.clear();
            mySet.clear();
        } else {
            person_Count++;
            for(size_t i=0; i < input.size(); i++){
                mySet.insert(input[i]);
                myMap[input[i]]++; // you are able to input a new key value pair like this even if it wasnt there in the first place really useful
            }
        }
    }
    total1 += mySet.size();
    for(auto i = myMap.begin(); i != myMap.end(); i++){
        if(i->second == person_Count){
        total2++;
        }
    }
    std::cout << "Part 1: " << total1 << std::endl;
    std::cout << "Part 2: " << total2 << std::endl;
    fin.close();
    return 0;
}

