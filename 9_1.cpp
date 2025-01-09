/**
 * @file 9_1.cpp
 * @author Sricharan
 * @brief Given a list of words and a prefix, find the count of words that begin with that prefix
 * @version 1
 * @date 2025-01-09
 * 
 */

#include <iostream>
#include <vector>
#include <string_view>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int total = 0;
        string_view pre(pref);
        for (int i = 0; i < words.size(); i++){
            if (words[i].length() >= pref.length()){
                if (pre == string_view(words[i].data(), pref.length())){
                    total++;
                }
            }
        }   
        return total;
    }   
};

int main(){
    Solution sol;
    vector<string> wordlist = {"hello", "hi", "heat","owl","help"};

    cout << sol.prefixCount(wordlist, "he");
}
