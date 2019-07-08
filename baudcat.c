#include "baudcat.h"

void baudcat_wait(int bps) {
	// ie, if 300 is the bps speed
	// then 300 bits per second must be 
	// shown on screen.
	int bytesPerSec = bps/8;
	if(bytesPerSec > 0) {
		usleep( ( 1000 * 1000 ) / ( bytesPerSec ) );
	} else {
		usleep( ( 1000 * 1000 ) ); // lowest wait
	} 
}

void baudcat_string(char * buffer, int bps) {
	
	int size = strlen(buffer);
	int i = 0;

	// disable buffering on stdout 
	setbuf(stdout, NULL);
	
	while (i < size) {
		baudcat_wait(bps);
		printf("%c", *buffer++);
		i++;
	}	
	
}

void baudcat_file(char * filename, int bps) {
	int c;
	FILE *fd;	

	// disable buffering on stdout 
	setbuf(stdout, NULL);	

	fd = fopen(filename, "r");
	if (fd == NULL) {
		fprintf(stderr, "Could not open file!\n");
		exit(1);
	}
	
	while ((c = fgetc(fd)) != EOF) {
		baudcat_wait(bps);
		printf("%c", (char) c);
	}	

	fclose(fd);
}