/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 27-11-2022
 */ 

#include <stdio.h>
#include <string.h>

const int IDENTITY[9] = {0, 0, 0, 0, 1, 0, 0, 0, 0};    // 3x3 matrix with Identity mask converted to 1D array (reversed order)
const int SHARPEN[9] = {0, -1, 0, -1, 5, -1, 0, -1, 0};

void showMatrix(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
    printf("\n");
    }
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};    // {1, 2, 3, 4} or {{1, 2}, {3, 4}}
    
    showMatrix(3, matrix);

    return 0;
}showme





















kocham



















































cię        bardzo           baaaaardzoooo
































                                                                                     ooooooooooooooo



