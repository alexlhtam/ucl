// PART A
// Write a function to create and return a pointer to a ragged 2D array data structure. A ragged 2D
// array has rows of different lengths. The basic data structure has a pointer to an array of pointers
// that point to each row, each of which is an array of integers:

// The function should take as a parameter the number of rows and an array that specifies the length
// of each row. The pointer to the ragged array will be of type int**, a pointer to an array of int
// pointers. All the arrays should be allocated memory dynamically on the heap using malloc.
// Write a second function that frees all the memory used by a ragged array, and some other
// functions to confirm that creating and printing your ragged arrays works correctly.

# include <stdio.h>
# include <stdlib.h>

int** create_r_array(int num_rows, int* row_lengths) {
    int** ragged = malloc(num_rows * sizeof(int*));

    for (int i = 0; i < num_rows; i++) {
        ragged[i] = malloc(row_lengths[i] * sizeof(int));
    }

    return ragged;
}

void free_r_array(int** ragged, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        free(ragged[i]);
    }
    free(ragged);
}


int main(void) {
    int height = 3;
    int lengths[] = {3, 2, 4};
    int** ragged = create_r_array(height, lengths);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            ragged[i][j] = (i * 10) + j;
        }
    }

    printf("printing ragged array:\n");
    for (int i = 0; i < height; i++) {
        printf("Row %d: ", i);

        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", ragged[i][j]);
        }

        printf("\n");
    }

    free_r_array(ragged, height);

    return 0;
}