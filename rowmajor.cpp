#include<iostream>
using namespace std;
int main(){
     int row,column;
    cout<<"enter number of rows = ";
    cin>>row;
    cout<<"enter number of columns = ";
    cin>>column;
    int list[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout<<"start entering elements row wise ";
            cin>>list[i][j];
        }
}
        for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%u",list[i][j]);
        }
        cout<<"\n";
    }
   int *ba ;
    ba=&list[0][0];
cout<<"base address"<<endl;

    printf("%u",&ba);
// cout<<"base address"<<endl;
    // printf("%u",&list[0][0]);
    cout<<endl;
     int x;
     int y;
    cout<<"enter coordinate at x = "<<endl;
    cin>>x;
    cout<<"enter coordinate at y = "<<endl;
    cin>>y;
   printf("%u",8125864+((x*row+y)*4));
   int u;
   int v;
   cout<<endl;
//    cout<<"enter coordinates to get the index number :"<<endl;
//    cin>>u;
//    cin>>v;
   cout<<"index  number ::";
   printf("%u",(x*row+y));
}