/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 27-11-2022
 */ 

#include <stdio.h>
#include <string.h>
#include "image.c"

struct matrix
{
    int rows, cols, length;
    unsigned char (*data)[3];
};

typedef struct matrix Matrix;

Matrix loadImageMatrixx(Image im, int channel)
{
    Matrix m;

    m.rows = im.height;
    m.cols = im.width;
    m.length = im.width * im.height;

    return m;
}

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

void loadImageMatrix(Image image, int channel);

int main()
{
    Image img;

    img = loadImage("test.png");

    printf("SHOW IMAGE:\n");

    for (int c=0; c < img.channels; c++)
    {
        loadImageMatrix(img, c);
        printf("CHANNEL DONE!\n");
    }   

    return 0;
}

void loadImageMatrix(Image image, int channel)
{
    int result[image.height][image.width][3];
    printf("CHANNEL %d:\n", channel); 
    for (int i=0; i < image.height; i++)
    {
        for (int j=0; j < image.width; j++)
        {
            unsigned bytePerPixel = channel;
            unsigned char *pixelOffset = image.img + (i + image.width * j) * bytePerPixel;
            unsigned char r = pixelOffset[0];
            unsigned char g = pixelOffset[1];
            unsigned char b = pixelOffset[2];
            unsigned char a = channel >= 4 ? pixelOffset[3] : 0xff;

            // printf("(%d, %d, %d)\n", r, g, b);
            result[i][j][0] = r;
            result[i][j][1] = g;
            result[i][j][2] = b;
            printf("(%d, %d, %d)  ", result[i][j][0], result[i][j][1], result[i][j][2]);
        }
        printf("\n");
    }

    //int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};    // {1, 2, 3, 4} or {{1, 2}, {3, 4}}
    
    //showMatrix(3, matrix);
}

