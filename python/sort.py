#!/usr/bin/python3.6


# Reference: https://blog.csdn.net/qq_30534935/article/details/82531311

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
# Not stable sort
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

# NlogN time complexity
# N space complexity
# Stable sort

def merge(nums, copy, lo, mid, hi):
   for i in range(lo, hi+1):
      copy[i] = nums[i]

   i = lo
   j = mid + 1

   for idx in range(lo, hi+1):
      if i > mid:
         nums[idx] = copy[j]
         j += 1
      elif j > hi:
         nums[idx] = copy[i]
         i += 1
      elif copy[i] > copy[j]:
         nums[idx] = copy[j]
         j += 1
      else:
         nums[idx] = copy[i]
         i += 1

def merge_sort_top_down(nums):
   def merge_top_down_helper(nums, copy, lo, hi):
      if lo >= hi:
         return
      mid = lo + (hi - lo) // 2
      merge_top_down_helper(nums, copy, lo, mid)
      merge_top_down_helper(nums, copy, mid + 1, hi)
      merge(nums, copy, lo, mid, hi)

   copy = nums[:]
   merge_top_down_helper(nums, copy, 0, len(nums)-1)

def merge_sort_bottom_up(nums):
   copy = nums[:]
   sz = 1
   while sz < len(nums):
      lo = 0
      while lo + sz < len(nums):
         merge(nums, copy, lo, lo + sz - 1, min(lo + sz + sz - 1, len(nums) - 1))
         lo = lo + sz + sz
      sz = sz * 2

# NlogN on average
# N^2 worst case (random shuffling can prevent)
# O(1) space
# not stable sort

def partition(nums, lo, hi):
   # TODO: randomly shuffle the data

   pivot = nums[lo]

   left = lo + 1
   right = hi

   while True:
      while nums[left] <= pivot and left <= right:
         left += 1

      while nums[right] >= pivot and right >= left:
         right -= 1

      if left <= right:
         swap(nums, left, right)
      else:
         break
   swap(nums, lo, right)
   return right

def quick_sort(nums):
   def quick_sort_helper(nums, lo, hi):
      if lo >= hi:
         return
      mid = partition(nums, lo, hi)
      quick_sort_helper(nums, lo, mid - 1)
      quick_sort_helper(nums, mid + 1, hi)

   quick_sort_helper(nums, 0, len(nums) - 1)




# assuming nums has a padding nums[0], real data is in nums[1] ~ nums[N]
# where N is number of read data, i.e., len(nums) - 1
# pros: fast, O(NlogN) time, O(1) space
# cons: cannot leverage cache (swap data[k] and data[k * 2], which are far
#       from each other
# Not stable sort
def heap_sort(nums):
   n = len(nums) - 1
   def sink(nums, k, N):
      while k * 2 <= N:
         j = k * 2
         if j < N and nums[j] < nums[j + 1]:
            j += 1
         if nums[k] > nums[j]:
            break
         swap(nums, k, j)
         k = j

   for i in reversed(range(1, n//2+1)):
      sink(nums, i, n)

   while n > 1:
      swap(nums, 1, n)
      n -= 1
      sink(nums, 1, n)

if __name__ == "__main__":
   nums = [4,1,3,4,5,11,1,2, 10,111, 3, 6]
   print(nums)
   print(is_sorted(nums))

   #selection_sort(nums)
   #bubble_sort(nums)
   #shell_sort(nums)
   #merge_sort_top_down(nums)
   #merge_sort_bottom_up(nums)
   quick_sort(nums)
   #nums = [0] + nums
   #heap_sort(nums)
   #nums = nums[1:]

   print(nums)
   print(is_sorted(nums))
