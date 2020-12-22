#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int countQuestions(vector <string> group) {
    vector <string> uniqueCharacters;
    string temp = group[0];
    cout << temp << endl;
    for (int x = 1; x < group.size(); x++) {
        for (int y = 0; y < temp.length(); y++){
            char character = temp.at(y);
            if (group[x].find(character) == string::npos){
                temp.erase(remove(temp.begin(), temp.end(), character), temp.end());
                y--;
            }
        }
        cout << group[x] << endl;
    }
    cout << "- Resultat: " << temp << endl;
    int sumUniqueCharacters = temp.length();
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
    vector <string> group;
    vector <vector <string>> groupVector;    
    while (!input.eof()){
        for(string line; getline(input, line);) {
            if (line.empty()){
                groupVector.push_back(group);
                group.clear();
                continue;
            }
            group.push_back(line);
        }
        groupVector.push_back(group);
    }
    for (int i = 0; i < groupVector.size(); i++) {
        questionCount += countQuestions(groupVector[i]);
        questionCountVector.push_back(questionCount);
        questionCount = 0;
    }    
    int totalQuestionCount = accumulate(questionCountVector.begin(), questionCountVector.end(), 0);
    cout << "Total questions: " << totalQuestionCount;
    return 0;
}