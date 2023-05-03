import Foundation

func solution(_ a:[Int], _ edges:[[Int]]) -> Int64 {
    var ans: Int = 0
    var graph = [[Int]](repeating: [], count: a.count)
    var visited = [Bool](repeating: false, count: a.count)
    
    if a.reduce(0, +) != 0 { return -1 } 
    
    func dfs(_ n: Int) -> Int {
        visited[n] = true
        var cur = a[n]
        
        for nxt in graph[n] {
            if visited[nxt] { continue }
            cur += dfs(nxt)
        }
        
        ans += abs(cur)
        return cur
    }
    
    for edge in edges {
        let u = edge[0]
        let v = edge[1]
        graph[u].append(v)
        graph[v].append(u)
    }
    
    dfs(0)
    
    return Int64(ans)
}