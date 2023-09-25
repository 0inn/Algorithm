import Foundation

var dp: [Int] = []
let MAX: Int = 1000001

func solution(_ x:Int, _ y:Int, _ n:Int) -> Int {
    (0...y).forEach() { _ in
        dp.append(MAX)
    }
    
    var idx = x
    dp[idx] = 0
    while(true) {
        if(dp[idx] == MAX) {
            idx += 1
            continue
        }
        if(idx + n > y && idx * 2 > y && idx * 3 > y)  {
            break
        }
        
        let nxtCnt = dp[idx] + 1
        if idx + n <= y {
            dp[idx + n] = min(dp[idx + n], nxtCnt)
        } 
        if idx * 2 <= y {
            dp[idx * 2] = min(dp[idx * 2], nxtCnt)
        }
        if idx * 3 <= y {
            dp[idx * 3] = min(dp[idx * 3], nxtCnt)
        }
        idx += 1
    }
    
    return dp[y] == MAX ? -1 : dp[y]
}