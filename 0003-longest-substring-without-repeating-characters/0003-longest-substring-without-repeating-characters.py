class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letters = {}
        longest = 0
        l = 0  # Initialize left pointer
        
        for r in range(len(s)):
            if s[r] in letters:
                l = max(l, letters[s[r]] + 1)  # Move left pointer to avoid duplicate
            
            letters[s[r]] = r  # Update the index of the character
            longest = max(longest, r - l + 1)  # Calculate the max length
        
        return longest
