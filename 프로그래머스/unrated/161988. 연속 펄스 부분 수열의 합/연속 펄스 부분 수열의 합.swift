import Foundation

func solution(_ sequence:[Int]) -> Int64 {
    var ans: Int64 = -100001
    var op = 1
    var arr: [(Int64, Int64)] = []
    var dp: [(Int64, Int64)] = Array(repeating: (0, 0), count: sequence.count)
    
    for num in sequence {
        arr.append((Int64(num * op), Int64(num * -op)))
        op *= -1
    }
    
    dp[0] = arr[0]
    ans = max(ans, dp[0].0)
    ans = max(ans, dp[0].1)
    for i in 1..<arr.count {
        dp[i].0 = dp[i-1].0 + arr[i].0
        dp[i].1 = dp[i-1].1 + arr[i].1
    }
    
    for i in 1..<arr.count {
        if dp[i-1].0 + arr[i].0 < arr[i].0 { 
            dp[i].0 = arr[i].0
        } else {
            dp[i].0 = dp[i-1].0 + arr[i].0
        }
        
        if dp[i-1].1 + arr[i].1 < arr[i].1 { 
            dp[i].1 = arr[i].1
        } else {
            dp[i].1 = dp[i-1].1 + arr[i].1
        }
        
        ans = max(ans, dp[i].0)
        ans = max(ans, dp[i].1)
    }
    
    return ans
}