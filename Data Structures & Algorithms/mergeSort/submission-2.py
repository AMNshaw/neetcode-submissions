# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:

        return self.merge(pairs, 0, len(pairs) - 1)

    def merge(self, pairs: List[Pair], l: int, r: int) -> List[Pair]:

        if r <= l: #legnth of the index is equal or smaller than
            return pairs

        m = (l+r)//2

        self.merge(pairs, l, m)
        self.merge(pairs, m+1, r)
        self.combine(pairs, l, m, r)

        return pairs

    def combine(self, pairs: List[Pair], l: int, m: int, r: int):
        
        left = pairs[l:m+1]
        right = pairs[m+1:r+1]

        i = 0
        j = 0
        n = l
        while i < len(left) and j < len(right):
            if left[i].key <= right[j].key:
                pairs[n] = left[i]
                i += 1
            else:
                pairs[n] = right[j]
                j += 1
            n += 1
        
        while i < len(left):
            pairs[n] = left[i]
            i += 1
            n += 1

        while j < len(right):
            pairs[n] = right[j]
            j += 1
            n += 1
