
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int main(int argc, char *argv[]) {
	char * filename = argv[1];
	int c;
	int bps = 300; 
	FILE *fd;	


	// disable buffering on stdout 
	setbuf(stdout, NULL);	
	if (argc < 2) {
		printf("usage: baudcat filename [bps]\n");
		exit(0);
	}

	if ( argv[2] != NULL ) {
		bps = atoi(argv[2]);
		printf("baudrate set at %d\n", bps);
	}
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

	return 0;
}
