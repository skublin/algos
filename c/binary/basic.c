/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 07-12-2022
 */ 

#include <stdio.h>

void integerEvenOrOdd(int number);

void oppositeSignsCheck(int a, int b);

int main()
{
    int n = 11;
    integerEvenOrOdd(n);

    int x = -12, y = 13;
    oppositeSignsCheck(x, y);

    return 0;
}

void integerEvenOrOdd(int number)
{
    if (number & 1)
        printf("%d is odd!\n", number);
    else
        printf("%d is even!\n", number);
}

void oppositeSignsCheck(int a, int b)
{
    if ((a ^ b) < 0)
        printf("%d and %d have opposite signs!\n", a, b);
    else
        printf("%d and %d have the same signs!\n", a, b);
}
