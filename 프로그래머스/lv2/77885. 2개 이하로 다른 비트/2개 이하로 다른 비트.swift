import Foundation

func solution(_ numbers:[Int64]) -> [Int64] {
    var ans: [Int64] = []
    
    for number in numbers {
        var num: Int64 = number
        var nxt: Int64 = 0
        var bin: [String] = String(num, radix: 2).map { String($0) }
        
        if num % 2 == 0 {
            nxt = num + 1
        } else {
            let idx = bin.reversed().firstIndex(of: "0") ?? bin.count
            nxt = num + Int64(pow(2.0, Double(idx) - 1))
        }
        ans.append(nxt)
    }
    
    return ans
}