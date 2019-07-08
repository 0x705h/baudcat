#ifndef _BAUDCAT_H_
#define _BAUDCAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void baudcat_wait(int bps);
void baudcat_file(char * filename, int bps);
void baudcat_string(char * buffer, int bps);

#endif /* _BAUDCAT_H_ */