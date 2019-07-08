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
