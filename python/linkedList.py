#!/usr/bin/python3.6

class ListNode:
   def __init__(self, val, next):
      self.val = val
      self.next = next

   def print(self):
      print("[%d]" % (self.val))

class LinkedList:
   author = "Qiao"
   def __init__(self, lst):
      self.head = None
      if lst == None:
         return
      else:
         prev = None
         for item in lst:
            node = ListNode(item, None)
            if self.head == None:
               self.head = node
            else:
               prev.next = node
            prev = node

   def print(self):
      node = self.head
      while node != None:
         print("[%d]->" % (node.val), end='')
         node = node.next
      print("")

   # https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
   # Jianzhi offer 03
   def reverse_print(self):
      def reverse_print_helper(node):
         if node == None:
            return
         reverse_print_helper(node.next)
         print("[%d]->" % (node.val), end='')

      node = self.head
      reverse_print_helper(node)
      print("")


if __name__ == "__main__":
   #nums = [1,2,3,4,5]
   nums = [2,1,3,4,5]
   lst = LinkedList(nums)
   lst.print()
   lst.reverse_print()
   print(lst.author)
   print(LinkedList.author)

   head = lst.head
   head.print()
