import Foundation

var n: Int = 0
var num: Int = 0
var ans: Int = 9

func cal(_ x: Int, _ cnt: Int) {
    if cnt > 8 {
        return
    }
    if x == num {
        ans = min(ans, cnt)
        return
    }
    
    var N = 0
    for i in 0..<8 {
        let nxtCnt = cnt + 1 + i
        if ans < nxtCnt {
            break
        }
        if nxtCnt > 8 {
            break
        }
        N = (10 * N) + n
        cal(x + N, nxtCnt)
        cal(x / N, nxtCnt)
        cal(x * N, nxtCnt)
        cal(x - N, nxtCnt)
    }
}

func solution(_ N:Int, _ number:Int) -> Int {
    n = N
    num = number
    
    cal(0, 0)
    
    return ans > 8 ? -1 : ans
}