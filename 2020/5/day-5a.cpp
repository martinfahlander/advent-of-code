#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int getRow(string boardingPass){
    int min = 0, max = 127, row = 0;
    for (int i = 0; i < 7; i++){
        if (boardingPass.at(i) == 'F')
            max = max - 64 / pow(2, i);
        else if (boardingPass.at(i) == 'B')
            min = min + 64 / pow(2, i);
    }
    if (min == max)
        row = min;
    return row;
}

int getCol(string boardingPass){
    int min = 0, max = 7, col = 0;
    for (int i = 0; i < 3; i++){
        if (boardingPass.at(i + 7) == 'L')
            max = max - 4 / pow(2, i);
        else if (boardingPass.at(i + 7) == 'R')
            min = min + 4 / pow(2, i);
    } 
    if (min == max)
        col = min;
    return col;
}

int main () {
    ifstream input;
    input.open("input.txt");
    if (!input) {
        cout << "No input found";
        exit(1);
    }
    string boardingPass = "";
    vector <int> seatID;
    int row = 0, col = 0;
    while (!input.eof()){
        getline(input, boardingPass);
        row = getRow(boardingPass);
        col = getCol(boardingPass);
        seatID.push_back(row * 8 + col);
    }
    double maxSeatID = *max_element(seatID.begin(), seatID.end());
    cout << "Highest seat ID: " << maxSeatID;
    return 0;
}