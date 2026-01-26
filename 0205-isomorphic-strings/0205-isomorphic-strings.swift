class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        // dict [char: char] - replace char
        var dict = [Character: Character]()
        
        let sa = Array(s)
        let ta = Array(t)
        
        for i in 0..<sa.count {
            if let val = dict[sa[i]] {
                if (val != ta[i]) {
                    return false
                }
            } else {
                if (dict.values.contains(ta[i])) {
                    return false
                }
                dict[sa[i]] = ta[i]
            }
        }
        return true
    }
}