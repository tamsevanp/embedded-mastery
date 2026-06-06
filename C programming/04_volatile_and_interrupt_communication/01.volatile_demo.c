#include <stdio.h>

volatile int flag = 0;

int main()
{
    printf("Waiting for flag to become 1...\n");

    while(flag == 1)
    {
        // wait
    }

    printf("Flag changed!\n");

    return 0;
}