
#include <stdio.h>
#include <stdlib.h>
#include "stringProg.h"
// #include <string.h>

#define TXT 1024
#define WORD 30
#define NotValid 1
#define Valid 0
#define AlafBat 26


int Gematria(char * w, char* t , int txtSize){
    
    printf("Gematria Sequences: ");
    int wordValue = GetWordValue(w);
    int i = 0;
    int j = 0;
    int isFirst = 0;
    while (i <txtSize){
        if (IsValid(t[i]) == Valid && t[i] != ' '){
            int currentWordSum = 0;
            j = i;
            while (j <txtSize && currentWordSum < wordValue){
                char c = t[j];
                currentWordSum = currentWordSum + GetGematriaValue(c);
                j = j+1;
            }
            if (currentWordSum == wordValue){
                currentWordSum = 0;
                j = i;
                if (isFirst == 1){
                   printf("~"); 
                }
                isFirst = 1;
                while (j < txtSize && currentWordSum < wordValue){
                    char c = t[j];
                    printf("%c",c);
                    currentWordSum = currentWordSum + GetGematriaValue(c);
                    j = j+1;
                }
                
            }
        }
        i = i+1;
    }
    printf("\n");
    return 0;
}

int GetWordValue(char* c){
    int i = 0;
    int sum = 0;
    while (c[i] != '\0'){
        sum = sum + GetGematriaValue(c[i]);
        i=i+1;
    }
    return sum;
}

int GetGematriaValue(char c){
    if (c >= 'A' && c<= 'Z'){
        return (c - 'A' + 1);
    }
    if (c >= 'a' && c<= 'z'){
        return (c - 'a' + 1);
    }
    return 0;
}

int IsValid(char c){
    if ((c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || c ==' '){
        return 0;
    }
    return 1;
}


int Atbash(char* w, char* t ,int wordSize, int txtSize){
    printf("Atbash Sequences: ");

    int isFirst = 0;
    // Finding the two valid atbash words 
    int i = 0;
    int j = wordSize -2;
    char word1[wordSize];
    char word2[wordSize];
    while (i < wordSize -1 && j >= 0){
        word1[i] = (char)AtbashValue(w[i]);
        word2[i] = (char)AtbashValue(w[j]);
        i = i+1;
        j = j-1;
    }
    word1[wordSize-1] = '\0';
    word2[wordSize-1] = '\0';
    // Printing the valid sequences in the text we got
    i = 0;
    while (i < txtSize){
        j = i;
        // Check if the current text letter matches to one of the words first letter 
        if ((t[i] == word1[0] || t[i] == word2[0]) && t[i] != ' '){
            int p = 0;
            int flag1 = 1;
            int flag2 = 1;
            while (j < txtSize && p < wordSize -1 && (flag1 == 1 || flag2 == 1)){
                if (IsValid(t[j]) == Valid && t[j] != ' '){
                    if (word1[p] != t[j]){
                        flag1 = 0;
                    }
                    if (word2[p] != t[j]){
                        flag2 = 0;
                    }
                    if (flag1 == 0 && flag2 ==0){
                        p = p -1;
                    }
                    
                    p = p+1;
                    j = j+1;
                }
                else if (t[j] == ' '){
                    j = j+1;
                }
                else{
                    break;
                }
            }
            // If p != wordSize it means we didnt go over all the necessary letters
            if (p == wordSize -1){
                // Now If one of the flags equals to 0 it means that one of the words sequences appeared!
                j = i;
                p = 0;
                if (flag1 == 1){
                    if (isFirst == 1){
                        printf("~");        
                    }
                    isFirst = 1;
                    while (p < wordSize -1){
                        printf("%c",t[j]);
                        if (t[j] != ' '){
                            p = p+1;
                        }
                        j = j+1;
                    }
                }
                if (flag2 == 1){
                    if (isFirst == 1){
                        printf("~");
                    }
                    isFirst = 1;
                    while (p < wordSize -1){
                        printf("%c",t[j]);
                        if (t[j] != ' '){
                            p = p+1;
                        }
                        j = j+1;
                    }
                }
                
            }
            
        }
        i = i+1;
    }
    
    printf("\n");
    return 0;
}

int AtbashValue(char c){
    int gematria = GetGematriaValue(c);
    
    if (c >= 'A' && c<= 'Z'){
        return ('Z' - gematria +1);
    }
    if (c >= 'a' && c<= 'z'){
        return ('z' - gematria +1);
    }
    return c;
}

int Anagram(char * w , char * t, int wordSize,int txtSize){
    printf("Anagram Sequences: ");
    int isFirst = 0;
    int i = 0;
    int j = 0;
    int wordHash[AlafBat] = {0};
    int charGematria = 0;
    while (i < wordSize-1){
        charGematria = GetGematriaValue(w[i]) -1;
        wordHash[charGematria] = wordHash[charGematria] + 1;
        i = i+1;
    }


    i = 0;
    while (i < txtSize){
        if (IsValid(t[i]) == Valid && t[i] != ' '){

            int tempHash[AlafBat] = {0};
            
            j = i;
            int p = 0;
            // Changes if we got an invalid value 
            int flag = Valid;
            // Changes if the current tempHash sel is bigger than the wordHash cel
            int flag2 = Valid;

            while (j < txtSize && p < wordSize -1 && flag == Valid && flag2 == Valid){
                if (IsValid(t[j]) == Valid){
                    if (t[j] != ' '){
                        charGematria = GetGematriaValue(t[j]) -1;
                        tempHash[charGematria] = tempHash[charGematria] + 1;
                        if (tempHash[charGematria] > wordHash[charGematria]){
                            flag2 = NotValid;
                            p = p-1;
                        }
                        p = p+1;
                        j = j+1;
                    }
                    else{
                        j = j+1;
                    }
                }
                else{
                    flag = NotValid;
                }
            }
            // If the bellow answer is true, it means we got to all the wordHash letters
            if (p == wordSize -1 && flag == Valid && flag2 == Valid){
                j = i;
                p = 0;
                if (isFirst == 1){
                    printf("~");
                }
                isFirst = 1;
                while (p < wordSize - 1){
                    if (t[j] != ' '){
                        p = p+1;
                    }
                    printf("%c",t[j]);
                    j = j+1;
                }
            }
            // If the bellow answer is true, it means we stumbled upon an invalid char.
            // Which means that all the subsequences that follow him are invalid as well..
            else if(flag == NotValid){
                i = j;
            }  
        }
        
        i = i+1;
    }
    
    // printf("\n");
    return 0;
}





