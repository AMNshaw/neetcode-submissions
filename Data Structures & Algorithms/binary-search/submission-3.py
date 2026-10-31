class Solution:
    def search(self, nums: List[int], target: int) -> int:
        min_index = 0
        max_index = len(nums)-1
        mid_index = (min_index + max_index+1)//2

        while min_index <= max_index:
            mid_index = (min_index + max_index+1)//2

            if target > nums[mid_index]:
                min_index = mid_index+1
            elif target < nums[mid_index]:
                max_index = mid_index-1
            elif target == nums[mid_index]:
                return mid_index
            
            # print(f"min: {min_index}")
            # print(f"max: {max_index}")
            # print(f"mid: {mid_index}\n")

        return -1