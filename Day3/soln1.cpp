#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream fin("input.txt");
    std::string input;
    int index1 = 1; //right 1 down 1
    int index2 = 3; //right 3 down 1
    int index3 = 5; //right 5 down 1
    int index4 = 7; //right 7 down 1
    int index5 = 1; //right 1 down 2
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 1;
    unsigned int total = 1;

    fin >> input;
    int length = input.size();
    while(fin >> input){
        if(input[index1] == '#'){
            counter1++;
        } 
        index1 = (index1+1) % length;

        if(input[index2] == '#'){
            counter2++;
        }
        index2 = (index2 + 3) % length;
        
        if(input[index3] == '#'){
            counter3++;
        }
        index3 = (index3 + 5) % length;

        if(input[index4] == '#'){
            counter4++;
        } 
        index4 = (index4 + 7) % length;
        
        
        if(counter6 % 2 == 0){
            if(input[index5] == '#'){
                counter5++;
            }
            index5 = (index5 + 1) % length;
        }
        counter6++;
    }

    total = counter1 * counter2 * counter3 * counter4 * counter5;
    std::cout << total << std::endl;
    
    return 0;
}