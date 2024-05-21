#include <stdio.h>
// Function to validate if the array is sorted in ascending order
int validateSortedArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}
// Function to perform binary search on a sorted list of integers
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid; // Target value found, return the index
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Search the right half
        }
        else
        {
            high = mid - 1; // Search the left half
        }
    }
    return -1; // Target value not found
}
int main()
{
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    // Validate if the array is sorted
    if (validateSortedArray(arr, n))
    {
        printf("Enter the element to be searched: ");
        scanf("%d", &target);
        // Perform binary search
        int result = binarySearch(arr, n, target);
        if (result != -1)
        {
            printf("Target value %d found at index: %d\n", target, result);
        }
        else
        {
            printf("Target value %d not found in the array.\n", target);
        }
    }
    else
    {
        printf("The entered array is not sorted.\n");
    }
    return 0;
}
