#include <stdio.h>
#include <stdlib.h>

void print_matrix(int *mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%4d ", *(mat + i*cols + j));
        printf("\n");
    }
}

void bubble_sort(int *arr, int len) {
    int swapped;
    for (int i = 0; i < len - 1; ++i) {
        swapped = 0;
        for (int j = 0; j < len - 1 - i; ++j) {
            if (*(arr + j) > *(arr + j + 1)) {
                int tmp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void) {
    int rows = 2, cols = 3;
    int data[] = { 9, 2, 7, 4, 5, 1 };
    int *mat = malloc(sizeof(int)*rows*cols);
    for (int i = 0; i < rows*cols; ++i) *(mat+i)=data[i];
    printf("Matriz original:\n"); print_matrix(mat,rows,cols);
    bubble_sort(mat, rows*cols);
    printf("\nMatriz ordenada:\n"); print_matrix(mat,rows,cols);
    free(mat);
}
