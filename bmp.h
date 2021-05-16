#ifndef BMP_H
#define BMP_H

#pragma pack(push, 1) // To avoid struct padding

// Represents the header of a bitmap file
typedef struct bmp_header_s { // [14] Bytes
    unsigned short signature; //  [2] 'BM'
    unsigned int file_size;   //  [4] File size in bytes
    unsigned int reserved;    //  [4] Unused
    unsigned int data_offset; //  [4] Data offset from the begining of the file
} bmp_header_t;

// Represents the info header of a bitmap file
typedef struct bmp_info_header_s { // [40] Bytes
    unsigned int size;             //  [4] Size of the info header
    int width;                     //  [4] Width of image in pixels
    int height;                    //  [4] Height of image in pixels
    short planes;                  //  [2] Number of planes
    short bits_per_pixel;          //  [2] Number of bits per pixel
    unsigned int compression;      //  [4] Type of compression
    unsigned int image_size;       //  [4] Compressed size of image
    int x_pixels_per_m;            //  [4] Horizontal pixels per meter
    int y_pixels_per_m;            //  [4] Vertical pixels per meter
    unsigned int colors_used;      //  [4] Number of colors used
    unsigned int important_colors; //  [4] Number of important colors (0 = all)
} bmp_info_header_t;

// Represents a pixel
typedef struct pixel_s { // [3] Bytes
    unsigned char r;     // [1] Red value
    unsigned char g;     // [1] Green value
    unsigned char b;     // [1] Blue value
} pixel_t;

// Represents the raw pixel data field in a bitmap file
typedef struct bmp_raw_data_s { // [1] Byte
    pixel_t *pixels;            // [1] Image data
} bmp_raw_data_t;

// Represents a bitmap file
typedef struct bmp_file_s {        // [55] Bytes
    bmp_header_t header;           // [14] The bitmap file header
    bmp_info_header_t info_header; // [40] The bitmap file info header
    bmp_raw_data_t raw_data;       //  [1] The raw data
} bmp_file_t;
#pragma pack(pop)

// Creates a bitmap file with random pixels
void create_bmp_file(int width, int height);

// Initializes the bitmap header
void init_header(bmp_header_t *header, int width, int height);

// Initializes the bitmap info header
void init_info_header(bmp_info_header_t *info_header, int width, int height);

// Generates random pixels
void generate_random_pixels(bmp_raw_data_t *raw_data, int width, int height);

#endif