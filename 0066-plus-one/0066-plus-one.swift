class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        var ans: [Int] = digits
        for i in stride(from: ans.count-1, through: 0, by: -1) {
            if ans[i] < 9 {
                ans[i] += 1
                return ans
            }
            ans[i] = 0
        }
        return [1] + ans
    }
}