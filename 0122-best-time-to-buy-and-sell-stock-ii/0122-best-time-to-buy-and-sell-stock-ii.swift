class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var minP = prices[0]
        var maxP = 0

        for price in prices {
            minP = min(minP, price)
            if maxP < maxP + (price-minP) {
                maxP += (price-minP)
                minP = price
            }
        }

        return maxP
    }
}