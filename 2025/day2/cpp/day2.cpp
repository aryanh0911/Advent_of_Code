#include<bits/stdc++.h>
using namespace std;

#define ll long long;

class Solution{
public:
    int solve_part_1(const vector<string>& puzzle_input){

    }
};

int main(){
    ifstream file("exampleInput.txt");

    if(!file.is_open()){
        cerr << "Error opening file!" << endl;
        return -1;
    }

    vector<string> puzzle_input;
    string line;
    while(getline(file, line)){
        puzzle_input.push_back(line);
    }
    file.close();

    Solution mySolution;
    cout << mySolution.solve_part_1(puzzle_input);

    return 0;
}
