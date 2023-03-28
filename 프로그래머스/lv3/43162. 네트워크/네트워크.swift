import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var visit = Array(repeating: false, count: computers.count + 1)
    var ans = 0
    
    func dfs(_ n: Int) {
        visit[n] = true
        
        for nxt in computers[0].indices {
            if visit[nxt] { continue }
            if computers[n][nxt] == 0 || (n == nxt) { continue }
            dfs(nxt)
        }
    }
    
    for com in computers[0].indices {
        if visit[com] == true { continue }
        dfs(com)
        ans += 1
    }
    
    return ans
}