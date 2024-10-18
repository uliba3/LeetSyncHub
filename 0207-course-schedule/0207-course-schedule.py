class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {}
        nodes = set()
        for prerequisite in prerequisites:
            ai, bi = prerequisite
            if bi not in graph:
                graph[bi] = []
            graph[bi].append(ai)
            nodes.add(bi)
        print(graph)
        visited = set()
        for nodei in nodes:
            if nodei in visited:
                continue
            visited.add(nodei)
            rec_visited = set()
            rec_visited.add(nodei)
            stack = []
            stack.append([nodei, rec_visited.copy()])
            while stack:
                node, rec_visited = stack.pop()
                visited.add(node)
                if node not in graph:
                    continue
                for neighbor in graph[node]:
                    if neighbor in rec_visited:
                        return False
                    else:
                        if neighbor not in visited:
                            rec_visited.add(neighbor)
                            stack.append([neighbor, rec_visited.copy()])
                            rec_visited.remove(neighbor)
        return True
