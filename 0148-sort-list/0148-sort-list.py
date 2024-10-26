# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def sortNodes(leftHead: Optional[ListNode], rightHead: Optional[ListNode]) -> Optional[ListNode]:
            l, r = leftHead, rightHead
            newHead = ListNode()
            startHead = newHead
            while l != None or r != None:
                if r == None:
                    newHead.next = l
                    break
                elif l == None:
                    newHead.next = r
                    break
                elif r.val < l.val:
                    newHead.next = r
                    r = r.next
                else:
                    newHead.next = l
                    l = l.next
                newHead = newHead.next
            return startHead.next
        def recursion(head) -> Optional[ListNode]:
            #print(f"head{head}")
            count = 0
            rightNode = head
            while rightNode!=None:
                count += 1
                rightNode = rightNode.next
            if count < 2:
                return head
            mid = count // 2
            rightNode = head
            for i in range(mid-1):
                rightNode = rightNode.next
            nodeCopy = rightNode
            rightNode = rightNode.next
            nodeCopy.next = None
            leftNode = head
            #print(f"leftNode:{leftNode} rightNode:{rightNode}")
            leftNode = recursion(leftNode)
            rightNode = recursion(rightNode)
            sortedNode = sortNodes(leftNode, rightNode)
            #print(f"sortedNode:{sortedNode}")
            return sortedNode
        return recursion(head)
            