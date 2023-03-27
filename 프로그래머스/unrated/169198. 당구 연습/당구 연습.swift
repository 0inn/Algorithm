import Foundation

func dist(_ x1: Int, _ y1: Int, _ x2: Int, _ y2: Int) -> Int {
    let dist = pow(Double(x2 - x1), 2) + pow(Double(y2 - y1), 2)
    return Int(dist)
}

func solution(_ m:Int, _ n:Int, _ startX:Int, _ startY:Int, _ balls:[[Int]]) -> [Int] {
    var ans: [Int] = []
    
    let x1 = startX
    let y1 = startY
    
    for ball in balls {
        var result = Int(1e9)
        let x2 = ball[0]
        let y2 = ball[1]
        
        if x1 != x2 || (x1 == x2 && y1 < y2) { // 공이 다른 공 치는 경우 제외
            result = min(result, dist(x1, -y1, x2, y2))  
        }
        if y1 != y2 || (y1 == y2 && x1 < x2) {
            result = min(result, dist(-x1, y1, x2, y2)) 
        }
        if x1 != x2 || (x1 == x2 && y1 > y2) {
            result = min(result, dist(x1, n+(n-y1), x2, y2))
        }
        if y1 != y2 || (y1 == y2 && x1 > x2) {
            result = min(result, dist(m+(m-x1), y1, x2, y2))
        }
        
        ans.append(result)
    }
    
    return ans
}