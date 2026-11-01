
#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX], n, i, choice;
    int pos, value, key, found;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n------ ARRAY OPERATIONS ------\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Update Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Array Elements: ");
                for(i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if(pos < 1 || pos > n + 1)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    printf("Enter value: ");
                    scanf("%d", &value);

                    for(i = n; i >= pos; i--)
                        arr[i] = arr[i - 1];

                    arr[pos - 1] = value;
                    n++;

                    printf("Element Inserted Successfully.\n");
                }
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    for(i = pos - 1; i < n - 1; i++)
                        arr[i] = arr[i + 1];

                    n--;
                    printf("Element Deleted Successfully.\n");
                }
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(arr[i] == key)
                    {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Element Not Found.\n");

                break;

            case 5:
                printf("Enter position to update: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    printf("Enter new value: ");
                    scanf("%d", &value);

                    arr[pos - 1] = value;
                    printf("Element Updated Successfully.\n");
                }
                break;

            case 6:
                printf("Program Exited.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

