/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 06-12-2022
 */ 

#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.png", "rb");

    if (fp == NULL)
    {
        printf("Error opening image file!\n");
        return 1;
    }

    unsigned char buffer[1024];
    size_t bytes_read = fread(buffer, 1, 1024, fp);

    if (bytes_read != 1024)
    {
        printf("Error reading image data!\n");
        return 1;
    }

    fclose(fp);

    return 0;
}
