import Foundation

func solution(_ n:Int) -> [Int] {
    var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
    var num = 1, x = -1, y = 0
    var ans: [Int] = []
    
    for i in 0..<n {
        for j in i..<n {
            if i % 3 == 0 {
                x += 1
            } else if i % 3 == 1 {
                y += 1
            } else {
                x -= 1
                y -= 1
            }
            
            arr[x][y] = num
            num += 1
        }
    }
    
    for i in 0..<n {
        for j in 0..<n {
            if arr[i][j] == 0 { break }
            ans.append(arr[i][j])
        }
    }
    
    return ans
}