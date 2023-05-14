#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

char data[100];
int r,len,i,j;
int code[100];

void parity(){
    int count=0,k=0,m=0,e=0;
    len=len+r;
    while(k<r){
        int need=pow(2,k);
        count=0;
        for ( i = pow(2,k); i <= len; i=i+m){
            printf("%d ",i);
            for ( j = 0; j < need; j++){
                if(code[i+j] == 1) count++;
            }
            m=need+j;
        }
        printf("%d\n",count);
        if(count%2!=0) code[need]=1;
        k++;
    }
    
}

int main(){
    printf("Enter the dataword: ");
    scanf("%s",data);
    len=strlen(data);

    r=1;
    while (pow(2,r)<len+r+1) r++;
    printf("%d\n",r);
    int k=0,l=len;
    for(i=1;i<=len+r;i++){
        if(i!=pow(2,k))
            code[i]=data[--l]-'0';
        else{
            code[i]=0;
            k++;
        }
    }
    for ( i = len+r; i >= 1; i--)
    {
        printf("%d ",code[i]);
    }
    printf("\n");
    
    parity();

    for ( i = len; i >= 1; i--)
    {
        printf("%d ",code[i]);
    }

    return 0;
}