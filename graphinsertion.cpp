#include <iostream>
using namespace std;

int adjmat[6][6];
int count=0;

void displaymat(int vertices){
    for(int i=0;i<vertices;i++){
        for (int j=0;j<vertices;j++){
            cout<<adjmat[i][j]<<"  ";

        }

        cout<<endl;
       

    }

}
void edges(int u,int v){
    adjmat[u][v]=1;
    adjmat[v][u]=1;

}
int main(){
   
    int vertices=4;
   
    edges(0, 1);
   edges(0, 2);
   edges(1, 2);
   edges(2, 3);
   edges(1, 0);
   edges(2, 0);
   edges(2, 1);
   edges(3, 2);
   
    displaymat(vertices);
}