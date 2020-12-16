#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int findSum(int targetSum, vector<int> &list){
    for (int x = 0; x < list.size(); x++){
        for (int y = 0; y < list.size(); y++)
            for (int z = 0; z < list.size(); z++)
            if (list[x] + list[y] + list[z] == targetSum)
                return list[x] * list[y] * list[z];
    }
    return 0;
}

int main () {
    ifstream input;
    input.open("input.txt");
    if (!input) {
        cout << "No input found";
        exit(1);
    }
    vector<int> list;
    int value;
    while (!input.eof()){
		input >> value;
		list.push_back(value);
	}
    input.close();
    int result = findSum(2020, list);
    cout << "Multiplied result: " << result;
    return 0;
}