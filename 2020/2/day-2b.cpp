#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool checkPasswords(int minInterval, int maxInterval, char character, string password){
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
    int validPasswords = 0;
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
		if (checkPasswords(minInterval, maxInterval, character, password))
            validPasswords++;
	}
    input.close();
    cout << "Valid passwords: " << validPasswords;
    return 0;
}