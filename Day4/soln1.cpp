#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
int main(){
    size_t valid_counter = 0;
    size_t i;
    std::unordered_map<std::string,std::string> myMap;
    std::string input = "blue";
    std::string k, v;
    // std::string mandatory_keys[7] = " ";
    unsigned int flag = 0; //if flag = 0 then k if 1 then v
    std::ifstream fin("input.txt");
    while(std::getline(fin,input)){
       //std::cout << input << " " << input.size() << std::endl;
        input += " ";
        if(input.size() == 1){ //end of pass port entries
            if(myMap.size()-1 < 8){
                if(myMap.find("cid") == myMap.end()){ //cid is not found
                    if(myMap.size()-1 == 7){
                        
                            valid_counter++; // if = 7 then cid is the only one missing
                        
                         
                    }
                }
            } else if (myMap.size()-1 == 8){
                
                    valid_counter++; // if = 7 then cid is the only one missing
                
            }
            //std::cout << std::endl << valid_counter << " " << myMap.size()-1 << std::endl;
            myMap.clear();
        }
        for(i = 0; i < input.size(); i++){
            if(input[i] == ' '){
                myMap[k] = v;
                k.clear();
                v.clear();
                flag = 0;
            } else if (input[i] == ':'){
                flag = 1;
            } else {
                if(flag == 0){
                    k += input[i];
                } else {
                    v += input[i];
                }
            } 
        }
        

    }
    
    std::cout << "Part 1: " << valid_counter+2 << std::endl;
    return 0;
}
