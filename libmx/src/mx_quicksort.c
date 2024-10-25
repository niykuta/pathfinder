#include <../inc/libmx.h> 

int partition(char **arr, int left, int right, int *swap_count) {
    int pivot = (left + right) / 2; 
    int pivot_len = strlen(arr[pivot]);

    while (left < right) {
        while (mx_strlen(arr[left]) < pivot_len) {
            left++;
        }
         while (mx_strlen(arr[right]) > pivot_len) {
            right--;
        }
        if (left <= right) {
            if(mx_strlen(arr[left]) != mx_strlen(arr[right])){
                mx_swap_str(&arr[left], &arr[right]);
                (*swap_count)++;
            }
            left++;
            right--;
        }
    }
    return left;
}

int mx_quicksort(char **arr, int left, int right) { 
    if (!arr) { 
        return -1; 
    } 
 
    int swap_count = 0; 

    if (left < right) {
        int pivot_index = partition(arr, left, right, &swap_count);
        swap_count += mx_quicksort(arr, left, pivot_index - 1); 
        swap_count += mx_quicksort(arr, pivot_index + 1, right); 
    }
 
    return swap_count; 
} 

