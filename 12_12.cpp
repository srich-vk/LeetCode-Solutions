/**
 * @file 12_12.cpp
 * @author Sricharan
 * @brief Given an integer array and an integer k, do the following operations
 * The operation is, choose the maximum element of the array and replace it with its square root.
 * Do the operation k times, and then return the sum of elements remaining 
 * @version 1
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    long long sum = 0;
    int first = 0;
    for(int i = 0; i < k; i++){
        int lar_ind = 0;
        for(int j = 0; j < gifts.size(); j++){
            if (gifts[j] > gifts[lar_ind]){
                lar_ind = j;
            }
            if (first == 0){
                sum += gifts[j];
            }
        }

        first = 1;
        long long new_var = sqrtl(gifts[lar_ind]);
        sum -= (gifts[lar_ind] - new_var);
        gifts[lar_ind] = new_var;     
    }

    return sum;
}

int main(){
    vector<int> v = {25,64,9,4,100};
    int k = 4;
    cout << pickGifts(v, k);
}