#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char data[100];
int r,len,i,j;
int code[100];

void haming_sender(){
    int count=0,k=0,m=0,e=0;
    len=len+r;
    while(k<r){
        int need=pow(2,k);
        count=0;
        for ( i = pow(2,k); i <= len; i=i+m){
            for ( j = 0; j < need; j++){
                if(code[i+j] == 1) count++;
            }
            m=need+j;
        }
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
    printf("No of redundent bits: %d\n",r);
    
    int k=0,l=len;
    for(i=1;i<=len+r;i++){
        if(i!=pow(2,k))
            code[i]=data[--l]-'0';
        else{
            code[i]=0;
            k++;
        }
    }
    haming_sender();

    printf("Codeword: ");
    for ( i = len; i >= 1; i--)
    {
        printf("%d",code[i]);
    }

    return 0;
}