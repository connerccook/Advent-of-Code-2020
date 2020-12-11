#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


int getSeatRow(string& seat){
    unsigned int lower = 0, upper = 127;
    for(int i = 0; i < 7; i++){
        if(seat[i] == 'F') upper -= (upper - lower) / 2 + 1;
        if(seat[i] == 'B') lower += (upper - lower) / 2 + 1;
    }
    return lower;
}

int getSeatCol(string& seat){
    unsigned int lower = 0, upper = 7;
    for(int i = 7; i < seat.size(); i++){
        if(seat[i] == 'L') upper -= (upper - lower) / 2 + 1;
        if(seat[i] == 'R') lower += (upper - lower) / 2 + 1;
    }
    return lower;
}

int main(){
    ifstream input;
    string seat;
    vector<unsigned int> seats;
    unsigned int highestSeat = 0, seatID, row, col, mySeat;
    input.open("input.txt");
    while (!input.eof())
    {
        input >> seat;
        row = getSeatRow(seat);
        col = getSeatCol(seat);
        seatID = row * 8 + col;
        seats.push_back(seatID);
        if(seatID > highestSeat) {highestSeat = seatID;}
    } 
    sort(seats.begin(), seats.end());
    for(size_t i = 1; i < seats.size(); i++){
        if(seats[i]-1 != seats[i-1]){
            mySeat = seats[i] - 1;
            break;
        }
    }
    cout << highestSeat << endl;
    cout << mySeat << endl;
    input.close();
    return 0;
}