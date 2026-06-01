#include<stdio.h>

int main()
{
    //single pointer
    int num = 25;
    int *ptr;
    ptr = &num;
    printf("num=%d ptr=%p *ptr=%d\n",num,ptr,*ptr);

    // Pointer-to-pointer
    int **pp = &ptr;
    printf("pp=%p **pp=%d",pp,**pp);

    //array-of-pointers
    char *arr[5];
    char name[5]="Tamil";
    for(int i=0; i<5; i++){
        arr[i]=&name[i];
    }

    printf("\nThe name is: ");
    for(int i=0; i<5; i++){
       printf("%c",*arr[i]);
    }
    printf("\n");

    //pointer-to-array
    int (*p)[5];
    int value[5]={11,12,13,14,15};
    p=&value;
    
    printf("The values in the array: ");
    for(int i=0; i<5; i++)
    {
        printf("%d ",(*p)[i]);
    }

    return 0;
}