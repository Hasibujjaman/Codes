import heapq

# Uniform Cost Search (UCS)

def uniform_cost_search(graph, start, goal):
    # Priority queue of (cost, node) pairs
    # Using heap to efficiently get the node with the lowest cost
    priority_queue = [(0, start)]
    # To keep track of visited nodes
    visited = set()
    # For path reconstruction: maps node to (parent, cost)
    parent = {start: (None, 0)}
    
    while priority_queue:
        # Get the node with the lowest cost
        current_cost, current_node = heapq.heappop(priority_queue)
        
        # Skip if already visited
        if current_node in visited:
            continue
        
        # Mark as visited
        visited.add(current_node)
        
        # Check if we've reached the goal
        if current_node == goal:
            # Reconstruct path
            path = []
            while current_node:
                path.append(current_node)
                current_node = parent[current_node][0]
            return list(reversed(path)), current_cost
        
        # Explore neighbors
        for neighbor, cost in graph[current_node].items():
            if neighbor not in visited:
                # Total cost to reach neighbor through current path
                new_cost = current_cost + cost
                
                # If we found a better path to the neighbor
                if neighbor not in parent or new_cost < parent[neighbor][1]:
                    parent[neighbor] = (current_node, new_cost)
                    heapq.heappush(priority_queue, (new_cost, neighbor))
    
    # No path found
    return None, float('inf')





# Example usage
if __name__ == "__main__":
    # Sample graph: {node: {neighbor: cost}}
    graph = {
        'S': {'A': 3, 'B': 5, 'C': 6},
        'A': {'F': 2},
        'B': {'E': 2, 'D': 1},
        'C': {'H': 4},
        'D': {'G': 2},
        'E': {'G': 2},
        'F': {},
        'G': {},
        'H': {'G': 3}
    }
    
    path, cost = uniform_cost_search(graph, 'S', 'G')
    if path:
        print(f"Path found: {' -> '.join(path)}")
        print(f"Total cost: {cost}")
    else:
        print("No path found")