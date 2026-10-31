# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:

        return self.quickSortHelper(pairs, 0, len(pairs) - 1)        

    def quickSortHelper(self, arr: List[Pair], l, r):

        if r <= l:
            return arr

        k = self.partition(arr, l, r)

        self.quickSortHelper(arr, l, k-1)
        self.quickSortHelper(arr, k+1, r)

        return arr

    def partition(self, arr: List[Pair], l, r):
        pivot = arr[r]
        k = l

        for i in range(l, r):
            if arr[i].key < pivot.key:
                arr[k], arr[i] = arr[i], arr[k]
                k += 1
        
        arr[k], arr[r] = arr[r], arr[k]

        return k