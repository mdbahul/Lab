#include <stdio.h>
int main(){
    char a[1000], word[50], sword[50], lword[50];
    int ss=0, se=0, ls=0, le=0, ws=0; we=0;
    printf("Enter the string ");
    gets(a);
    while(a[i] != '\0'){
        if ( a[i] == ' ' ){
        if ( strlen(word) > strlen(lword))
            le = we, ls = ws;//strcpy(lword,word);
        else if (strlen(word)< strlen(sword))
            ss = ws; se = we;//strcpy(sword,word);
        else if (strlen(word) == strlen(sword) && strcmp(sword, word))
            //strcpy(sword,word);
        else if (strlen(word) == strlen(lword) && strcmp(word, lword))
            strcpy(lword,word);
            ws=i+1;
            we= i+1;
        }
        else 
            we++;
            //strncat(word, a[i], 1);
        }
    puts(sword);
    puts(lword);
    }
}