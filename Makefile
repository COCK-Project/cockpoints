all:
	gcc cockpoints.c -o cockpoints -pipe -march=native
	ls ~/.local/bin || mkdir ~/.local/bin
	cp cockpoints ~/.local/bin/cockpoints
	touch ~/.local/bin/nums.txt
	./cockpoints
