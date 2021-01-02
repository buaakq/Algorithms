#!/usr/bin/python3.6

class TreeNode:
   def __init__(self, val):
      self.val = val
      self.left = None
      self.right = None

   def print(self):
      print("<%d>" % self.val, end='')


class BinaryTree:
   def __init__(self):
      self.root = None


   def buildTree(self, preOrder, inOrder):
      def buildTreeCore(preOrder, inOrder, p1, p2, i1, i2):
         sz = p2 - p1 + 1
         if sz == 0:
            return None
         rootVal = preOrder[p1]
         rootNode = TreeNode(rootVal)

         for i in range(i1, i2+1):
            if inOrder[i] == rootVal:
               break

         leftSz = i - i1
         rootNode.left = buildTreeCore(preOrder, inOrder, p1 + 1, p1 + leftSz,
                                       i1, i1 + leftSz - 1)

         rootNode.right = buildTreeCore(preOrder, inOrder, p1 + leftSz + 1, p2,
                                        i1 + leftSz + 1, i2)
         return rootNode


      # sz = len(preOrder)
      self.root = buildTreeCore(preOrder, inOrder, 0, len(preOrder)-1, 0, len(inOrder)-1)

   def print(self):
      pass

   def preTraverse(self):
      def preTraverse_helper(node):
         if node == None:
            return
         node.print()
         preTraverse_helper(node.left)
         preTraverse_helper(node.right)

      print("pre order: ")
      preTraverse_helper(self.root)
      print("")

   def inTraverse(self):
      def inTraverse_helper(node):
         if node == None:
            return
         inTraverse_helper(node.left)
         node.print()
         inTraverse_helper(node.right)

      print("in order: ")
      inTraverse_helper(self.root)
      print("")

   def posTraverse(self):
      def posTraverse_helper(node):
         if node == None:
            return
         posTraverse_helper(node.left)
         posTraverse_helper(node.right)
         node.print()

      print("pos order: ")
      posTraverse_helper(self.root)
      print("")

if __name__ == "__main__":
   preorder = [3,9,20,15,7]
   inorder = [9,3,15,20,7]

   tree = BinaryTree()
   tree.buildTree(preorder, inorder)

   tree.preTraverse()
   tree.inTraverse()
   tree.posTraverse()
