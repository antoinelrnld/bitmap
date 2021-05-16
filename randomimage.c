#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int width, height;

    if (argc < 3) {
        printf("Usage : randomimage width height\n");
        return EXIT_FAILURE;
    }

    width = strtol(argv[1], NULL, 10);

    if (errno == EINVAL || width < 1) {
        printf("Wrong value provided for the width argument\n");
        return EXIT_FAILURE;
    }

    height = strtol(argv[2], NULL, 10);

    if (errno == EINVAL || height < 1) {
        printf("Wrong value provided for the height argument\n");
        return EXIT_FAILURE;
    }

    create_bmp_file(width, height);
    printf("Bitmap file successfully created\n");

    return 0;
}