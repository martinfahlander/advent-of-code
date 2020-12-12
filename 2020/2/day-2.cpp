#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

bool checkCharOccurrence(int minInterval, int maxInterval, char character, string password){
    int occurrence = count(password.begin(), password.end(), character);
    if (occurrence >= minInterval && occurrence <= maxInterval)
        return true;
    else
        return false;
}

bool checkCharPosition(int minInterval, int maxInterval, char character, string password){
    char firstPosition = password.at(minInterval - 1);
    char secondPosition = password.at(maxInterval - 1);
    if (firstPosition == character ^ secondPosition == character)
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
    string intervalString = "";
    string characterString = "";
    string password = "";
    int validCharOccurrence = 0;
    int validCharPosition = 0;
    while (!input.eof()){
        input >> intervalString;
        string minIntervalString =  intervalString.substr(0, intervalString.find('-'));
        string maxIntervalString = intervalString.substr(intervalString.find('-') + 1, intervalString.length());
        stringstream ssMin(minIntervalString);
        stringstream ssMax(maxIntervalString);
        int minInterval = 0;
        int maxInterval = 0;
        ssMin >> minInterval;
        ssMax >> maxInterval;

        input >> characterString;
        char character = characterString.at(0);
        
        input >> password;

		if (checkCharOccurrence(minInterval, maxInterval, character, password))
            validCharOccurrence++;
        if (checkCharPosition(minInterval, maxInterval, character, password))
            validCharPosition++;
	}
    input.close();
    cout << "Part One: " << validCharOccurrence << "\nPart Two: " << validCharPosition;
    return 0;
}