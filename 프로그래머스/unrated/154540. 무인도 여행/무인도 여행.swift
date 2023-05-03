import Foundation

func solution(_ maps:[String]) -> [Int] {
    var maps = maps.map { Array($0).map { String($0) } }
    let N = maps.count
    let M = maps[0].count
    var visited = [[Bool]](repeating: Array(repeating: false, count: M), count: N)
    var q: [(Int, Int)] = []
    var dq: [(Int, Int)] = []
    let dx = [0, 0, -1, 1]
    let dy = [-1, 1, 0, 0]
    var days: Int = 0
    var ans: [Int] = []
    
    func dequeue() ->(Int, Int) {
        if dq.isEmpty {
            dq = q.reversed()
            q.removeAll()
        }
        return dq.popLast()!
    }

    func bfs(_ x: Int, _ y: Int) {
        q.append((x, y))
        visited[x][y] = true

        while !(q.isEmpty && dq.isEmpty) {
            var (curx, cury) = dequeue()
            
            for dir in 0..<4 {
                let nx = curx + dx[dir]
                let ny = cury + dy[dir]

                if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
                if visited[nx][ny] || maps[nx][ny] == "X" { continue }

                days += Int(maps[nx][ny])!
                
                visited[nx][ny] = true
                q.append((nx, ny))
            }
        }
    }

    for i in 0..<N {
        for j in 0..<M {
            if visited[i][j] || maps[i][j] == "X" { continue }
            days = Int(maps[i][j])!
            bfs(i, j)
            ans.append(days)
        }
    }

    return ans.isEmpty ? [-1] : ans.sorted()
}