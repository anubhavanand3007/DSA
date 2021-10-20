// C++ Find the sum of all non-repeated
// elements in an array
#include<bits/stdc++.h>
using namespace std;
 
// Find the sum of all non-repeated elements
// in an array
int findSum(int arr[], int n)
{
    // sort all elements of array
    sort(arr, arr + n);
 
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] != arr[i+1])
            sum = sum + arr[i];
    }
 
    return sum;
}
 
// Driver code
int main()
{
    int arr[] = {2,5,4,7,9,8,4,2};
    int n = sizeof(arr)/sizeof(int);
    cout << findSum(arr, n);
    return 0;
}