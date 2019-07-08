#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "baudcat.h"

//#define TEST

int main(int argc, char *argv[]) {
	char * filename = argv[1];
	int c;
	int bps = 300; 
	FILE *fd;	

    char test_str[] = "We are baudcat-ing this buffer :) \n";

   	// disable buffering on stdout 
	setbuf(stdout, NULL);	
	if (argc < 2) {
		printf("usage: baudcat filename [bps]\n");
		exit(0);
	}

	if ( argv[2] != NULL ) {
		bps = atoi(argv[2]);
#ifdef TEST
		printf("baudrate set at %d\n", bps);
#endif 
	}

#ifdef TEST
    printf("\n[+] Printing from buffer (buffer size: %lu): \n", sizeof(test_str));
    baudcat_string(test_str, bps);

    printf("\n[+] Printing from filename: \n");
#endif
    baudcat_file(filename, bps);

	return 0;
}

