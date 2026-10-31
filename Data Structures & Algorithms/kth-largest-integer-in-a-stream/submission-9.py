class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.minHeap = nums
        self.k = k
        self.heapify(self.minHeap)
        while len(self.minHeap) - 1 > self.k:
            self.heapPop(self.minHeap)

    def add(self, val: int) -> int:
        self.heapPush(self.minHeap, val)
        if len(self.minHeap) - 1 > self.k:
            self.heapPop(self.minHeap)
        return self.minHeap[1] if len(self.minHeap) > 1 else None
    
    def heapPush(self, heap: List[int], val: int):
        heap.append(val)

        ptr = len(heap) - 1

        while heap[ptr] < heap[ptr // 2] and ptr > 1:
            heap[ptr], heap[ptr // 2] = heap[ptr//2], heap[ptr]
            ptr = ptr//2

    def heapPop(self, heap: List[int]):
        if len(heap) == 1:
            return None
        if len(heap) == 2:
            return self.heap.pop()

        popVal = heap[1]

        heap[1] = heap.pop()

        i = 1

        while 2*i < len(heap):
            if (2*i + 1 < len(heap) and
            heap[2*i + 1] < heap[2*i] and
            heap[i] > heap[2*i + 1]):
                heap[2*i+1], heap[i] = heap[i], heap[2*i+1]
                i = 2*i + 1
            elif heap[i] > heap[2*i]:
                heap[2*i], heap[i] = heap[i], heap[2*i]
                i = 2*i
            else:
                break

        return popVal

    def heapify(self, arr: List[int]):
        if len(arr) < 1:
            arr.append(0)
            return 
        arr.append(arr[0])

        startPtr = (len(arr) - 1) //2

        while startPtr > 0: #Percolate down

            i = startPtr
            while 2*i < len(arr): # If curr node has left child
                if (2*i+1 < len(arr) and # If curr node has right child
                arr[2*i + 1] < arr[2*i] and # If right child < left child
                arr[i] > arr[2*i + 1]): # If curr node > right child
                    arr[i], arr[2*i + 1] = arr[2*i + 1], arr[i]
                    i = 2*i + 1 # set curr pointer to right child
                elif arr[i] > arr[2*i]: # Else if node > left child
                    arr[i], arr[2*i] = arr[2*i], arr[i]
                    i = 2*i
                else:
                    break
            startPtr -= 1 # Percolate down until root