#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define DOWN "down"
#define UP "up"
#define FORWARD "forward"

#define SOLUTION_TWO

void fatal(const char *msg) {
  perror(msg);
  exit(1);
}

struct Position {
  long x;
  long y;
#ifdef SOLUTION_TWO
  long aim;
#endif
};

struct Command {
  char *directive;
  long magnitude;
};

void parse_command(char *command_string, struct Command *command) {
  char *space_position;
  char *ptr;
    
  // Locate the space between the directive string and the magnitude integer and insert a null byte
  // ex. "down 5 -> down\05"
  // Then, let the directive point to the beginning of the command string, which "ends" at the null byte
  // Finally, increment the space pointer by one and that's where our magnitude string begins
  space_position = strchr(command_string, ' ');
  *space_position = '\0';

  command->directive = command_string;
  command->magnitude = strtol(space_position + 1, &ptr, 10);
}

int main() {
  struct Position position = { 0, 0 };
  struct Command command;

  FILE *input; 
  input = fopen("input.txt", "r");
  if (input == NULL) fatal("fopen");

  // Allocate the buffer to read the command from input
  char *buffer;
  size_t buffer_size = BUFFER_SIZE;
  buffer = (char *)malloc(buffer_size * sizeof(char));
  if (buffer == NULL) fatal("malloc");

  while (getline(&buffer, &buffer_size, input) > 0) {

    parse_command(buffer, &command);

    if (strcmp(FORWARD, command.directive) == 0) {
      position.x = position.x + command.magnitude;
      #ifdef SOLUTION_TWO
      position.y = position.y + (command.magnitude * position.aim);
      #endif
      continue;
    }

    if (strcmp(DOWN, command.directive) == 0) {
      #ifdef SOLUTION_TWO
      position.aim = position.aim + command.magnitude;
      #else
      position.y = position.y + command.magnitude;
      #endif
      continue;
    }

    if (strcmp(UP, command.directive) == 0) {
      #ifdef SOLUTION_TWO
      position.aim = position.aim - command.magnitude;
      #else
      position.y = position.y - command.magnitude;
      #endif
      continue;
    }
  }
  

  printf("Position: { x: %ld, y: %ld }\n", position.x, position.y);
  printf("%ld\n", position.x * position.y);


  fclose(input);
  free(buffer);
}
