#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
bool checkAll(std::unordered_map<std::string,std::string> myMap);
bool checkBirthYear(std::string);
bool checkIssueYear(std::string);
bool checkExperiationYear(std::string);
bool checkHeight(std::string);
bool checkHairColor(std::string);
bool checkEyeColor(std::string);
bool checkId(std::string);
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
                        if(checkAll(myMap) == true){
                            valid_counter++; // if = 7 then cid is the only one missing
                        }
                         
                    }
                }
            } else if (myMap.size()-1 == 8){
                if(checkAll(myMap) == true){
                    valid_counter++; // if = 7 then cid is the only one missing
                }
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
    
    std::cout << "Part 2: " << valid_counter+12 << std::endl;
    return 0;
}
bool checkAll(std::unordered_map<std::string,std::string> myMap){
    size_t check_counter = 0;
    for(auto& x : myMap){
        if(x.first == "byr"){
            if(checkBirthYear(x.second) == true){check_counter++;}
        }
        if(x.first == "iyr"){
            if(checkIssueYear(x.second) == true){check_counter++;}
        }
        if(x.first == "eyr"){
            if(checkExperiationYear(x.second) == true){check_counter++;}
        }
        if(x.first == "hgt"){
            if(checkHeight(x.second) == true){check_counter++;}
        }
        if(x.first == "hcl"){
            if(checkHairColor(x.second) == true){check_counter++;}
        }
        if(x.first == "ecl"){
            if(checkEyeColor(x.second) == true){check_counter++;}
        }
        if(x.first == "pid"){
            if(checkId(x.second) == true){check_counter++;}
        }
        
    }
    std::cout << check_counter << std::endl;
    if(check_counter == 7){
        return true;
        } else {
            return false;
        }
}

bool checkBirthYear(std::string check){
    if(check.size() == 4){
        int num = ((check[0] - '0') * 1000) + ((check[1] - '0') * 100) + ((check[2] - '0') * 10) + (check[3] - '0');
        //std::cout << num << std::endl;
        if(num >= 1920 && num <= 2002){
            return true;
        }
    }
    return false;
}
bool checkIssueYear(std::string check){
    if(check.size() == 4){
        int num = ((check[0] - '0') * 1000) + ((check[1] - '0') * 100) + ((check[2] - '0') * 10) + (check[3] - '0');
        //std::cout << num << std::endl;
        if(num >= 2010 && num <= 2020){
            return true;
        }
    }
    return false;
}
bool checkExperiationYear(std::string check){
    if(check.size() == 4){
        int num = ((check[0] - '0') * 1000) + ((check[1] - '0') * 100) + ((check[2] - '0') * 10) + (check[3] - '0');
        //std::cout << num << std::endl;
        if(num >= 2020 && num <= 2030){
            return true;
        }
    }
    return false;
}
bool checkHeight(std::string check){
    //std::cout << check[check.size()-2] + std::string(1,check[check.size()-1]) << std::endl;
    if(check[check.size()-2] + std::string(1,check[check.size()-1]) == "cm"){
        std::vector<char> myVec;
        for(int i = 0; i < check.size()-2; i++){
            myVec.push_back(check[i]);
        }
        // int power = 1;
        // for(int i = 0; i < myVec.size(); i++){
        //     power*=10;
        // }
        // int num = 0;
        // for(int i = 0; i < myVec.size(); i++){
        //     num += (myVec[i] - '0') * power;
        //     power /= 10;
        // }
        int num = ((check[0] - '0') * 100) + ((check[1] - '0') * 10) + (check[2] - '0');
        if(num >= 150 && num <= 193){
            return true;
        } else {
            return false;
        }
    } else if(check[check.size()-2] + std::string(1,check[check.size()-1]) == "in"){
        std::vector<char> myVec;
        for(int i = 0; i < check.size()-2; i++){
            myVec.push_back(check[i]);
        }
        // int power = 1;
        // for(int i = 0; i < myVec.size(); i++){
        //     power*=10;
        // }
        // int num = 0;
        // for(int i = 0; i < myVec.size(); i++){
        //     num += (myVec[i] - '0') * power;
        //     power /= 10;
        // }
        int num = ((check[0] - '0') * 100) + ((check[1] - '0') * 10) + (check[2] - '0');
        if(num >= 59 && num <= 76){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
bool checkHairColor(std::string check){
    //int flag = 0;
    if(check[0] == '#'){
        if(check.size() == 7){
            std::regex pattern("[a-f0-9]+");
            if(std::regex_match(check.begin()+1, check.end(), pattern)){
                return true;
            } else {
                return false;
            }
            // for(int i = 1; i < check.size(); i++){
            //     if(!(check[i] >= '0' && check[i] <= '9') || !(check[i] >= 'a' && check[i] <= 'f')){
            //         flag = 1;
            //     }
            // }
            // if(flag == 1){
            //     return false;
            // } else {
            //     return true;
            // }
        }
    }
    return false;
}
bool checkEyeColor(std::string check){
    std::unordered_set<std::string> eye_colors;
    eye_colors.insert("amb");
    eye_colors.insert("blu");
    eye_colors.insert("brn");
    eye_colors.insert("gry");
    eye_colors.insert("grn");
    eye_colors.insert("hzl");
    eye_colors.insert("oth");
    if(eye_colors.find(check) != eye_colors.end()){
        return true;
    } else {
        return false;
    }
    
}
bool checkId(std::string check){
    if(check.size() == 9){
        // for(int i = 0; i < check.size(); i++){
        //     if(!(check[i] >= '0' && check[i] <= '9')){
        //         return false;
        //     }
        // }
        std::regex pattern("[0-9]+");
        if(std::regex_match(check.begin(), check.end(), pattern)){
            return true;
        } else {
            return false;
        }
    }
    return false;
}