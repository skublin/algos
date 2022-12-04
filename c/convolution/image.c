/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 27-11-2022
 */ 

#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

struct image 
{
    int width, height, channels;
    unsigned char *img;
};

typedef struct image Image;

Image loadImage(char *name)
{
    Image i;
    int width, height, channels;
    unsigned char *img = stbi_load(name, &width, &height, &channels, 0);    // last argument 0 or at least 3 (?)

    if (img == NULL)
    {
        printf("Error in loading the image!\n");
        exit(1);
    }

    i.width = width;
    i.height = height;
    i.channels = channels;
    i.img = img;

    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels.\n", width, height, channels);

    stbi_image_free(img);

    return i;
};

