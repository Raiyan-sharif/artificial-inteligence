
graph = {'Arad': set(['Zerind', 'Timisoara','Sibiu']),
         'Zerind': set(['Arad', 'Oradea']),
         'Timisoara': set(['Arad', 'Lugoj']),
         'Sibiu': set(['Arad','Fagaras','Rimnicu']),
         'Oradea': set(['Zerind', 'Sibiu']),
         'Lugoj': set(['Timisoara', 'Mehadia']),
         'Mehadia': set(['Dobreta', 'Lugoj']),
         'Dobreta': set(['Mehadia','Craiova']),
         'Craiova': set(['Rimnicu','Pitesti']),
         'Rimnicu': set(['Sibiu','Pitesti']),
         'Pitesti': set(['Bucharest','Rimnicu','Craiova']),
         'Fagaras': set(['Sibiu','Bucharest']),
         'Bucharest': set(['Pitesti','Fagaras'])
         }



def bfs_paths(graph, start, goal):
    queue = [(start, [start])]
    while queue:
        (vertex, path) = queue.pop(0)
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                queue.append((next, path + [next]))

print('all path using bfs....\n')
print(list(bfs_paths(graph, 'Arad', 'Bucharest')))


print('\n\npath using bfs\n')

def shortest_path(graph, start, goal):
    try:
        return next(bfs_paths(graph, start, goal))
    except StopIteration:
        return None

print(shortest_path(graph, 'Arad', 'Bucharest')) 
