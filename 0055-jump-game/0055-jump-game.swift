class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        var maxJump = 0

        for (i, num) in nums.enumerated() {
            if i > maxJump {
                return false
            } 
            maxJump = max(maxJump, i+num)
            if maxJump >= nums.count - 1 {
                return true
            }
        }

        return false
    }
}