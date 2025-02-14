class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for word in strs:
            sorted_word = ''.join(sorted(word))
            if sorted_word not in hashmap:
                hashmap[sorted_word] = [word]
            else:
                hashmap[sorted_word].append(word)
        words = []
        for sorted_word in hashmap:
            words.append(hashmap[sorted_word])
        return words
