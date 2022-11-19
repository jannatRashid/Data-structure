// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;
#define high 9999999

// number of vertices in graph
#define V 5

// creating a 2d array of size 5X5 for adjacency matrix to represent graph

int G[V][V] = {
    //     0  1  2  3  4
    /*0*/ {0, 4, 0, 5, 2},
    /*1*/ {4, 0, 1, 3, 0},
    /*2*/ {0, 1, 0, 8, 0},
    /*3*/ {5, 3, 8, 0, 2},
    /*4*/ {2, 0, 0, 2, 0}};

int main()
{
    int edge; // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];
    // set selected false initially
    memset(selected, false, sizeof(selected));
    edge = 0; // set no.of edges =0
    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    // print for edge(source destination) and weight
    cout << "source"
         << " - "
         << "deatination"
         << " : "
         << "Weight";
    cout << endl;
    while (edge < V - 1)
    {
        {
            int min = high;
            x = 0;
            y = 0;
            for (int i = 0; i < V; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < V; j++)
                    {
                        if (!selected[j] && G[i][j])
                        { // not in selected and there is an edge
                            if (min > G[i][j])
                            {
                                min = G[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout << x << " - " << y << " :  " << G[x][y];
            cout << endl;
            selected[y] = true;
            edge++;
        }
    }
}
