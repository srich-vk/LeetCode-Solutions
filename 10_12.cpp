/**
 * @file 10_12.cpp
 * @author Sricharan
 * @brief 
 * @version 0.1
 * @date 2024-12-10
 * 
 * Code to find the maximum length of special substring of a string, that appears thrice within the string
 * A string/substring is said to be special if all the characters of the string are the same
 */
#include <iostream>
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
    int len = s.length();
    int flen = 0;
    for(int i = 1; i < len; i++){
        int found = 0;
        for (int j = 0; j < len - i + 1; j++){
            int count = 0;
            string sub = s.substr(j, i);
            if (isSpecial(sub)){
                for (int k = j; k < len - i + 1; k++){
                    string trsub = s.substr(k, i);
                    if (trsub == sub){
                        count++;
                    }
                    if (count >= 3){
                        flen = sub.length();
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 1){
                break;
            }
        }
    }
    return flen == 0 ? -1 : flen;
}

int main(){
    string a;
    cin >> a;
    cout << maximumLength(a);
    return 0;
}