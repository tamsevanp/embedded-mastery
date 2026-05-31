#include<stdio.h>
#include<stdlib.h>

static int num=25; //initialize data (global) .data section
int value;  //unitialized data (global) .bss section

int main()
{
    int a=10; //local variable destroyed when function destroy
    static int b; //.bss

    printf("Local variable of main a= %d\n",a); //10
    printf("static global variable initialized num= %d\n", num); //25
    printf("static local variable of main uninitialized b=%d\n",b); //0
    printf("global variable unintialized value=%d\n",value); //0

    int *c=malloc(5*sizeof(int)); //allocating memory in the HEAP section
    for(int i=0; i<=4; i++)
    {
        c[i]=i;
    }

    printf("Values in the heap: ");
    for(int i=0; i<=4; i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
    
    free(c);
    
    return 0;
}

/*

Higher Addresses
0xFFFF FFFF
+----------------------+
| Command-line args    |
| Environment vars     |
+----------------------+
| Stack                |
| a                    |
| c (pointer variable) |
+----------------------+
|                      |
|      Free Space      |
|                      |
+----------------------+
| Heap                 |
| malloc(5*sizeof(int))|
+----------------------+
| .bss                 |
| value                |
| b                    |
+----------------------+
| .data                |
| num = 25             |
+----------------------+
| .rodata              |
| format strings       |
+----------------------+
| .text                |
| main(), code         |
+----------------------+
Lower Addresses
0X0000 0000

*/