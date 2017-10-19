#include<iostream>
#include<utility>
#include<queue>

using namespace std;


const int s = 9999;
const int mat = 9999;
int N, E, adjMat[s][s], dist[s], par[s];
int start,fin,path[s];

void init()
{
     for( int i = 0; i < s; i++ )
    {
        par[i] = -1;
        dist[i] = mat;

        for( int j = 0; j < s; j++ )
        {
            adjMat[i][j] = mat;
        }
    }
}


void input()
{
    cout<<"Input Number Of Nodes,Edges:"<<endl;
     cin >> N >> E;

     cout<<"Input edge to edge connection and Path cost:"<<endl;
    for( int i = 0; i < E; i++ )
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adjMat[u][v] = cost;
    }
}
void print()
{
    cout<< "Total cost: " << dist[fin] << endl;

    int i=0;
    while(1)
    {
        path[i] = fin;
        fin = par[fin];

        if(start==path[i])
            break;

        i++;

    }

    cout<< "Path: ";
    while(i>=0)
    {
        cout << path[i] << " ";

        i--;
    }

}


void ucs()
{
    dist[start] = 0;

    pair <int, int> p;
    priority_queue < pair<int, int> > pq;

    p.first = 0;
    p.second = start;

    pq.push( p );

    while( !pq.empty() )
    {

        p = pq.top();
        pq.pop();

        int u = p.second;

        for( int v = 0; v < N; v++ )
        {
            if( adjMat[u][v] != mat )
            {
                if( dist[v] > dist[u] + adjMat[u][v] )
                {
                    dist[v] = dist[u] + adjMat[u][v];
                    par[v] = u;
                    p.first = dist[v];
                    p.second = v;
                    pq.push( p );
                }
            }
        }
    }
}

int main()
{
    init();
    input();

    cout << "Start node: ";
    cin >> start;
    cout << "Destination node: ";
    cin >> fin;


    ucs();


    print();

    return 0;
}

/*
7 10
0 1 5
0 3 3
1 2 1
2 4 6
2 6 8
3 5 2
3 4 2
4 1 4
5 6 3
6 4 4
*/
