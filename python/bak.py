def merge(nums, copy, left, mid, right):
      assert(mid <= right)
      assert(mid >= left)
      for i in range(left, right+1):
         copy[i] = nums[i]

      i = left
      j = mid + 1

      for k in range(left, right+1):
         if i > mid:
            nums[k] = copy[j]
            j += 1
         elif j > right:
            nums[k] = copy[i]
            i += 1
         elif copy[i] > copy[j]:
            nums[k] = copy[j]
            j += 1
         else:
            nums[k] = copy[i]
            i += 1

   def merge_sort_helper(nums, copy, low, high):
      if (low >= high):
         return
      mid = (high - low) // 2 + low
      merge_sort_helper(nums, copy, low, mid)
      merge_sort_helper(nums, copy, mid + 1, high)
      merge(nums, copy, low, mid, high)

   nums_copy = nums[:]
   merge_sort_helper(nums, nums_copy, 0, len(nums)-1)

def quick_sort(nums):
   def partition(nums, low, high):
      val = nums[low]

      i = low + 1
      j = high

      while True:
         while nums[i] <= val and i <= j:
            i += 1
         while nums[j] >= val and i <= j:
            j -= 1

         if i <= j:
            swap(nums, i, j)
         else:
            break
      swap(nums, low, j)
      return j

   def quick_sort_helper(nums, low, high):
      if (low >= high):
         return
      idx = partition(nums, low, high)
      quick_sort_helper(nums, low, idx-1)
      quick_sort_helper(nums, idx+1, high)

   quick_sort_helper(nums, 0, len(nums) - 1)


