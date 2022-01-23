all:
	gcc cockpoints.c -o cockpoints -pipe -O2 -march=native
	./cockpoints
