#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream fin("input.txt");
    unsigned int valid_counter_1 = 0;
    unsigned int valid_counter_2 = 0;
    std::string num_range, letter, password;
    int range_begin, range_end;
    size_t dash_pos;

    while(fin >> num_range >> letter >> password){
        dash_pos = num_range.find("-");
        if(dash_pos == 1) {
            if(num_range.size() == 3) {
                range_begin = num_range[0] - '0';
                range_end = num_range[2] - '0';
            } else if (num_range.size() == 4) {
                range_begin = num_range[0] - '0';
                range_end = (num_range[2] - '0') * 10 + (num_range[3] - '0');
            }
        } else if (dash_pos == 2){
            if(num_range.size() == 4){
                range_begin = (num_range[0] - '0') * 10 + (num_range[1] - '0');
                range_end = num_range[3] - '0';
            } else if (num_range.size() == 5){
                range_begin = (num_range[0] - '0') * 10 + (num_range[1] - '0');
                range_end = (num_range[3] - '0') * 10 + (num_range[4] - '0');
            }
        } 
        int counter1 = 0;
        for(int i = 0; i < password.size(); i++){
            if(password[i] == letter[0]) {
                counter1++;
            }
        }
        if(counter1 >= range_begin && counter1 <= range_end){
            valid_counter_1++;
        }
        
        if(letter[0] == password[range_begin-1] && letter[0] != password[range_end-1]){
            valid_counter_2++;
        } else if(letter[0] != password[range_begin-1] && letter[0] == password[range_end-1]){
            valid_counter_2++;
        }   
        std::cout << range_begin << " " << range_end << " " << letter[0] << " " << counter1 << " " << valid_counter_2 << std::endl;     
    }
    std::cout << "Part 1: " << valid_counter_1 << std::endl;
    std::cout << "Part 2: " << valid_counter_2 << std::endl;
    return 0;
}