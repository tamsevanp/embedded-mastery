#include<stdio.h>
#include<stdint.h>

#define SET_BIT(mask,pos)  ((mask) |= (1U<<(pos)))
#define CLEAR_BIT(maks,pos) ((maks) &= (~(1U<<(pos))))
#define TOGGLE_BIT(mask,pos)  ((mask) ^= (1U<<(pos)))
#define CHECK_BIT(mask,pos)     (((mask) >> (pos)) & 1U)

int main()
{
    uint32_t reg=0;

    printf("reg =0x%08x\n",reg);

    SET_BIT(reg,5);
    printf("After 5th bit set reg = 0X%08x\n",reg);

    printf("Check the 5th bit high or low reg = %u\n",CHECK_BIT(reg,5));

    TOGGLE_BIT(reg,5);
    printf("After toggle the 5th bit reg = 0x%08x\n",reg);

    TOGGLE_BIT(reg,5);
    printf("After toggle the 5th bit reg = 0x%08x\n",reg);

    CLEAR_BIT(reg,5);
    printf("After clear the 5th bit reg = 0x%08x",reg);

    return 0;
}
