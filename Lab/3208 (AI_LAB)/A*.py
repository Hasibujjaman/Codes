import heapq

h_s = 15



def uniform_cost_search(graph, start, goal):
    # Priority queue of (heuristic_val, node) pairs
    # Using heap to efficiently get the node with the lowest heuristic_val
    priority_queue = [(h_s, start)]
    # To keep track of visited nodes
    visited = set()
    # For path reconstruction: maps node to (parent, heuristic_val, cost)
    parent = {start: (None, h_s, 0)}
    
    while priority_queue:
        # Get the node with the lowest heuristic_val
        current_heuristic, current_node = heapq.heappop(priority_queue)
        
        # Skip if already visited
        if current_node in visited:
            continue
        
        # Mark as visited
        visited.add(current_node)
        
        # Check if we've reached the goal
        if current_node == goal:
            # Reconstruct path
            path = []
            current_cost = 0

            while current_node:
                print(f"current_node={current_node}")
                print(f"parrent[current_node]: {parent[current_node]}")
                print(f"Current node: {current_node}, parent: {parent[current_node][0]}, {current_node}, --> {parent[current_node][0]}, cost: {parent[current_node][2]}")
                print("\n")

                current_cost += parent[current_node][2]
                path.append(current_node)
                current_node = parent[current_node][0] # node : (parent, heuristic_val, cost)
            return list(reversed(path)), current_cost
        
        # Explore neighbors
        for neighbor, heuristic_val in graph[current_node].items(): # neighbor: (heuristic_val, cost)
            if neighbor not in visited:
                # Total heuristic_val to reach neighbor through current path
                new_heuristic = current_heuristic + (heuristic_val[0]+heuristic_val[1])
                
                # If we found a better path to the neighbor
                if neighbor not in parent or new_heuristic < parent[neighbor][1]:
                    parent[neighbor] = (current_node, new_heuristic, heuristic_val[1])  # node : (parent, heuristic_val, cost)
                    heapq.heappush(priority_queue, (new_heuristic, neighbor))
    
    # No path found
    return None, float('inf')





# Example usage
if __name__ == "__main__":
    # Sample graph: {node: {neighbor: heuristic_val}}
    graph = {
        'S': {'A': (3, 12), 'B': (5, 6), 'C': (6, 10)},
        'A': {'F': (2, float('inf'))},
        'B': {'E': (2, 3), 'D': (1, 2)},
        'C': {'H': (4, 7)},
        'D': {'G': (2, 0)},
        'E': {'G': (2, 0)},
        'F': {},
        'G': {},
        'H': {'G': (3, 0)}
    }
    
    path, cost = uniform_cost_search(graph, 'S', 'G')
    if path:
        print(f"Path found: {' -> '.join(path)}")
        print(f"Total cost: {cost}")
    else:
        print("No path found")