/**
 * @file 12_12.cpp
 * @author Sricharan
 * @brief Given an integer array and an integer k, do the following operations
 * The operation is, choose the maximum element of the array and replace it with its square root.
 * Do the operation k times, and then return the sum of elements remaining 
 * @version 2
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    long long sum = 0;
    int first = 0;
    priority_queue<int> pq;
    for(int i = 0; i < gifts.size(); i++){
        pq.push(gifts[i]);
        sum += gifts[i];
    }
    for(int i = 0; i < k; i++){
        int new_var = sqrt(pq.top());
        sum -= pq.top() - new_var;
        pq.pop();
        pq.push(new_var);
    }

    return sum;
}

int main(){
    vector<int> v = {25,64,9,4,100};
    int k = 4;
    cout << pickGifts(v, k);
}
