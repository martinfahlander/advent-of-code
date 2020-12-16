#include <iostream>
#include <fstream>
using namespace std;

bool checkPath(string line, int activeRow, int right){
    int position = (activeRow * right) % line.length();
    char activeChar = line.at(position);
    if (activeChar == '#')
        return true;
    else
        return false;
}

int main () {
    ifstream input;
    input.open("input.txt");
    if (!input) {
        cout << "No input found";
        exit(1);
    }
    int activeRow = 0;
    long long path1Encounters = 0, path2Encounters = 0, path3Encounters = 0, path4Encounters = 0, path5Encounters = 0;
    while (!input.eof()){
        string line = "";
        getline(input, line);
        if (checkPath(line, activeRow, 1))
            path1Encounters++;
        if (checkPath(line, activeRow, 3))
            path2Encounters++;
        if (checkPath(line, activeRow, 5))
            path3Encounters++;
        if (checkPath(line, activeRow, 7))
            path4Encounters++;
        if (activeRow % 2 == 0)
            if (checkPath(line, activeRow / 2, 1)){
                path5Encounters++;
            }
        activeRow++;
	}
    input.close();
    long long multipliedEncounters = path1Encounters * path2Encounters * path3Encounters * path4Encounters * path5Encounters;
    cout << "Multiplied tree encounters: " << multipliedEncounters;
    return 0;
}