#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int main(int argc, char **argv) {
  // Create a string that contains the "awk" command and its arguments.
  char *awk_cmd = "awk '{ print $1 }' input.txt";

  // Use the execve function to execute the "awk" command.
  execve("/usr/bin/awk", &awk_cmd, NULL);
  printf("run error\n");
  return 0;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
*/

int main(int argc, char **argv) {
  // Create an array of strings that contains the "awk" command and its arguments.
  char *awk_cmd[] = {
    "/usr/bin/awk",
    "{ print $1 }",
    "input.txt",
    NULL
  };

  // Use the execve function to execute the "awk" command.
  execve("/usr/bin/awk", awk_cmd, NULL);

  return 0;
}
