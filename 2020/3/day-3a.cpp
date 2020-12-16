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
    long long pathEncounters = 0;
    while (!input.eof()){
        string line = "";
        getline(input, line);
        if (checkPath(line, activeRow, 3))
            pathEncounters++;
        activeRow++;
	}
    input.close();
    cout << "Tree encounters: " << pathEncounters;
    return 0;
}