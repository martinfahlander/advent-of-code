#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int countValidPassports(vector <string> &passportVector){
    int validCount = 0;
    for (int i = 0; i < passportVector.size(); i++){
        if (passportVector[i].find("byr:") != string::npos && 
            passportVector[i].find("eyr:") != string::npos &&
            passportVector[i].find("iyr:") != string::npos && 
            passportVector[i].find("hgt:") != string::npos && 
            passportVector[i].find("hcl:") != string::npos &&
            passportVector[i].find("ecl:") != string::npos && 
            passportVector[i].find("pid:") != string::npos ){
            validCount++;
        }
    }
    return validCount;
}

int main () {
    ifstream input;
    input.open("input.txt");
    if (!input) {
        cout << "No input found";
        exit(1);
    }
    string passport = "";
    vector <string> passportVector;
    while (!input.eof()){
        for(string line; getline(input, line);){
            if (line.empty()){
                passportVector.push_back(passport);
                passport = "";
                continue;
            }
            if (passport.length() > 0){
                passport += " ";
            }
            passport += line;
        }
        passportVector.push_back(passport);
	}
    input.close();
    int validPassport = countValidPassports(passportVector);
    cout << "Valid passports: " << validPassport;
    return 0;
}