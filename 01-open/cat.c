#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[4096];

    // iterate through command-line arguments (starting at argv[1]).
    for (int i = 1; i < argc; i++) {
        // open file
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0) {
            perror("open");
            return EXIT_FAILURE;
        }

        // keep reading until EOF
        int bytes;
        while((bytes = read(fd, &buffer[0], sizeof(buffer))) > 0) {
            if(write(1, &buffer[0], bytes) < 0) {
                perror("write");
                return EXIT_FAILURE;
            }
        }

        // handle read error
        if(bytes < 0) {
            perror("read");
            return EXIT_FAILURE;
        }

        // handle close error
        if(close(fd) != 0) {
            perror("close");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
