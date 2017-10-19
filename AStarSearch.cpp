#include<bits/stdc++.h>

using namespace std;

const int a= 999;
const int Lim = 99999999;
int N, E, mat[a][a], distence[a], parent[a];
int start,finish,path[a];
//={7,6,2,1,0};
int main(){
    for( int i = 0; i < a; i++ )
    {
        parent[i] = -1;
        distence[i] = Lim;

        for( int j = 0; j < a; j++ )
        {
            mat[i][j] = -Lim;
        }
    }

    //inputGraph;
    cout<<"Enter Number of Nodes and Edges:"<<endl;

    cin >> N >> E;
    int h[N];
    cout<<"Input all the Edges with path cost:"<<endl;
    for( int i = 0; i < E; i++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    cout<<"Input the heurestic value :"<<endl;
    for(int i=0;i<N;i++){
        cin>>h[i];
    }

    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> finish;
    distence[start] = 0;

    pair <int, int> nd;
    priority_queue < pair<int, int> > PQ;

    nd.first = 0;
    nd.second = start;

    PQ.push(nd);

    while( !PQ.empty() )
    {
        nd = PQ.top();
        PQ.pop();



        int u = nd.second;

        for(int v = 0; v < N; v++)
        {
            if(mat[u][v] != -Lim)
            {
                if(distence[v] + h[v] > distence[u] + mat[u][v])
                {
                    distence[v] = distence[u] + mat[u][v];

                    parent[v] = u;

                    nd.first = distence[v];
                    nd.second = v;

                    PQ.push(nd);
                }
            }
        }
    }
    cout << "Total Path Cost in A* =" << distence[finish] << endl;

    int i=0;
    while(1)
    {
        path[i] = finish;
        finish = parent[finish];

        if(start==path[i])
            break;

        i++;
    }
      while(i>=0)
    {
        cout << path[i] << " ";

        i--;
    }

}

/*Romanian Map
13 16
0 1 75
0 9 118
0 3 140
1 2 71
2 3 151
9 10 111
10 11 70
11 12 75
12 8 120
8 6 146
8 7 138
3 6 80
3 4 99
6 7 97
7 5 101
4 5 211
360 374 380 253 178 0 193 98 160 329 244 241 242
*/
