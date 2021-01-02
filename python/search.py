#!/usr/bin/python3.6

def bi_search(nums, target):
   left = 0
   right = len(nums) - 1

   while left <= right:
      middle = (right - left) // 2
      if nums[middle] == target:
         return middle
      elif nums[middle] > target:
         left = middle + 1
      else:
         right = middle - 1

   return -1

if __name__ == "__main__":
   nums = [1,2,3,4,5,11,31,41,111]
   target = 5

   idx = bi_search(nums, target)
   print(idx)
