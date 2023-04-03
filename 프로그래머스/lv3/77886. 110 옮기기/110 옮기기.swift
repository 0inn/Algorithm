import Foundation

var cnt = 0

func remove(_ strs: inout [String]) -> [String] {
    var stack: [String] = []
    
    for i in strs.indices {
        if stack.count < 2 {
            stack.append(strs[i])
        } else {
            if strs[i] == "0" {
                let str = stack.popLast()!
                if str == "1" && stack.last! == "1" {
                    stack.popLast()
                    cnt += 1
                } else {
                    stack.append(str)
                    stack.append(strs[i])
                }
            } else {
                stack.append(strs[i])
            }
        }
    }
    
    return stack
}

func makeAns(_ strs: inout [String]) -> String {
    var start: String = ""
    var end: String = ""
    
    for i in stride(from: strs.count-1, through: 0, by: -1) {
        if strs[i] != "0" {
            end += strs[i]
        } else {
            for j in 0...i {
                start += strs[j]
            }
            break 
        }
    }
    
    for _ in 0..<cnt {
        start += "110"
    }
    
    return start + end
}

func solution(_ bits:[String]) -> [String] {
    var ans: [String] = []
    
    for bit in bits {
        cnt = 0
        var strs = Array(bit).map { String($0) }
        var removeStrs = remove(&strs)
        ans.append(makeAns(&removeStrs))
    }
    
    return ans
}