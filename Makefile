randomimage: randomimage.c bmp.c bmp.h
	gcc randomimage.c bmp.c -o randomimage

clean:
	rm randomimage