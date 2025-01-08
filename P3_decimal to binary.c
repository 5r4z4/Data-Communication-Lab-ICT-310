#include<stdio.h>
void decimalTobinary(int decimal)
{
    int binary[32];
    int index = 0;


    if(decimal == 0)
    {
        printf("binary : 0\n",decimal);
        return 0;
    }
    while(decimal>0)
    {
        binary[index++] = decimal%2;
        decimal/=2;
    }
    printf("Binary: ");

    for(int i = index-1; i>=0; i--)
    {
        printf("%d",binary[i]);
    }
    printf("\n");
}

int main()
{
    int decimal;
    printf("enter the decimal: ");
    scanf("%d",&decimal);
    decimalTobinary(decimal);
    return 0;
}