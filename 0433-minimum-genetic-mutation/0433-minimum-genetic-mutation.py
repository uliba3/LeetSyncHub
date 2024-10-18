class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        q = deque()
        q.append([startGene, 0])
        minStepNum = -1
        visited = set()
        while q:
            print(f"q:{q}")
            gene, stepNum = q.popleft()
            visited.add(gene)
            if gene == endGene:
                minStepNum = stepNum
                break
            for i in range(len(gene)):
                for letter in ["A", "C", "G", "T"]:
                    if gene[:i] + letter + gene[i+1:] in bank and gene[:i] + letter + gene[i+1:] not in visited:
                        q.append([gene[:i] + letter + gene[i+1:], stepNum+1])
                        visited.add(gene[:i] + letter + gene[i+1:])
        return minStepNum