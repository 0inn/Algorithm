import Foundation

var nums: [[Int]] = []
var ans: [Int] = [0, 0]

func check(_ x: Int, _ y: Int, _ cnt: Int) {
    var num = nums[x][y]
    var isSame = true
    
    for i in x..<x+cnt {
        for j in y..<y+cnt {
            if num != nums[i][j] {
                isSame = false
                break
            }
        }
    }
    
    if isSame {
        ans[num] += 1
    } else {
        let nxtCnt = cnt/2
        check(x, y, nxtCnt)
        check(x+nxtCnt, y, nxtCnt)
        check(x, y+nxtCnt, nxtCnt)
        check(x+nxtCnt, y+nxtCnt, nxtCnt)
    }
}

func solution(_ arr:[[Int]]) -> [Int] {
    nums = arr
    
    check(0, 0, nums.count)
    
    return ans
}