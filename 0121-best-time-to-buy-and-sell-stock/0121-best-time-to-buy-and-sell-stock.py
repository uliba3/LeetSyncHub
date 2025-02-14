class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        profit = 0
        for price in prices:
            if price < minPrice:
                minPrice = price
            else:
                profit = max(profit, price-minPrice)
        return profit