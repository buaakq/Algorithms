#!/usr/bin/python3.6

def is_sorted(nums):
   for i in range(len(nums) - 1):
      if nums[i] > nums[i+1]:
         return False
   return True

def swap(nums, i, j):
   if i == j:
      return
   # print("swapping nums[%d]=%d and nums[%d]=%d" % (i, nums[i], j, nums[j]))
   tmp = nums[i]
   nums[i] = nums[j]
   nums[j] = tmp

# N^2 compares, N exchanges (minimal data movement)
# Sensitive to input data:
# bad performance on sorted data (or data with all equal keys)
# Stable sort
def selection_sort(nums):
   if len(nums) <= 1:
      return
   for i in range(0, len(nums) - 1):
      m = nums[i]
      mIdx = i
      for j in range(i + 1, len(nums)):
         if nums[j] < m:
            print(j, m)
            m = nums[j]
            mIdx = j
      swap(nums, i, mIdx)

# N^2 compares and exchanges
# Linear time for sorted data / data with all equal keys
# Stable sort
def insertion_sort(nums):
   for i in range(1, len(nums)):
      for j in reversed(range(1, i+1)):
         if nums[j] < nums[j - 1]:
            swap(nums, j, j - 1)
         else:
            break

# N^2 compares and exchanges
# Sorted data: N^2 compares, 0 movements
# Stable sort
def bubble_sort(nums):
   for i in reversed(range(1, len(nums))):
      for j in range(0, i):
         if nums[j] > nums[j + 1]:
            swap(nums, j, j + 1)


# Time: Nlog(N)
# Not stable sort
def shell_sort(nums):
   k = 1
   while k < len(nums) / 3:
      k = k * 3 + 1

   while k >= 1:
     for i in range(k, len(nums)):
        for j in reversed(range(k, i+1)):
           if nums[j] < nums[j-k]:
              swap(nums, j, j-k)
           else:
              break
     k = k // 3

# TODO
def merge_sort(nums):
   pass

# TODO
def quick_sort(nums):
   pass


if __name__ == "__main__":
   nums = [4,1,3,4,5,11,1,2, 10,111, 3, 6]
   print(nums)
   print(is_sorted(nums))

   #selection_sort(nums)
   #bubble_sort(nums)
   shell_sort(nums)

   print(nums)
   print(is_sorted(nums))
