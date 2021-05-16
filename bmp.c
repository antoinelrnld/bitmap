#include "bmp.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Creates a bitmap file with random pixels
void create_bmp_file(int width, int height) {
    bmp_file_t image;
    FILE *output_file;

    // Creation of an output file
    output_file = fopen("result.bmp", "wb");

    // Initialization of different headers
    init_header(&image.header, width, height);
    init_info_header(&image.info_header, width, height);

    // Memory allocation for the pixels
    image.raw_data.pixels = malloc(3 * width * height * sizeof(pixel_t));

    generate_random_pixels(&image.raw_data, width, height);

    // Writing data on disk
    fwrite(&image.header, 1, sizeof(bmp_header_t), output_file);
    fwrite(&image.info_header, 1, sizeof(bmp_info_header_t), output_file);
    fwrite(image.raw_data.pixels, 1, 3 * width * height, output_file);

    // Closing the output file
    fclose(output_file);

    // Free the previously allocated memory
    free(image.raw_data.pixels);
}

// Initializes the bitmap header
void init_header(bmp_header_t *header, int width, int heigth) {
    header->signature = 0x4D42;                    // 'BM'
    header->file_size = 54 + (3 * width * heigth); // File size in bytes
    header->reserved = 0;
    header->data_offset = 0x36;                    // Data offset from the beggining of the file
}

// Initializes the bitmap info header
void init_info_header(bmp_info_header_t *info_header, int width, int height)
{
    info_header->size = 40;
    info_header->width = width;
    info_header->height = height;
    info_header->planes = 1;
    info_header->bits_per_pixel = 24;
    info_header->compression = 0;
    info_header->image_size = 0;
    info_header->x_pixels_per_m = 3780;
    info_header->y_pixels_per_m = 3780;
    info_header->colors_used = 0;
    info_header->important_colors = 0;
}

// Generates a random image
void generate_random_pixels(bmp_raw_data_t *raw_data, int width, int height) {
    int i, j, p;
    srand(time(NULL));
    p = 0;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // Random colors
            raw_data->pixels[p].r = rand() % 256;
            raw_data->pixels[p].g = rand() % 256;
            raw_data->pixels[p].b = rand() % 256;
            p++;
        }
    }
}