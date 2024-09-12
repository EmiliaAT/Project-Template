/**
 * Assignment 1
 *
 * Reads a given amount of numbers from the console into a dynamically
 * allocated array and displays them in reverse order before freeing.
 *
 * @author JustMisaki
 * @date   2024/09/04
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Reads an integer from the console until a valid input is given.
 *
 * @param[out] dest   The pointer to the output destination.
 * @param[in]  prompt The prompt to display for input.
 */
static void read_int(int *dest, const char *prompt);

void read_int(int *dest, const char *prompt) {
  // The string buffer for console input.
  // This is safely uninitialised as it is not read until after it is written
  // to.
  char buffer[12];
  // The return code from the call to `sscanf()` used to parse an numeric
  // string.
  int result;
  // The intermediate integer value read from the console.
  int value;

  // Prompt user for input in a loop until a valid input is given.
  while (1) {
    printf("%s", prompt);

    // Read the user input from the console and parse as an integer.
    fgets(buffer, 12, stdin);
    result = sscanf(buffer, "%d", &value);

    // Break out of the loop if the input was valid and successfully parsed.
    if (!(result == 0 || result == EOF)) {
      break;
    }

    printf("Invalid input, please try again.\n\n");
  }

  // Read the successful intermediate value into the destination.
  *dest = value;
}

int main(void) {
  // The number of elements to be read from the console.
  int num_elems;
  // The dynamically allocated array of integer elements read from the console.
  // This is safely uninitialised as it is not read until after it is written
  // to.
  int *elems;

  // Read the number of elements from the console.
  printf(
      "Please enter the number of array elements you would like to input.\n\n");
  read_int(&num_elems, "Total: ");

  // Ensure that the number of elements is a valid postive non-zero number.
  while (num_elems <= 0) {
    printf("Please enter a positive non-zero value.\n\n");
    read_int(&num_elems, "Total: ");
  }

  // Dynamically allocate `num_elems` amount of integers into `elems`
  elems = (int *)malloc(sizeof(int) * num_elems);

  printf("\n========================================================\n\n");
  printf("Please input the array elements.\n\n");

  // Reads the array elements from the console iteratively.
  for (int i = 0; i < num_elems; i++) {
    read_int(&elems[i], "Next Value: ");
  }

  printf("\n========================================================\n\n");
  printf("Displaying array elements in reverse order...\n\n");

  // Displays the array elements in reverse.
  for (int i = num_elems - 1; i >= 0; i--) {
    printf("Value [%d]: %d\n", i, elems[i]);
  }

  printf("\n========================================================\n\n");
  printf("Done!\n");

  // Free the array before returning successfully.
  free(elems);
  elems = NULL;

  return 0;
}
