class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letters = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }
        ans = []
        def recursion(letterCombination, digits):
            print(f"letterCombination:{letterCombination} digits:{digits}")
            if digits == "":
                if letterCombination != "":
                    ans.append(letterCombination)
            else:
                digit = digits[0]
                digits = digits[1:]
                for letter in letters[digit]:
                    recursion(letterCombination+letter, digits)
        recursion("", digits)
        return ans
        