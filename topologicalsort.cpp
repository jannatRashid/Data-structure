#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int vertices, option;
    int edges, row, column, k = 0;
    // forming adjency matrix
    cout << "ENTER NO. OF VERTICES=";
    cin >> vertices;
    int graph[vertices][vertices];
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "ENTER NO. OF EDGES=";
    cin >> edges;
    while (k < edges)
    {
        cout << "Enter source: " <<" ";
        cin >> row;
        cout << "Enter its destination : " << " ";
        cin >> column;
        graph[row][column] = 1;

        k++;
    }

    // to print adjencency matrix
    cout<<"...::displaying the adjacency matrix::..."<<endl;
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {

            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int indegree[vertices];

    for (int i = 0; i < vertices; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[j][i] != 0)
            {
                indegree[i]++;
            }
        }
    }



    cout<<"...::BEFORE SORTING THE INDEGREE OF EACH VERTIX WAS::..."<<endl;
    for(int i=0;i<vertices;i++){
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
    //initializing the array with false flag
    bool selected[vertices];
    for (int i = 0; i < vertices; i++)
    {
        selected[i] = false;
    }

    unsigned int counter;
    int topnum[vertices];
    int v,w;
    cout << "Topological Sorting of the given directed graph" << endl;
    for (counter=0;counter<vertices;counter++){
        for (int i=0;i<vertices;i++){
            if(indegree[i]==0 && selected[i]==false){
                v=i;
                cout<<v<<" ";
                selected[v] = true; // Once the vertice is selected change its state to true
                for (int i = 0; i < vertices; i++)
                {
                    if (graph[v][i] == 1)
                    {
                        w = i;
                        indegree[w]--; // Pop the indegree by 1 of those vertices associated with the selected one
                    }
                }

            }
        }
    }
    if (v == -1)
        {
            cout << "Graph is Cyclic" << endl; // If none of the vertices indegree is zero then the graph is cyclic
        }

        topnum[v] = counter;
        cout << endl;
    cout << "...:: AFTER SORTING THE INDEGREE OF EACH VERTIX IS::..." << endl;
    for (int i = 0; i < vertices; i++)
    {

        cout << indegree[i] << " ";
    }
    cout << endl;







}

