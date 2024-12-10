/**
 * @file 10_12.cpp
 * @author Sricharan
 * @brief Code to find the maximum length of special substring of a string, that appears thrice within the string
 *        A string/substring is said to be special if all the characters of the string are the same
 * @version 2
 * @date 2024-12-10
 * 
 */
#include <iostream>
#include <unordered_map>
using namespace std;

bool isSpecial(string s){
    char c = s[0];
    for (int i = 0; i < s.length(); i++){
        if (c != s[i]){
            return false;
        }
    }

    return true;
}

int maximumLength(string s){
    unordered_map <string, int> substrcol;
    int len = s.length();
    int flen = -1;

    for(int i = 1; i < len; i++){
        for (int j = 0; j < len - i + 1; j++){
            string sub = s.substr(j, i);
            if (i == 1 || isSpecial(sub)){
                substrcol[sub]++;
                if (substrcol[sub] == 3){
                    flen = sub.length();
                    break;
                }
            }
        }
    }

    return flen;
}

int main(){
    string a;
    cin >> a;
    cout << maximumLength(a);
    return 0;
}
