#include <iostream>

using namespace std;

void merg(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1]; // two temperary array to merg left and right sorted arrays
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;

    }
     while(j<n2){
        arr[k]=b[j];
        k++;
        j++;

    }

}

void mergsort(int arr[], int l, int r)
{ // l=left array,r=right array
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergsort(arr, l, mid);
        mergsort(arr, mid + 1, r);
        merg(arr, l, mid, r);
    }
}
int main(){
    int arr[]={8,3,1,6,2,7,9,4};
    int n=8;
    

    cout<<"...::The UnSorted Array Is::..."<<endl;

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergsort(arr,0,n-1);
    cout<<"...::The Sorted Array After Applying Merg Sort Is::..."<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}