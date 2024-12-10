/**
 * @file 1_12.cpp
 * @author Sricharan
 * @brief Returns true if there exists 2 elements in the given list of integers, where one is the double of another
 * @version 1
 * @date 2024-12-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i] ){
                return true;
            }
        }
    }
    return false;
}

