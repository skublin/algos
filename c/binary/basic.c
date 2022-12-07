/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 07-12-2022
 */ 

#include <stdio.h>

void integerEvenOrOdd(int number);

int main()
{
    int n = 11;

    integerEvenOrOdd(n);

    return 0;
}

void integerEvenOrOdd(int number)
{
    if (number & 1)
        printf("%d is odd!\n", number);
    else
        printf("%d is even!\n", number);
}
