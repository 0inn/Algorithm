class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let word = Array(s.filter {$0.isLetter || $0.isNumber}.map { $0.lowercased()})
        let rs = Array(word.reversed())

        for i in 0..<word.count/2 {
            if (word[i] != rs[i]) {
                return false
            }
        }

        return true
    }
}