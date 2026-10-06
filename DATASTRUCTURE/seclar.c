#include <stdio.h>
#include <limits.h>
int main()
{
int arr[] = {45,45,44,43,2};
int n = sizeof(arr) / sizeof(arr[0]);
int first = INT_MIN, second = INT_MIN;
for (int i = 0; i < n; i++)
{
if (arr[i] > first)
{
second = first;
first = arr[i];
}
else if (arr[i] > second && arr[i] != first)
{
second = arr[i];
}
}
printf("%d\n", second);
return 0;
}