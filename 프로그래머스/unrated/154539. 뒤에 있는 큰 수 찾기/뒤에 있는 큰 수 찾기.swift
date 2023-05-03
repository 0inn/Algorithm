import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var stack: [Int] = []
    var ans = Array(repeating: -1, count: numbers.count)
    
    for (idx, num) in numbers.enumerated() {
        while !stack.isEmpty && numbers[stack.last!] < num {
            ans[stack.popLast()!] = num
        }
        stack.append(idx)
    }
    
    return ans
}