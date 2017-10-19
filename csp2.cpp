
#include <iostream>
#include <list>
using namespace std;

int V;
list<int> *adj;

void Coloring()
{
	int result[100];
	bool available[3];

	result[0] = 0;

	for (int i = 1; i < V; i++)
	{
		result[i] = -1;
		available[i] = false;
	}

	for (int u = 1; u < V; u++)
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (result[*i] != -1)
				available[result[*i]] = true;
		}

		int cr;
		for (cr = 0; cr < V; cr++)
		{
			if (available[cr] == false)
				break;
		}

		result[u] = cr;

		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (result[*i] != -1)
				available[result[*i]] = false;
		}
	}

	for (int u = 0; u < V; u++)
	{
		cout << "Vertex " << u << " is Colored with " << result[u] << endl;
	}
}

int main()
{
	int n1, n2;
	int v, e;
	cin >> v >> e;

	V = v;
	adj = new list<int>[V];

	for (int i = 0; i < e; i++)
	{
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);

	}

	cout << "\nColoring the graph : \n";
	Coloring();


	return 0;
}

/*
5 6
0 1
0 2
1 2
1 3
2 3
3 4
*/
/*
12 23
0 1
1 2
0 3
1 3
3 4
4 5
2 4
3 6
4 6
6 7
1 4
2 5
4 7
5 7
5 8
7 8
6 9
9 10
7 9
7 10
8 10
10 11
8 11

*/
