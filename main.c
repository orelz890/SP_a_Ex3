#include <stdio.h>
#include <string.h>
#include "stringProg.h"
#define TXT 1024
#define WORD 30

int main(){
    
    char str[TXT+1];
    char word[WORD+1];
    // int i = 0;
    // int WordSize = 0;
    scanf("%s",word);
    scanf("%[^~]",str);
    //scanf("%s",str);
    // Getting the word content:
    // char c;

    // do
    // {
    //     scanf("%c",&c);
    //     printf("%c",c);
    //     if((c >= 'a' && c <= 'z') || (c >='A' && c<='Z') ){
    //         word[i] = c;
    //         i = i+1;
    //     }
    // } while ((c != '\t' && c != '\n' && c != ' ') || i < WORD);            // Check what happens with \n \t ???

    // word[i] = '\0';
    // // Added +2 because we began with i=0 and for '\0'.
    // WordSize = i + 2;
    
    // // Getting the text content:
    // i = 0;
    // do
    // {
    //     scanf("%c",&c);
    //     printf("%c",c);
    //     if(c != '~'){
    //         str[i] = c;
    //         i = i+1;
    //     }
    // } while (c != '~' || i <= TXT);
    // str[i] = '\0';
    int wordSize = strlen(word);
    int txtSize = strlen(str);
    word[wordSize] = '\0';
    str[txtSize] = '\0';
    wordSize = wordSize+1;

    Gematria(word ,str,txtSize);
    Atbash(word , str , wordSize,txtSize);
    Anagram(word, str, wordSize,txtSize);
    
    return 0;
}