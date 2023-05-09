#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int input[20],temp[20],sum[20],inp_len,tmp_len,carry,i,j,sl;
char ip[20];

int pow_of_two(int n){
    if (n == 0)
        return 0;
    while (n != 1) {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

void check(){
    int len=inp_len%sl;
    if(len!=0){
        for(j=0;j<sl-len;j++)
            temp[j]=0;
        for(i=0;i<inp_len;i++)
            temp[j++]=input[i];
    }else{
        for(i=0;i<inp_len;i++)
            temp[i]=input[i];
    }
}

void reverse(){
    for(i=0;i<sl;i++){
        if(sum[i]==0) sum[i]=1;
        else sum[i]=0;
    }
}

void code_generator(){
    int k=0;
    for(i=tmp_len;i<tmp_len+sl;i++)
        temp[i]=sum[k++];
}

void checksum(){
    for ( i = 0; i < sl; i++)
        sum[i]=temp[i];

    int p=sl,k,need;
    while(p<tmp_len){
        k=sl-1,carry=0;
        for ( i = sl+p-1; i >= p ; i--){
            need=sum[k]+temp[i]+carry;
            sum[k]=need%2;
            carry=need/2;
            k--;
        }
        if(carry==1){
            for(j=sl-1;j>=0;j--){
                need=sum[j]+carry;
                sum[j]=need%2;
                carry=need/2;
            }
        }
        p+=sl;
    }
    reverse();
}

void receiver(){
    printf("Enter the dataword: ");
    scanf("%s",ip);
    for ( i = 0; i < tmp_len; i++)
        temp[i]=ip[i]-'0';
    checksum();
    for(i=0;(i<sl) && (sum[i]==0);i++);
    if(i==sl) printf("\nNo error!!");
    else printf("\nError!!");
}

int main(){
    printf("Enter the dataword: ");
    scanf("%s",ip);
    inp_len=strlen(ip);
    for ( i = 0; i < inp_len; i++)
        input[i]=ip[i]-'0';
    do
    {
        printf("Enter the length of the divior: ");
        scanf("%d",&sl);
    } while (pow_of_two(sl)!=1);

    check();
    tmp_len=inp_len+(sl-inp_len%sl);
    printf("After adding 0's: ");
    for ( i = 0; i < tmp_len; i++)
        printf("%d",temp[i]);

    checksum();
    printf("\nSum: ");
    for(i=0;i<sl;i++)
        printf("%d",sum[i]);
        
    code_generator();
    printf("\nCodeword: ");
    for ( i = 0; i < tmp_len+sl; i++)
        printf("%d",temp[i]);
    printf("\n");
    tmp_len=tmp_len+sl;
    
    receiver();

    return 0;
}