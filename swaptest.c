#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char** argv) {
    int max = -1;
    int mb = 0;
    int multiplier = 1; // allocate 1 MB every time unit. Increase this to e.g.100 to allocate 100 MB every time unit.
    char* buffer;

    if(argc > 1)
        max = atoi(argv[1]);

    while((buffer=malloc(multiplier * 1024*1024)) != NULL && mb != max) {
        memset(buffer, 1, multiplier * 1024*1024);
        mb++;
        printf("Allocated %d MB\n", multiplier * mb);
        sleep(1); // time unit: 1 second
    }      
    return 0;
}
