#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* revisedRussianRoulette(int doors_size, int* doors, int *result_size) {
    // Complete this function
    int i,*arr = malloc(sizeof(int)*2);
    *result_size = 2;
    arr[0] = 0;
    arr[1] = 0;
    for(i=doors_size-1;i>=0;i--)
        if(doors[i])
            arr[1]++;
    for(i=0;i<doors_size;i++) {
        if(doors[i]) {
            arr[0]++;
            i++;
        }
    }
    return arr;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *doors = malloc(sizeof(int) * n);
    for (int doors_i = 0; doors_i < n; doors_i++) {
       scanf("%i",&doors[doors_i]);
    }
    int result_size;
    int* result = revisedRussianRoulette(n, doors, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
