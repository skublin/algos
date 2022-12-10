/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 10-12-2022
 */

#include <stdio.h>

int fibo(int number);

int main()
{
    int number;

    printf("Input number: ");
    
    scanf("%d", &number);

    printf("%d \n", fibo(number));

    return 0;
}

int fibo(int number)
{
    if (number == 1 || number == 2)
        return 1;
    else
        return fibo(number - 1) + fibo(number - 2);
}

