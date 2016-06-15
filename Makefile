make:
	gcc -w`pkg-config --cflags libconfig` -lconfig main.c -o trab \
	`pkg-config --libs libconfig`


