class Solution:
    def calculate(self, s: str) -> int:
        m = ["+", "-", "*", "/"]
        mul = ["*", "/"]
        num = ""
        ans = 0
        wasMul = False
        stack = []
        for c in s:
            if c == " ":
                continue
            if c not in m:
                num += c
            else:
                stack.append(int(num))
                num = ""
                if wasMul:
                    r = stack.pop()
                    op = stack.pop()
                    l = stack.pop()
                    wasMul = False
                    if op == "*":
                        stack.append(int(l*r))
                    else:
                        stack.append(int(l/r))
                if c in mul:
                    wasMul = True
                else:
                    wasMul = False
                stack.append(c)
        stack.append(int(num))
        num = ""
        if wasMul:
            r = stack.pop()
            op = stack.pop()
            l = stack.pop()
            wasMul = False
            if op == "*":
                stack.append(int(l*r))
            else:
                stack.append(int(l/r))
        print(f"stack:{stack}")
        q = deque()
        p = deque()
        stack.reverse()
        while len(stack) > 0:
            q.append(stack.pop())
        while len(q) > 0:
            p.append(q.popleft())
            if len(p) == 3:
                l = p.popleft()
                o = p.popleft()
                r = p.popleft()
                if o == "+":
                    p.append(l+r)
                else:
                    p.append(l-r)
        return p.popleft()
