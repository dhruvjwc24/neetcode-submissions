import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # create a map
        pam = {}
        for num in nums:
            if num not in pam: pam[num] = 1
            else: pam[num]+=1

        heap = []
        heapq.heapify(heap) # create a heap (min heap by default, so negate to get max heap)
        for pair in pam.items():
            heapq.heappush(heap, (pair[1], pair[0]))
            if (len(heap) > k):
                heapq.heappop(heap)
        
        return [heap[i][1] for i in range(k)]



        