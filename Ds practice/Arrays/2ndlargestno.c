//2largestno.c
//finding the second largest number in an array



int main()
{
    int n, arr[20], l_large, pos, post;
    printf("\nEnter the number of elements in an array: ");
    scanf("%d", &n);

    printf("Enter the array elements : ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    l_large = arr[0];
    pos = 0;
    for(int i = 1; i < n; i++)
    {
        if(l_large < arr[i])
        {
            l_large = arr[i];
            pos = i;
        }
    }
    l_large = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[pos])
        {
            i++;
            printf("\np");
            continue;
        }
        if(l_large < arr[i])
        {
            l_large = arr[i];
            post = i;
        }

    }
    printf("Largest no. is : %d", l_large);
    return 0;
}