#include <stdio.h>
// Function to perform linear search
void linearSearch(int arr[], int size, int target, int result[], int *resultSize)
{
    *resultSize = 0; // Initialize the resultSize to 0
    // Iterate through the array
    for (int i = 0; i < size; i++)
    {
        // Check if the current element matches the target
        if (arr[i] == target)
        {
            // Add the matching index to the result array
            result[*resultSize] = i;
            (*resultSize)++; // Increment the resultSize
        }
    }
}
int main()
{
    int size, target;
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Input the target value to search
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    // Declare an array to store matching indices
    int result[size];
    int resultSize;
    // Perform linear search
    linearSearch(arr, size, target, result, &resultSize);
    // Print the matching indices
    if (resultSize > 0)
    {
        printf("Matching indices for target %d: ", target);
        for (int i = 0; i < resultSize; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No matching indices found for target %d.\n", target);
    }
    return 0;
}