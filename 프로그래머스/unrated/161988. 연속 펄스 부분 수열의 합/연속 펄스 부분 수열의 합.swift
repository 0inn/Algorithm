import Foundation

func solution(_ sequence:[Int]) -> Int64 {
    var ans: Int64 = -100001
    let len = sequence.count
    
    let arrP = sequence.enumerated().map { $0.0 % 2 == 0 ? $0.1 : -$0.1 }.map { Int64($0) }
    let arrM = sequence.enumerated().map { $0.0 % 2 == 0 ? -$0.1 : $0.1 }.map { Int64($0) }
    var dpP: [Int64] = Array(repeating: 0, count: len)
    var dpM: [Int64] = Array(repeating: 0, count: len)
    
    dpP[0] = arrP[0]
    dpM[0] = arrM[0]
    ans = max(dpP[0], dpM[0])
    
    for i in 1..<len {
        dpP[i] = max(arrP[i], dpP[i-1] + arrP[i])
        dpM[i] = max(arrM[i], dpM[i-1] + arrM[i])
        ans = max(ans, dpP[i])
        ans = max(ans, dpM[i])
    }
    
    return ans
}