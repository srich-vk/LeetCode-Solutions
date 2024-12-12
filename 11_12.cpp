/**
 * @file 11_12.cpp
 * @author Sricharan
 * @brief To find the maximum beauty of an array after applying certain operations to it
 * The operation is:
 *      Given an integer k, replace the element at nums[i] with any number btw nums[i]+k and nums[i]-k
 * The beauty of an array is defined as the maximum number m such that there are m identical elements in the array
 * @version 1
 * @date 2024-12-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vectorPrint(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int maximumBeauty(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int res = 0, left = 0;
    for (int right = 0; right < nums.size(); right++){
        while (nums[right] - nums[left] > 2*k){
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

int main(){
    vector<int> v = {4,6,2,1};
    int k = 2;
    cout << maximumBeauty(v, k);
}