all:
	gcc cockpoints.c -o cockpoints -pipe -O2 -march=native
	ls ~/.local/bin || mkdir ~/.local/bin
	cp cockpoints ~/.local/bin/cockpoints
	touch ~/.local/bin/nums.txt
	./cockpoints
