class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        digits = "0123456789"
        for c in s:
            print(f"c:{c} stack:{stack}")
            if c == "]":
                insideS = ""
                while "[" not in insideS:
                    insideS = stack.pop() + insideS 
                num = ""
                print(f"insideS:{insideS}")
                while len(stack) > 0 and stack[len(stack)-1] in digits:
                    num = stack.pop() + num
                print(f"num:{num} insideS[1:]:{insideS[1:]}")
                newS = int(num) * insideS[1:]
                stack.append(newS)
            else:
                stack.append(c)
        return ''.join(stack)
        