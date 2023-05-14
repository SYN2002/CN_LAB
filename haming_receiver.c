#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char data[100];
int len,code[100],bin[100],i,j,r;

int bin_to_dec(){
    int dec=0,k=r-1;
    for(i=0;i<r;i++){
        dec=dec+(bin[i]*pow(2,k));
        k--;
    }
    return dec;
}

void haming_receiver(){
    int count=0,k=0,m=0;
    while(k<r){
        int need=pow(2,k);
        count=0;
        for ( i = pow(2,k); i <= len; i=i+m){
            for ( j = 0; (j < need) && (j+need<=len); j++){
                if(code[i+j] == 1) count++;
            }
            m=need+j;
        }
        if(count%2==0)
            bin[k]=0;
        else
            bin[k]=1;
        k++;
    }
    int btd=bin_to_dec();
    if(btd==0)
        printf("No error!!");
    else{
        printf("Error at %dth position!!\n",bin_to_dec());
        code[btd]=(code[btd]==0)?1:0;
        printf("Corrrect codeword is: ");
        for ( i = 1; i <= len; i++)
            printf("%d",code[i]);
        
    }
}

int main(){
    printf("Enter the codeword: ");
    scanf("%s",data);
    len=strlen(data);
    for ( i = 1; i <= len; i++)
        code[i]=data[i-1]-'0';
    r=1;
    while(pow(2,r)<len) r++;
    printf("Redundent bits: %d\n",r);
    haming_receiver();

    return 0;
}