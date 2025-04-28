#include<stdio.h>
#include<string.h>
#include<math.h>
#define d 256

void rabinKarp(char pat[] , char txt[]){
    int i,j;
    int m = strlen(pat);
    int n = strlen(txt);
    unsigned long p=0;
    unsigned long t=0;
    
    for(int i = 0 ;i<m; i++){
        p = d*p + pat[i];
        t = d*t + txt[i];
    }

    for(int i=0 ; i<n-m ; i++){
        if(p==t){
            for(j=0 ; j<m;j++){
                if(pat[j]!= txt[i+j]){
                    printf("Break");
                    break;
                }
            }

            if(j == m ){
                printf("Pattern found at index %d\n", i);
            }
        }
        
        if(i<n-m){
            t = d*(t-txt[i] * pow(d,m-1))+txt[i+m];
        }
    }

}

int main(){
    char txt[] = "ABFDCCDDAEFG";
    char pat[] = "CDD";

    rabinKarp(pat, txt);
    return 0;
}