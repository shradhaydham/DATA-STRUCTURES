#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",ptr+i);
    printf("The array elements are: \n");
    for (int i = 0; i < n; i++)
    printf("%d\n",*(ptr+i));
    int sum=0;
    for (int i = 0; i < n; i++)
    sum=sum + *(ptr+i);
    printf("The Sum of the array elements is: %d",sum);
    return 0;
}
