#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

void create_file(const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("File creation failed");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    close(fd);
}

void write_to_file(const char *filename, const char *data) {
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("File open failed");
        return;
    }
    write(fd, data, strlen(data));
    printf("Data written to file '%s'.\n", filename);
    close(fd);
}

void read_from_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File open failed");
        return;
    }
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("File read failed");
    } else {
        buffer[bytesRead] = '\0';
        printf("Data read from file '%s':\n%s\n", filename, buffer);
    }
    close(fd);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("File deletion failed");
    }
}

int main() {
    const char *filename = "example.txt";
    const char *data = "This is some sample data to write to the file.\n";

    create_file(filename);
    write_to_file(filename, data);
    read_from_file(filename);
    delete_file(filename);

    return 0;
}
