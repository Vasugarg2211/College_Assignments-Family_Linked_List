/*
    Answer 1:
in In-place sorrting algorithms, the space complexity lies between O(1) and O(logn) both included.
so, in in-place sorting algorithms, we can say that is does not require extra space for proccessing and produces an output in the same memory as that contains the data by transforming the input.
Whereas in Out-Place sorting algorithm is algorithm whose space complexity is 
greater than O(logn)
*/

//  Answer 2:

#include<bits/stdc++.h>
using namespace std;

void insertionSortInplace(int arr[],int n)
{
    int i = 0, j = i+1;
    
    while(j <= n-1)
    {
        int var = arr[j];
        while(i >= 0)
        {
            if(arr[i] > var)
            {
                arr[i+1] = arr[i];
                i--;
            }
            if(i == -1)
            {
                arr[0] = var;
                break;
            }
            if(arr[i] <= var)
            {
                arr[i+1] = var;
                break;
            }
        }
        
        j++;
        i = j-1;
    }
    return;
}

void insertionSortOutplace(int arr[],int s,int e)
{
    if(s == e) return;
    
    int j = s + 1;
    int temp = arr[j];
    
    while (s >= 0)
    {
        if(arr[s] > temp)
        {
            arr[s+1] = arr[s];
            s--;
        }
        
        if(s == -1)
        {
            arr[0] = temp;
            break;
        }
        if(arr[s] <= temp)
        {
            arr[s+1] = temp;
            break;
        }
    }
    insertionSortOutplace(arr,s+1,e);
    
}

int main()
{
    int arr[] = {5,6,9,1,4,3,5,4};
    
    
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSortInplace(arr,n);
    cout<<"Array after inplace insertion sort:\n";
    
    for(auto i:arr) cout<<i<<' ';
    cout<<endl;
    
    insertionSortOutplace(arr,0,n-1);
    cout<<"Array after outplace insertion sort:\n";
    for(auto i:arr) cout<<i<<' ';
    
    return 0;
}

/*
    Answer 3:
    
In-place techniques have lesser space complexity but are difficult to 
apply in algorithm whereas out-place techniques are easy to apply but 
increases the space complexity of algorithm.

For exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the 
middle of array whereas if we want to solve the same problem using out-place 
algorithm we have to create one extra array of same size and copy 
elements of original array from back to the front of new array,this 
algorith increases the space complexity to O(n) as we have creaed an 
extra array.

IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort,Quick sort, Because merge sort requires O(n) extra space.
*/
