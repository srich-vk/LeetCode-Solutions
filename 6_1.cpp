/**
 * @file 6_1.cpp
 * @author Sricharan
 * @brief Given a string of 0's and 1's, representing the no. of objects in boxes, for each box find the minimum number 
 * of shifts required to put all the objects in that box. A shift can take place only between adjacent boxes. 
 * @version 1
 * @date 2025-01-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    vector<int> minOperations(string boxes){
        int len = boxes.length();
        int sum = 0;
        vector<int> box, shift;
        for(int i = 0; i < len; i++){
            box.push_back(int(boxes[i])-48);
            sum += int(boxes[i]) - 48;
        }

        for(int i = 0; i < len; i++){
            int leng = 0;
            int total = box[i];
            for(int j = 0; j < len; j++){
                if (i != j && box[j] == 1 && total != sum){
                    total++;
                    leng += abs(i - j);
                }

                if (total == sum){
                    break;
                } 
            }

            shift.push_back(leng);
        }

        return shift;
    }

};

void vectorPrint(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    Solution sol;
    string Input;
    cin >> Input;
    vectorPrint(sol.minOperations(Input));

    return 0;
}
