#ifndef BMP_H
#define BMP_H

typedef struct bmp_header_s {
    char signature[2];              // 'BM'
    char file_size[4];              // File size in bytes.
    char reserved[4];               // Unused
    char data_offset[4];            // Data offset from the begining of the file
} bmp_header;

typedef struct bmp_info_header_s {
    char size[4];                   // Size of the info header
    char width[4];                  // Width of image in pixels
    char height[4];                 // Height of image in pixels
    char planes[2];                 // Number of planes
    char bits_per_pixel[2];         // Number of bits per pixel
    char compression[4];            // Type of compression
    char image_size[4];             // Compressed size of image
    char x_pixels_per_m[4];         // Horizontal pixels per meter
    char y_pixels_per_m[4];         // Vertical pixels per meter
    char colors_used[4];            // Number of colors used
    char important_colors[4];       // Number of important colors (0 = all)
} bmp_info_header;

typedef struct bmp_color_table_s {
    char red;                       // Red Intensity
    char green;                     // Green Intensity
    char blue;                      // Blue Intensity
    char reserved;                  // Unused
} bmp_color_table;

typedef struct bmp_pixel_data_s {
    char *data;                     // Image data
} bmp_pixel_data;

typedef struct bmp_s {
    bmp_header header;
    bmp_info_header  info_header;
    bmp_color_table *color_table;
    bmp_pixel_data pixel_data;
} bmp_file;

// Initializes the bitmap header
void init_header(bmp_header *header);

// Initializes the bitmap info header
void init_info_header(bmp_info_header *info_header);

// Initializes a color table
void init_color_table(bmp_color_table *color_table, char red, char green, char blue);

// Generates a random image
void generate_pixel_data(bmp_pixel_data *pixel_data);

#endif