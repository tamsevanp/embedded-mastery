#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int division(int a, int b)
{
    return a/b;
}

void swap(void *a, void *b, size_t size)
{
    char temp[size];

    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
}


//Function pointer dispatch table: array of 4 fn ptrs called by index
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
    for(int i=0; i<5; i++)
    {
        arr[i]=&name[i];
    }

    printf("\nThe name is: ");
    for(int i=0; i<5; i++)
    {
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

    //function pointer
    int a=10,b=30;
    int (*func_ptr)(int, int);
    func_ptr=add;
    printf("\nadd: %d",(*func_ptr)(a,b));

    //function dispatch table
    int (*fptr[4])(int,int)={add,sub,mul,division}; //array of pointers to function

    printf("\nADD= %d",(*fptr[0])(a,b));//40
    printf("\nSUB: %d",(*fptr[1])(a,b)); //-20
    printf("\nMUL: %d",(*fptr[2])(a,b)); //300
    printf("\nDIV: %d",(*fptr[3])(a,b)); //0

    //generic swap with void *

    int x=50 , y=100;
    printf("\nbefore swap: x=%d y=%d",x,y);
    swap(&x,&y,sizeof(int));
    printf("\nafter swap: x=%d y=%d",x,y);

    char ch1='A', ch2='B';
    printf("\nbefore swap: ch1=%c ch2=%c",ch1,ch2);
    swap(&ch1,&ch2,sizeof(char));
    printf("\nafter swap: ch1=%c ch2=%c",ch1, ch2);

    float f1=24.123, f2=45.045;
    printf("\nbefor swap: f1=%f f2=%f",f1,f2);
    swap(&f1,&f2,sizeof(float));
    printf("\nafter swap: f1=%f f2=%f",f1,f2);

    return 0;
}