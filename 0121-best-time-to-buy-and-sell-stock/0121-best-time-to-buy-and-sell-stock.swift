class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var minP = prices[0]
        var maxP = -1

        for price in prices {
            minP = min(minP, price)
            maxP = max(maxP, price - minP)
        }

        return maxP
    }
}