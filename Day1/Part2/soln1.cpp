#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
int main(){
    std::ifstream fin("../input.txt");
    int num1, num2, num3, input, left, right, currentSum;
    int target = 2020;
    std::vector<int> array;
    while(fin >> input){
        array.push_back(input);
    }
    std::sort(array.begin(), array.end());

    for(int i = 0; i < array.size() - 1; i++){
        int left = i + 1;
        int right = array.size() - 1;
        while(left < right){
            currentSum = array[i] + array[left] + array[right];
            if(currentSum == target){
                num1 = array[i];
                num2 = array[left];
                num3 = array[right];
                std::cout << array[i] << " " << array[left] << " " << array[right] << std::endl;
                left++;
                right--;
            } else if(currentSum < target){
                left++;
            } else if(currentSum > target){
                right--;
            }
        }
    }
    std::cout << num1 + num2 + num3 << std::endl;
    std::cout << num1 * num2 * num3 << std::endl;
    return 0;
}