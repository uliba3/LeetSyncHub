class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def canTransform(wordi: str, wordj: str) -> bool:
            count = 0
            for i in range(len(wordi)):
                if wordi[i] != wordj[i]:
                    count += 1
            return count == 1
        q = deque()
        q.append([beginWord, 1])
        ans = 0
        visited = set()
        while q:
            word, step = q.popleft()
            if word == endWord:
                ans = step
                break
            for wordi in wordList:
                if wordi not in visited and canTransform(wordi, word):
                    q.append([wordi, step+1])
                    visited.add(wordi)
        return ans
