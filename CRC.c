#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char input[20],divisor[20],divident[20],temp[20];
int ip_len,div_len;

void xor(){
    for (int i = 1; i < div_len; i++)
        temp[i]=((temp[i]==divisor[i])?'0':'1');
    
}

void CRC(){
    int j,i;
    for ( i = 0; i < div_len; i++)
        temp[i]=divident[i];
    do{
        if(temp[0]=='1')
            xor();
        for ( j = 0; j < div_len-1; j++)
            temp[j]=temp[j+1];
        temp[j]=divident[i++];
    }while(i<=ip_len+div_len-1);
}

void reciever_side(){
    printf("Enter the recieved data: ");
    scanf("%s",divident);
    CRC();
    int i;
    for ( i = 0; (i < div_len-1) && (temp[i]!='1'); i++);
    if(i<div_len-1)
        printf("Error Found!");
    else
        printf("No Error!");
}

int main(){

    printf("Enter the dataword: ");
    scanf("%s",input);
    printf("Enter the divisor: ");
    scanf("%s",divisor);
    ip_len=strlen(input);
    div_len=strlen(divisor);
    int r=div_len-1;
    strcpy(divident,input);
    for (int i = ip_len; i < ip_len+r; i++)
        divident[i]='0';
    printf("After adding 0's: %s\n",divident);

    CRC();//temp[] contains crc bits

    printf("CRC: %s\n",temp);
    for (int i = ip_len,k=0; i < (ip_len+div_len); i++)
        input[i]=temp[k++];
    
    printf("Codeword: %s\n",input);

    reciever_side();
    
    return 0;
}