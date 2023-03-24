#include <stdio.h>
#include <math.h>

int sender(int b[10], int k)
{
    int checksum,sum = 0;
    for(int i = 0;i<k;i++)
    {
        sum+=b[i];
    }
    printf("Sum is %d\n", sum);
    checksum = ~sum;
    printf("Sender checksum is %d\n", checksum);
    return checksum;
}

int receiver(int c[10], int k, int scheck)
{
    int checksum,sum = 0;
    for(int  i = 0;i<k;i++)
    {
        sum+=c[i];
    }
    sum = sum + scheck;
    printf("Sum is %d\n", sum);
    checksum = ~sum;
    printf("Receiver checksum is %d\n", checksum);
    return checksum;
}

int main()
{
    int a[10], i,m, scheck,rcheck;
    printf("Enter the size of the string\n");
    scanf("%d", &m);
    printf("Enter the elements of the array\n");
    for(i = 0;i<m;i++)
    {
        scanf("%d", &a[i]);
    }
    scheck = sender(a,m);
    rcheck = receiver(a,m,scheck);
    if(rcheck == 0)
    printf("\n\n NO ERROR IN TRANSMISSION\n\n");
    else
    printf("\n\n ERROR DETECTED\n\n");

}