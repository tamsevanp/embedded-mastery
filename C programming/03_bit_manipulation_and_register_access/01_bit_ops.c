#include<stdio.h>
#include<stdint.h>

#define SET_BIT(mask,pos)   ((mask) |= (1U << (pos)))
#define CLEAR_BIT(mask,pos)  ((mask) &= (~(1U << (pos))))
#define TOGGLE_BIT(mask,pos)  ((mask) ^= (1U << (pos)))
#define CHECK_BIT(mask,pos)  (((mask) >> (pos)) & 1U) //((mask) & (1U << (pos)))

int main()
{
    uint8_t num = 154; //10011010

    uint8_t value = SET_BIT(num,2);
    printf("Number given: %d \n",value);

    

    return 0;
}