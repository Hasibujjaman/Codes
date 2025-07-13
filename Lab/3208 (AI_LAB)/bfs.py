import queue


graph = {
    'S': [('A', 2), ('B', 1), ('C', 3)],
    'A': [('E', 1), ('F', 1)],
    'B': [('G', 2)],
    'C': [('D', 5)],
    'D': [],
    'E': [('H', 2)],
    'F': [('G', 1)],
    'G': [],
    'H': [('G', 1)]
}
parent = {'S': None, 'A': None, 'B': None, 'C': None,'D': None, 'E': None, 'F': None, 'G': None, 'H': None}
visited = {'S': False, 'A': False, 'B': False, 'C': False, 'D':False, 'E': False, 'F': False, 'G': False, 'H': False}
cum_weight = {'S': 0, 'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0, 'F': 0, 'G': 0, 'H': 0}






def bfs(G, start, goal):
    q = queue.Queue(100)

    q.put(start)
    visited[start] = True
    while not q.empty():
        current = q.get()
        print(f"Current node: {current}")

        if current == goal:
            print("Goal found\n\n")
            return
        
        print(G[current])

        for neighbor, weight in G[current]:
            if not visited[neighbor]:
                q.put(neighbor)
                visited[neighbor] = True
                parent[neighbor] = current
                cum_weight[neighbor] = cum_weight[current] + weight
        print(f"Frontier:{list(q.queue)}\n")
    print("Goal not found")



def print_path(parent, start, goal):
    if goal == start:
        print(start)
    elif parent[goal] == None:
        print("No path")
    else:
    
        print_path(parent, start, parent[goal])
        print(goal)




bfs(graph,'S', 'G')
print("Path:")
print_path(parent, 'S', 'G')
print(f"Path weight:{cum_weight['G']}")
