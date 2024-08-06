#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void demonstrate_fcntl(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl get failed");
        return;
    }
    printf("File descriptor flags: %d\n", flags);

    // Set the file descriptor to non-blocking mode
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl set failed");
    } else {
        printf("File descriptor set to non-blocking mode.\n");
    }
}

void demonstrate_lseek(int fd) {
    off_t offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) {
        perror("lseek failed");
        return;
    }
    printf("Current file size: %ld bytes\n", offset);
}

void demonstrate_stat(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("stat failed");
        return;
    }
    printf("File size: %ld bytes\n", fileStat.st_size);
    printf("Number of links: %ld\n", fileStat.st_nlink);
    printf("File owner: %d\n", fileStat.st_uid);
    printf("File group: %d\n", fileStat.st_gid);
}

void demonstrate_opendir(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        perror("opendir failed");
        return;
    }
    
    struct dirent *entry;
    printf("Contents of directory '%s':\n", dirPath);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main() {
    const char *filename = "testfile.txt";
    const char *dirPath = "."; // Current directory

    // Create a test file
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("File open failed");
        return EXIT_FAILURE;
    }

    // Demonstrate fcntl
    demonstrate_fcntl(fd);

    // Demonstrate lseek
    demonstrate_lseek(fd);

    // Demonstrate stat
    demonstrate_stat(filename);

    // Close the file descriptor
