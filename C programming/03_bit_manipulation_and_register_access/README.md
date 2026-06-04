#  Bit Manipulation in C

## Overview

Bit manipulation is the process of operating directly on individual bits of a number using bitwise operators. It is widely used in Embedded Systems, Device Drivers, Communication Protocols, and Microcontroller Programming for efficient memory and hardware register access.

---

## Bitwise Operators

| Operator    | Symbol  | Description                    |
|-------------|---------|--------------------------------|
| AND         | `&`     | Sets bit if both bits are 1    |
| OR          |`\|`     | Sets bit if either bit is 1    |
| XOR         | `^`     | Sets bit if bits are different |
| NOT         | `~`     | Inverts all bits               |
| Left Shift  | `<<`    | Shifts bits left               |
| Right Shift | `>>`    | Shifts bits right              |

### Example

```c
uint8_t a = 5;   // 00000101
uint8_t b = 3;   // 00000011

a & b;  // 00000001
a | b;  // 00000111
a ^ b;  // 00000110
```

---

## Bit Manipulation Macros

### Set a Bit

```c
#define SET_BIT(mask, pos) ((mask) |= (1U << (pos)))
```

Sets the bit at position `pos`.

Example:

```c
SET_BIT(reg, 5);
```

Before:

```
00000000
```

After:

```
00100000
```

---

### Clear a Bit

```c
#define CLEAR_BIT(mask, pos) ((mask) &= ~(1U << (pos)))
```

Clears the bit at position `pos`.

Example:

```c
CLEAR_BIT(reg, 5);
```

Before:

```
00100000
```

After:

```
00000000
```

---

### Toggle a Bit

```c
#define TOGGLE_BIT(mask, pos) ((mask) ^= (1U << (pos)))
```

Flips the bit at position `pos`.

Example:

```c
TOGGLE_BIT(reg, 5);
```

Before:

```
00100000
```

After:

```
00000000
```

---

### Check a Bit

```c
#define CHECK_BIT(mask, pos) (((mask) >> (pos)) & 1U)
```

Returns:

- `1` → Bit is set
- `0` → Bit is cleared

Example:

```c
CHECK_BIT(reg, 5);
```

---

## Count Set Bits

Counts the number of bits that are set to `1`.

```c
uint32_t count_set_bits(uint32_t num)
{
    uint32_t count = 0;

    while(num)
    {
        count += num & 1U;
        num >>= 1;
    }

    return count;
}
```

Example:

```c
count_set_bits(13);
```

Binary:

```
1101
```

Output:

```
3
```

---

## Reverse Byte

Reverses all 8 bits in a byte.

```c
uint8_t reverse_byte(uint8_t byte)
{
    uint8_t reversed = 0;

    for(int i = 0; i < 8; i++)
    {
        reversed <<= 1;
        reversed |= (byte & 1U);
        byte >>= 1;
    }

    return reversed;
}
```

Example:

```
00001101
```

Becomes:

```
10110000
```

---

## Highest Set Bit

Returns the position of the most significant set bit.

```c
int highest_set_bit(uint32_t num)
{
    if(num == 0)
        return -1;

    int pos = 0;

    while(num >>= 1)
        pos++;

    return pos;
}
```

Example:

```
40 = 101000
```

Highest set bit position:

```
5
```

---

## GPIO Register Simulation

In Embedded Systems, peripherals are controlled through memory-mapped registers.

### Simulated Register

```c
uint32_t reg = 0;
```

### Set PA5

```c
SET_BIT(reg, 5);
```

Register:

```
00000000 00000000 00000000 00100000
```

---

### Clear PA5

```c
CLEAR_BIT(reg, 5);
```

Register:

```
00000000 00000000 00000000 00000000
```

---

### Toggle PA5

```c
TOGGLE_BIT(reg, 5);
```

Register:

```
00000000 00000000 00000000 00100000
```

---

### Check PA5

```c
CHECK_BIT(reg, 5);
```

Returns:

```
1
```

if PA5 is HIGH.

---

## Real Embedded Register Access

Example from STM32-like microcontrollers:

```c
#define GPIOA_ODR (*(volatile uint32_t *)0x48000014U)
```

Set PA5:

```c
SET_BIT(GPIOA_ODR, 5);
```

Clear PA5:

```c
CLEAR_BIT(GPIOA_ODR, 5);
```

Toggle PA5:

```c
TOGGLE_BIT(GPIOA_ODR, 5);
```

Read PA5:

```c
if(CHECK_BIT(GPIOA_ODR, 5))
{
    // Pin is HIGH
}
```

---

## Key Takeaways

- Bitwise operations are essential in Embedded C.
- Registers are manipulated using masks and bit positions.
- Macros provide efficient and readable register access.
- GPIO control in microcontrollers is fundamentally bit manipulation on memory-mapped registers.
- Understanding bit operations is crucial for firmware, drivers, and low-level programming.