#include<bits/sdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int x)
{
    while(true) // no condition to stop the loop until the element not found.
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

int binary_search(vector<int> &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    vector<int> arr;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter key to search : ";
    cin >> x;

    cout << "Index using linear search is : " << linear_search(arr, x) << endl;
    cout << "Index using binary search is : " << binary_search(arr,0,n-1,x) << endl;
    
    return 0;
}
