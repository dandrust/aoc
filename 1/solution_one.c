#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Expect 4-byte number, plus newline
#define BUFFER_SIZE 5

int main() {
  int fd;
  char *ptr;
  long last_depth;
  int increments = 0;
  ssize_t bytes_read;

  fd = open("input.txt", O_RDONLY);
  char *buffer = (char *)malloc(BUFFER_SIZE);

  while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
    long depth = strtol(&buffer[0], &ptr, 10);

    if (last_depth) {
      if (depth > last_depth) increments++;
    }

    last_depth = depth;
  }

  printf("%d\n", increments);
}