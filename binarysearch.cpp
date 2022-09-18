#include <iostream>
using namespace std;

// int binarysearch(int a[], int n,int value)
// {
//     // # n=length of list
//     // #a=list
//     // #value=required data
//     int l=0;
//     int r=n-1;

//     if (l <= r)
//     {
//         int mid = (l + r) / 2;
     
//         if (value == a[mid])
//             return mid;

//         if (value < a[mid])
//             r = mid - 1;
//         // return r;

//         if (value > a[mid])
//             l = mid + 1;
//         // return l;
//     }
//     return -1;
// }
// int main(void)
// {

//     int a[] = {2, 3, 4, 9, 11, 25, 35, 48, 55, 115};
//     cout<<a<<endl;
//     int N = 10;
//     int V;
//     cout << "enter value to be searched:" << endl;
//     cin >> V;
    
//     int result = binarysearch(a,N,V);
//     if (result == -1)
//     printf("Not found");
//   else
//     printf("Element is found at index %d", result);
//     return 0;
// }
// C++ program to implement recursive Binary Search


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
// l=left subarray
// r=right sub array
// x=desiered value



	if (l<=r) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (x==arr[mid])
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (x < arr[mid])
			return binarySearch(arr, l, mid - 1, x);
            // decrement in right sub array (r=mid-1)

		
        // if(x>arr[mid])
        else
		return binarySearch(arr, mid + 1, r, x);
            // increment in right  leftarray (l=mid+1)

	}

	
	return -1;
}

int main(void)
{
  int arr[] = {3, 4, 5, 6, 7, 8, 9 , 10,11,12,22,33};
 

	
	int x ;
    cout<<"enter value to be searched:";
    cin>>x;
    int N=10;
    // N =length of array
	// int n = N-1;
    int n = sizeof(arr) / sizeof(arr[0]);
    int l=0;
	int result = binarySearch(arr, l, n-1, x);
	if(result == -1)
		cout << "Element is not present in array";
    else
		 cout << "Element is present at index " << result;
	return 0;
}
