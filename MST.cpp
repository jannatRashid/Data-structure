#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class edge
{
public:
    int source;
    int dest;
    int weight;
};

int findparent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findparent(parent[v], parent);
}
bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}
void kruskals(edge *input, int n, int e)
{
    // sort the input array ascending order based on weights
    sort(input, input + e, compare);
    edge *output = new edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        edge currentedge = input[i];
        // check if we can add the current edge in MST or not
        int sourceparent = findparent(currentedge.source, parent);
        int destparent = findparent(currentedge.dest, parent);
        if (sourceparent != destparent)
        {
            output[count] = currentedge;
            count++;
            parent[sourceparent] = destparent;
        }
        i++;
    }
    cout<<"...::MINIMUM SPANNING TREE::..."<<endl;
    cout<<"source__destination____weight"<<endl;

    for (int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;

        }
    }
}


int main()
{
    int n, e; // n=vertices and e=edges
    cout << "enter no. of vertices : n=";
    cin >> n;
    cout << "enter no. of edges : e=";
    cin >> e;
    cout << endl;
    edge *input = new edge[e];
    cout << "...::ENTER GRAPH::..." << endl;

    cout << "enter__source destination weight" << endl;
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskals(input, n, e);
}