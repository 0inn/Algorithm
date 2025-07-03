class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        var jump = Array(repeating: 0, count: nums.count)

        if nums.count <= 1 {
            return true
        }

        for (index, num) in nums.enumerated() {
            if (index != 0 && jump[index] != 1) || num == 0 {
                continue
            }
            for j in 1...num {
                let nxtIndex = index+j
                if nxtIndex == nums.count-1 {
                    return true
                }
                if (nxtIndex >= nums.count-1) {
                    break;
                }
                jump[nxtIndex] = 1;
            }
        }

        return false
    }
}