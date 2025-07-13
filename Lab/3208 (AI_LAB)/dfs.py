def dfs_recursive(graph, node, visited=None):
    """Recursive implementation of Depth-First Search for weighted graphs."""
    if visited is None:
        visited = set()
    
    visited.add(node)
    print(f"Visited node: {node}")
    
    # Explore neighbors
    for neighbor, weight in graph[node]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited) #Python passes mutable objects like sets by reference
    
    return visited


def dfs_iterative(graph, start_node):
    """Iterative implementation of Depth-First Search for weighted graphs."""
    visited = set()
    stack = [start_node]
    
    while stack:
        node = stack.pop()
        
        if node not in visited:
            visited.add(node)
            print(f"Visited node: {node}")
            
            for neighbor, weight in reversed(graph[node]): 
                if neighbor not in visited:
                    stack.append(neighbor) 
    
    return visited


def find_path_dfs(graph, start, end, path=None, visited=None):
    """Find a path from start to end using DFS."""
    if path is None:
        path = []
    if visited is None:
        visited = set()
    
    path = path + [start]
    visited.add(start)
    
    if start == end:
        return path
    
    for neighbor, _ in graph[start]:
        if neighbor not in visited:
            new_path = find_path_dfs(graph, neighbor, end, path, visited)
            if new_path:
                return new_path
    
    return None


def calculate_path_weight(graph, path):
    """Calculate the total weight of a given path."""
    if not path or len(path) < 2:
        return 0
    
    total_weight = 0
    for i in range(len(path) - 1):
        current = path[i]
        next_node = path[i + 1]
        
        # Find weight between current and next node
        for neighbor, weight in graph[current]:
            if neighbor == next_node:
                total_weight += weight
                break
    
    return total_weight


# Example usage
if __name__ == "__main__":
    # Define a weighted graph using adjacency list with (node, weight) tuples
    graph = {
        'S': [('A', 3), ('B', 5), ('C', 6)],
        'A': [('F', 2)],
        'B': [('E', 2), ('D', 1)],
        'C': [('H', 4)],
        'D': [('G', 2)],
        'E': [('G', 2)],
        'F': [],
        'G': [],
        'H': [('G', 3)]
    }
    
    print("Recursive DFS starting from node 'S':")
    dfs_recursive(graph, 'S')
    
    print("\nIterative DFS starting from node 'S':")
    dfs_iterative(graph, 'S')
    
    print("\nFinding path from 'S' to 'G':")
    path = find_path_dfs(graph, 'S', 'G')
    print(f"Path: {path}")
    
    if path:
        weight = calculate_path_weight(graph, path)
        print(f"Path weight: {weight}")