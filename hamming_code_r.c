#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 100

bool is_all_zeroes(int s, int *a)
{
    for (int i = 0; i < s; ++i)
        if (a[i]) return false;
        
    return true;
}

int convert_to_decimal(int s, int *a)
{
    int result = 0;
    
    for (int i = 0, p = s - 1; i < s; ++i, --p)
        result += (pow(2, p) * a[i]);
    
    return result;
}

int main(){

    char codeword[SIZE];
    printf("Codeword: ");
    scanf("%s", codeword);
    int s = strlen(codeword);
    
    int r = 0;
    while (pow(2, r) < s + 1){
        ++r;
    }
        
    int parity[r];
    for (int i = 0; i < r; ++i)
        parity[i] = 0;
    
    for (int p = 1; p <= r; ++p) {
        int poi = pow(2, p - 1);
        int result = 0;
        for (int j = poi; j <= s; j += poi) {
            for (int i = 0; i < poi && s - j >= 0; ++i, ++j)
                result ^= (codeword[s - j] - '0');
        }
        parity[r - p] = result;
    }
    
    if (is_all_zeroes(r, parity)) printf("Accepted\n");
    
    else {
        int pos = convert_to_decimal(r, parity);
        printf("Error at position %d from right.\n", pos);
        codeword[s - pos] = codeword[s - pos] == '1' ? '0' : '1';
        printf("Corrected codeword: %s\n", codeword);
    }
    
    return 0;
}
