import Foundation

func solution(_ scores:[[Int]]) -> Int {
    var arr: [[Int]] = []
    
    if scores.count == 1 {
        return 1
    }
    
    for i in scores.indices {
        let first = scores[i][0]
        let second = scores[i][1]
        let score = [i, first, second, first+second]
        arr.append(score)
    }
    
    arr.sort { $0[1] == $1[1] ? $0[2] < $1[2] : $0[1] > $1[1] }
    
    var max = arr[0][2]
    var ansArr: [[Int]] = [arr[0]]
    for i in 1..<arr.count {
        if arr[i][2] >= max {
            max = arr[i][2]
            ansArr.append(arr[i])
        } else {
            if arr[i][0] == 0 {
                return -1
            }
        }
    }
    
    ansArr.sort { $0[3] > $1[3] }
        
    if ansArr[0][0] == 0 {
        return 1
    }
    
    var ans = 1
    var person = 1
    for i in 1..<ansArr.count {
        if ansArr[i-1][3] == ansArr[i][3] { 
            person += 1
        } else {
            ans += person
            person = 1
        }
        
        if ansArr[i][0] == 0 {
            break
        }
    }
    
    return ans
}