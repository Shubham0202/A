Q1. 

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Open a file for writing (create if it doesn't exist)
    int fd = open("file_with_hole.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Write some initial data
    write(fd, "Start", 5);

    // Create a hole by seeking forward
    lseek(fd, 1024, SEEK_CUR); // Skip 1 KB

    // Write more data
    write(fd, "End", 3);

    // Close the file
    close(fd);

    printf("File with a hole created: file_with_hole.txt\n");
    return 0;
}

