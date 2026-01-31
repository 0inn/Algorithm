class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var ans = 0
        for i in 1..<prices.count {
            ans += max(0, prices[i] - prices[i-1])
        }
        return ans
    }
}