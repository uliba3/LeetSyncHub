class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {}
        startNodes = set()
        nonstartNodes = set()
        nodes = set()
        order = []
        reverseG = {}
        for prerequisite in prerequisites:
            ai, bi = prerequisite
            if bi not in graph:
                graph[bi] = []
            graph[bi].append(ai)
            if ai not in reverseG:
                reverseG[ai] = []
            reverseG[ai].append(bi)
            nodes.add(bi)
            if ai in startNodes:
                startNodes.remove(ai)
            nonstartNodes.add(ai)
            if bi not in nonstartNodes:
                startNodes.add(bi)
        print(f"graph:{graph}")
        print(f"startNodes:{startNodes}")
        print(f"nonstartNodes:{nonstartNodes}")
        print(f"reverseG:{reverseG}")
        visited = set()
        for startNode in startNodes:
            if startNode in visited:
                continue
            stack = [startNode]
            while stack:
                node = stack.pop()
                visited.add(node)
                order.append(node)
                if node not in graph:
                    continue
                for neighbor in graph[node]:
                    checker = True
                    for nn in reverseG[neighbor]:
                        if nn not in visited:
                            checker = False
                    if checker:
                        stack.append(neighbor)
        for i in range(numCourses):
            if i in nonstartNodes and i not in visited:
                return []
            else:
                if i not in visited:
                    order.append(i)
        return order

        