class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        maxProfit = 0

        l = 0

        for i in range(len(prices)):
            if prices[i] < prices[l]:
                l = i
            maxProfit = max(maxProfit, prices[i] - prices[l])

        return maxProfit
