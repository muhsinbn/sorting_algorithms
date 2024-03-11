#include "sort.h"
#include <stdio.h>

void *_calloc(unsigned int nmemb, unsigned int size)
{
    if (nmemb * size == 0)
        return NULL;

    char *p = malloc(nmemb * size);
    if (p == NULL)
        return NULL;

    for (unsigned int i = 0; i < (nmemb * size); i++)
        p[i] = '\0';

    return p;
}

void merge(int *arr, int start, int mid, int end)
{
    int size_left = mid - start + 1, size_right = end - mid;
    int array_left[size_left], array_right[size_right];
    int left, right, i = start;

    for (left = 0; left < size_left; left++)
        array_left[left] = arr[start + left];
    for (right = 0; right < size_right; right++)
        array_right[right] = arr[mid + 1 + right];

    left = 0, right = 0;

    while (left < size_left && right < size_right)
    {
        if (array_left[left] <= array_right[right])
            arr[i] = array_left[left++];
        else
            arr[i] = array_right[right++];
        i++;
    }

    while (left < size_left)
        arr[i++] = array_left[left++];

    while (right < size_right)
        arr[i++] = array_right[right++];

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array_left, size_left);
    printf("[right]: ");
    print_array(array_right, size_right);
    printf("[Done]: ");
    print_array(&arr[start], size_left + size_right);
}

void mergesort(int *array, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int *tmp = _calloc(size, sizeof(int));
    if (tmp == NULL)
        return;

    mergesort(array, 0, size - 1);
    free(tmp);
}

