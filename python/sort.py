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

def bubble_sort(nums):
   for i in reversed(range(1, len(nums))):
      for j in range(0, i):
         if nums[j] > nums[j + 1]:
            swap(nums, j, j + 1)

def insertion_sort(nums):
   for i in range(1, len(nums)):
      for j in reversed(range(1, i+1)):
         if nums[j] < nums[j - 1]:
            swap(nums, j, j - 1)
         else:
            break

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
   insertion_sort(nums)

   print(nums)
   print(is_sorted(nums))
