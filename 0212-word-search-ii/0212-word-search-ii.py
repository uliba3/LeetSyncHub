class TreeNode:
    def __init__(self):
        self.children = {}
        self.numbers = 0
        self.end = False

class Tree:
    def __init__(self):
        self.root = TreeNode()
    
    def addWord(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TreeNode()
            cur = cur.children[c]
            cur.numbers += 1
        cur.end = True
    
    def removeWord(self, word):
        cur = self.root
        for c in word:
            cur = cur.children[c]
            cur.numbers -= 1

    def searchWord(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
            if cur.numbers <= 0:
                return False
        return cur.end and cur.numbers>0
    
    def isSubString(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
            if cur.numbers <= 0:
                return False
        return True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        wordsTree = Tree()
        for word in words:
            wordsTree.addWord(word)
        allWords = []
        allWordsSet = set()
        di = [-1,0,1,0]
        dj = [0,-1,0,1]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if not wordsTree.isSubString(board[i][j]):
                    continue
                q = deque()
                visited = set()
                visited.add((i, j))
                q.append([visited, i, j, board[i][j]])
                while q:
                    visited, xi, yj, word = q.popleft()
                    visited.add((xi, yj))
                    #print(f"visited:{visited} word:{word}")
                    if wordsTree.searchWord(word) and word not in allWordsSet:
                        allWords.append(word)
                        allWordsSet.add(word)
                        wordsTree.removeWord(word)
                        #print(f"allWords:{allWords}")
                    for k in range(4):
                        if di[k] + xi < 0 or di[k] + xi >= len(board) or dj[k] + yj < 0 or dj[k] + yj >= len(board[0]):
                            continue
                        if (di[k] + xi, dj[k] + yj) in visited:
                            continue
                        word += board[di[k] + xi][dj[k] + yj]
                        if wordsTree.isSubString(word):
                            q.append([visited.copy(), di[k] + xi, dj[k] + yj, word])
                        word = word[:len(word)-1]
        return allWords
