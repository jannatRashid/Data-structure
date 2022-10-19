#include <iostream>
using namespace std;
#include <conio.h>
void minBH(int *pq, int i, int data){
   int lc, t,rc;
   t= pq[i]; 
   lc = 2 * i;
   rc=lc+1;
   //lc+1= right node
   while (lc<= data) {
      if (lc < data && pq[rc] < pq[lc])
         lc = rc;
      if (t < pq[lc])
         break;
       else if (t >= pq[lc]) {
         pq[lc/2] = pq[lc];
         lc = 2 * lc;
      }
      else break;
   }
     pq[lc/2] = t;
   
   
   return;
}
void creation(int *pq, int n) { //root node creation with i/2 index 
   int k;
   for(k = n/2; k >= 1; k--) {
      minBH(pq,k,n);
   }
}
int main() {
   int n, i;
   cout<<"enter no of elements of array\n";
   cin>>n;
   int a[30];
   for (i = 1; i <= n; i++) {
      cout<<"enter element"<<" "<<(i)<<endl;
      cin>>a[i];
   }
   creation(a, n);
   cout<<"Min binary Heap tree\n";
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
   getch();
}