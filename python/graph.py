#!/usr/bin/python3.6

#https://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python

class Graph:
   def __init__(self, graph):
      self.graph = graph

   def dfs(self, start):
      print("dfs:")
      visited = set()
      stack = [start]
      while len(stack) > 0:
         nextNode = stack.pop()
         if nextNode not in visited:
            # visit this node
            print(nextNode)
            visited.add(nextNode)
            # add all child nodes which are not visited to the stack
            stack.extend(self.graph[nextNode] - visited)
      return visited

   def dfs_recursive(self, start, visited=None):
      if visited == None:
         print("dfs recursive:")
         visited = set()
      visited.add(start)
      print(start)
      for nextNode in self.graph[start]:
         if nextNode not in visited:
            self.dfs_recursive(nextNode, visited)
      return visited

   def bfs(self):
      print("bfs the graph:")
      pass

   def dfs_paths(self, start, goal):
      pass

   def bfs_paths(self, start, goal):
      pass

if __name__ == "__main__":
   graph_dict = {'A': set(['B', 'C']),         \
                 'B': set(['A', 'D', 'E']),    \
                 'C': set(['A', 'F']),         \
                 'D': set(['B']),              \
                 'E': set(['B', 'F']),         \
                 'F': set(['C', 'E'])}

   graph = Graph(graph_dict)
   #graph.dfs('A')
   graph.dfs_recursive('A')
   graph.bfs()
