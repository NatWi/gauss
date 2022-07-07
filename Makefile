maincompile: staticlib
	gcc main_gauss_in.c -lgauss_in_static

staticlib:
	gcc gauss_in_static.c -c
	ar -crs libgauss_in_static.a gauss_in_static.o
	sudo cp gauss_in_static.h /usr/include
	sudo cp libgauss_in_static.a /usr/lib
