#include <iostream>
using namespace std;
#define INF 9999999
#define V 6
int main()
{
    int Graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    int v, w;
    bool known[V];
    int distance[V];
    int previous[V];
    int source, destination, i, k;
    // Initializing the array by false and inf
    for (int i = 0; i < V; i++)
    {
        known[i] = false;
        distance[i] = INF;
    }
    cout << "ENTER THE SOURCE VERTIX:"
         << " ";
    cin >> source;
    distance[source] = 0;
    previous[source] = -1;

    for (int i = 0; i < V; i++)
    {
        if (distance[i] <= INF && known[i] == false)
        {
            v = i;
            known[i] = true;
            for (int i = 0; i < V; i++)
            {
                if (Graph[v][i] != 0)
                {
                    w = i;
                    if (!known[w] && distance[v] + Graph[v][w] < distance[w] && Graph[v][w] && distance[v] != INF)
                    {
                        // know==false and distance of vertex+weight <distance of corresponding vertex
                        distance[w] = distance[v] + Graph[v][w];
                        previous[w] = v;
                    }
                }
            }
        }
    }
    cout << "Enter your destination: " <<" ";
    cin >> destination;
    cout << "The total cost to reach " << destination << " is " << distance[destination] << endl;

    if (destination != source)
    {
        cout << "Shortest Path to reach " << destination;
        k = destination;
        do
        {
            k = previous[k];
            cout << "<---" << k;
        } while (k != source);
        cout << endl;
    }
    return 0;
}