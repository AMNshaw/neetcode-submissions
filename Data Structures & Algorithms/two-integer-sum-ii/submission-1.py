class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers)-1

        sum = numbers[i] + numbers[j]
        while sum != target:
            if sum > target:
                j -= 1
            elif sum < target:
                i += 1
            else:
                break
            sum = numbers[i] + numbers[j]

        return [i+1, j+1]