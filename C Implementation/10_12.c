#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isSpecial(char* s, int len){
    char c = s[0];
    for (int i = 1; i < len; i++){
        if (c != s[i]){
            return false;
        }
    }
    return true;
}

void createSub(const char* s, int start, int len, char* sub){
    for (int i = 0; i < len; i++){
        sub[i] = s[start + i];
    }
    sub[len] = '\0';
}


int maximumLength(char* s) {
    int slen = strlen(s);
    int flen = -1;
    for (int i = 1; i < slen; i++){
        int fnd = 0;
        for (int j = 0; j < slen - i + 1; j++){
            int count = 0;
            char sub[100];
            createSub(s, j, i, sub);
            if (isSpecial(sub, i) == true){
                for (int k = j; k < slen - i + 1; k++){
                    char tsub[100];
                    createSub(s, k, i, tsub);
                    if (strcmp(sub, tsub) == 0){
                        count++;
                    }
                    if (count == 3){
                        flen = i;
                        fnd = 1;
                        break;
                    }
                }
            }
            if (fnd == 1){
                break;
            }
        }
    }

    return flen;
}

int main(){
    char sent[] = "aaaa";
    printf("%d\n",maximumLength(sent));
}
