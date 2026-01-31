class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var buy = prices[0]
        var ans = 0
        for i in 1..<prices.count {
            buy = min(prices[i-1], buy)
            ans = max(ans, prices[i]-buy)
        }
        return ans
    }
}