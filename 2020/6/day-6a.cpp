#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

int countQuestions(string group){
    string uniqueCharacters = "";
    for (int i = 0; i < group.length(); i++){
        char character = group.at(i);
        if (uniqueCharacters.find(character) == string::npos)
            uniqueCharacters += character;
    }
    int sumUniqueCharacters = uniqueCharacters.length();
    return sumUniqueCharacters;
}

int main () {
    ifstream input;
    input.open("input.txt");
    if (!input) {
        cout << "No input found";
        exit(1);
    }
    int questionCount = 0;
    vector <int> questionCountVector;
    string group = "";
    vector <string> groupVector;
    while (!input.eof()){
        for(string line; getline(input, line);){
            if (line.empty()){
                groupVector.push_back(group);
                group = "";
            }
            group += line;
        }
        groupVector.push_back(group);
    }
    for (int i = 0; i < groupVector.size(); i++){
        questionCount += countQuestions(groupVector[i]);
        questionCountVector.push_back(questionCount);
        questionCount = 0;
    }
    int totalQuestionCount = accumulate(questionCountVector.begin(), questionCountVector.end(), 0);
    cout << "Total questions: " << totalQuestionCount;
    return 0;
}