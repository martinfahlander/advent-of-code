#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int countValidPassports(vector <string> &passportVector){
    int validPassports = 0;
    string field = "";
    for (int i = 0; i < passportVector.size(); i++){
        int obligatoryFields = 0;
        stringstream passportStream(passportVector[i]);
        while (getline(passportStream, field, ' ')){
            int byrValue = 0, iyrValue = 0, eyrValue = 0, hgtValue = 0;;
            string hgtUnit = "", hclValue = "", hclPrefix = "", eclValue = "", pidValue = "";
            if (field.substr(0, 4) == "byr:"){
                byrValue = stoi(field.substr(4, field.length() - 4));
                if(byrValue >= 1920 && byrValue <= 2002)
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "iyr:"){
                iyrValue = stoi(field.substr(4, field.length() - 4));
                if(iyrValue >= 2010 && iyrValue <= 2020)
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "eyr:"){
                eyrValue = stoi(field.substr(4, field.length() - 4));
                if(eyrValue >= 2020 && eyrValue <= 2030)
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "hgt:"){
                hgtUnit = field.substr(field.length() - 2, field.length());
                hgtValue = stoi(field.substr(4, field.length() - 2));
                if(hgtUnit == "cm" && hgtValue >= 150 && hgtValue <= 193)
                    obligatoryFields++;
                else if (hgtUnit == "in" && hgtValue >= 59 && hgtValue <= 76)
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "hcl:"){
                hclValue = field.substr(5);
                hclPrefix = field.substr(4, 1);
                bool hex = false;
                for (char x : hclValue)
                    if (isxdigit(x))
                        hex = true;
                if(hclPrefix == "#" && hex)
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "ecl:"){
                eclValue = field.substr(4, field.length() - 4);
                if (eclValue == "amb" ||
                    eclValue == "blu" || 
                    eclValue == "brn" || 
                    eclValue == "gry" ||
                    eclValue == "grn" ||
                    eclValue == "hzl" ||
                    eclValue == "oth")
                    obligatoryFields++;
            } else if (field.substr(0, 4) == "pid:"){
                pidValue = field.substr(4, field.length() - 4);
                bool num = false;
                for (char x : pidValue)
                    if (isdigit(x))
                        num = true;
                if(num && pidValue.length() == 9)
                    obligatoryFields++;
            }
        }
        if (obligatoryFields >= 7)
            validPassports++;
    }
    return validPassports;
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
    int validPassports = countValidPassports(passportVector);
    cout << "Valid passports: " << validPassports;
    return 0;
}