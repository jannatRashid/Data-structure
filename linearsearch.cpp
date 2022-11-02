#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int value)
{  
  
    for (int i = 0; i < size; i++)
       { if (arr[i] == value)
       return i+1;}

        
           
    return -1;   

}

int main()
{
    int arr[] = {10, 5, 15, 20, 22, 26, 38, 33, 40};
    for (int i = 0; i < 9; ++i)
    {
        cout << arr[i] << "  ";
        
    }
    cout<<endl;

    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "enter your required value" << endl;
    cin >> x;
    int result = linearsearch(arr, n, x);
    if(result==-1){
        cout<<"your required value not found;"<<endl;

    }
    else{
        cout<<"element found at position::"<<result<<endl;
    }
   
    
    return 0;
}
