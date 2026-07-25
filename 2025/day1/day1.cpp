#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int solve_part_1(const vector<string>& puzzle_input){
    //     int dial = 50; // initially at 50.
    //     int MOD = 100; // 0-99 includes 100 turns.

    //     int count = 0; // count of times the dial stops at 0.
    //     for(const string& line : puzzle_input){
    //         char direction = line[0];
    //         int turns = stoi(line.substr(1, line.length()-1));

    //         if(direction == 'L'){
    //             dial = (((dial - turns) % MOD) + MOD) % MOD; // note: since new dial could be negative.
    //         }
    //         else {
    //             dial = (dial + turns) % MOD;
    //         }

    //         if(dial == 0) count++;
    //     }

    //     return count;
    // }

    int solve_part_2(const vector<string>& puzzle_input){
        int dial = 50; // dial initially at 50.
        int MOD = 100; // 0-99 includes 100 turns.

        int count = 0; // count of times the dial passes or stops at 0.
        for(const string& line : puzzle_input){
            char direction = line[0];
            int turns = stoi(line.substr(1, line.length()-1));

            if(direction == 'R'){
                if(dial != 0){
                    if(turns >= MOD-dial){ // since we need atleast MOD-dial turns to reach 0.
                        turns -= (MOD-dial);
                        dial = 0;
                        count += 1;
                        if(turns == 0) continue; // continue if there're no more turns left.

                        count += turns / MOD;
                        dial = (dial + turns) % MOD;
                    }
                    else {
                        dial = (dial + turns) % MOD;
                    }
                }
                else { // dial == 0.
                    count += turns / MOD;
                    dial = (dial + turns) % MOD;
                }
            }
            else { // direction == 'L'.
                if(dial != 0){
                    if(turns >= dial){ // since we need atleast dial turns to reach 0.
                        turns -= dial;
                        dial = 0;
                        count += 1;
                        if(turns == 0) continue; // continue if there're no more turns left.

                        count += turns / MOD;
                        dial = (((dial - turns) % MOD) + MOD) % MOD;
                    }
                    else {
                        dial = (((dial - turns) % MOD) + MOD) % MOD;
                    }
                }
                else { // dial == 0.
                    count += turns / MOD;
                    dial = (((dial - turns) % MOD) + MOD) % MOD;
                }
            }
        }

        return count;
    }
};

int main(){
    ifstream file("input.txt");

    if(!file.is_open()){
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<string> puzzle_input;
    string line;
    while(getline(file, line)){
        puzzle_input.push_back(line);
    }
    file.close();

    Solution mySolution;
    // cout << mySolution.solve_part_1(puzzle_input);
    cout << mySolution.solve_part_2(puzzle_input);

    return 0;
}
