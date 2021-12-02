#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Expect 4-byte number, plus newline
#define BUFFER_SIZE 5

int main() {
  int fd;
  char *ptr;
  long window[3], last_window_sum, current_window_sum;
  int write_pos = 0;
  int increments = 0;
  ssize_t bytes_read;

  fd = open("input.txt", O_RDONLY);
  char *buffer = (char *)malloc(BUFFER_SIZE);

  // populate first window
  for (int i = 0; i < 3; i++) {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    long depth = strtol(&buffer[0], &ptr, 10);
    window[i] = depth;
  }

  // capture first window sum
  last_window_sum = window[0] + window[1] + window[2];

  while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
    long depth = strtol(&buffer[0], &ptr, 10);

    // write new value, set write_pos to oldest value
    window[write_pos] = depth;
    if (++write_pos > 2) write_pos = 0;

    current_window_sum = window[0] + window[1] + window[2];

    if (last_window_sum) {
      if (current_window_sum > last_window_sum) increments++;
    }

  last_window_sum = current_window_sum;

  }

  free(buffer);
  printf("%d\n", increments);
}