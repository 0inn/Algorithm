import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    let dx = [1, 0, 0, -1] // 하 좌 우 위
    let dy = [0, -1, 1, 0]
    var flag = false
    var ans = "z"
    
    func move(_ x: Int, _ y: Int, _ road: String) {
        let dist = abs(r - x) + abs(c - y) 
        if dist > k - road.count || (k - road.count) % 2 != dist % 2 { // 불가능한 경로라면 종료
            return
        }
        
        if flag {  // 정답 구한경우 종료
            return
        }
        
        if x == 0 || y == 0 || x > n || y > m { // 범위 벗어나면 종료
            return
        }
        
        if road.count == k { // k만큼 움직였다면 종료
            if (x, y) == (r, c) { // 정답 조건
                flag = true
                ans = road
            }
            return
        }
        
        move(x + dx[0], y + dy[0], road + "d")
        move(x + dx[1], y + dy[1], road + "l")
        move(x + dx[2], y + dy[2], road + "r")
        move(x + dx[3], y + dy[3], road + "u")
    }
    
    move(x, y, "")
    
    return ans == "z" ? "impossible" : ans
}