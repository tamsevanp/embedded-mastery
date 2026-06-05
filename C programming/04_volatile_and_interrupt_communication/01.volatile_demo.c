#include<stdio.h>

int main()
{
    volatile int a=20;
    int *ptr=(int*)&a;
    printf("The int is a=%d\n",*ptr);
    *ptr=25;
    printf("after the changes a=%d",*ptr);
    return 0;
}