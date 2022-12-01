#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    // For cat, we have to iterate over all command-line arguments of
    // our process. Thereby, argv[0] is our program binary itself ("./cat").
    int idx;
    for (idx = 1; idx < argc; idx++) {
        printf("argv[%d] = %s\n", idx, argv[idx]);
    }

    return 0;
}
