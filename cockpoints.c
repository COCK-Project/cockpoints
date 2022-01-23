#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"

// Location is edited in ./config.h

int main(int argc, char *argv[]) {
//    if(argc < 3) {
//        puts("Usage: add -a [num]");
//        return -1;
//    }
    int opt = getopt(argc, argv, "a:");
    char *num;

    switch(opt) {
        case 'a':
            num = optarg;
    }

    FILE *file = fopen(location, "r");
    if(!file) {
        perror("add");
        return -1;
    }

    char str[9];
    int c;
    short int i = 0;

    while((c = fgetc(file)) != EOF && i < 9) {
        *(str + i) = c;
        i++;
    }

    fclose(file);
    int num1 = atoi(str);
    char str1[9];

    for(i = 0; i < 9; i++)
        *(str1 + i) = *(num + i);

    FILE *fp = fopen(location, "w");

    if(!fp) {
        perror("add");
        return -1;
    }

    fprintf(fp, "%d", num1 + atoi(str1));
    fprintf(stdout, "Current Cockpoints: %d\n", num1 + atoi(str1));

    fclose(fp);

    if(argc < 3) {
        puts("Usage: add -a [num]");
        return -1;
    }

    return 0;
}
