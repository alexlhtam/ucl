// Write a function with the signature int* sort(int* n) that takes a pointer to an array of
// 10 integers, and returns a pointer to a new array containing the integers in sorted order.

// Note that a sort function with the signature above is not given the size of the array to be sorted,
// and can only work with a fixed size array where the size is specified elsewhere in the program. A
// better signature would be int* sort(int* n, int size) that adds a second parameter
// giving the size of the array to be sorted. Modify a copy of your function, edit it to have this
// signature with a new name, and update the function body to use the size parameter.

# include <stdio.h>
# include <stdlib.h>


int* sort(int* n) {
    int *newArr = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) newArr[i] = n[i];

    int temp;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (newArr[j] > newArr[j+1]) {
                temp = newArr[j];
                newArr[j] = newArr[j+1];
                newArr[j+1] = temp;
            }
        }
    }

    return newArr;
}

int* var_sort(int* n, int len) {
    int *newArr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) newArr[i] = n[i];

    int temp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-1; j++) {
            if (newArr[j] > newArr[j+1]) {
                temp = newArr[j];
                newArr[j] = newArr[j+1];
                newArr[j+1] = temp;
            }
        }
    }

    return newArr;
}


int main(void) {
    int nums[] = {50, 10, 40, 20, 30};
    int length = 5;

    int *sorted = var_sort(nums, length);

    printf("Original: ");
    for (int i = 0; i < length; i++) printf("%d ", nums[i]);
    printf("\n");

    printf("Sorted:   ");
    for(int i =  0; i < length; i++) printf("%d ", sorted[i]);
    printf("\n");

    free(sorted);

    return 0;
}