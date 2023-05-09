#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    char arr[]={'1','0','0'},arr1[]={'0','1','0'},rem[10];
    for (int i = 0; i < 3; i++)
    {
        rem[i]=(arr[i]^arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d",rem[i]);
    }
    
    
    return 0;
}