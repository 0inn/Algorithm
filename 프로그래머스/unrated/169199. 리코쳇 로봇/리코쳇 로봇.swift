import Foundation

func solution(_ board:[String]) -> Int {
    var board = board.map { $0.map { String($0) } }
    let row = board.count
    let col = board[0].count
    var dist = Array(repeating: Array(repeating: -1, count: col), count: row)
    var ans = -1
    
    let dx = [0, 0, -1, 1]
    let dy = [-1, 1, 0, 0]
    
    func bfs(x: Int, y: Int) {
        var q: [(Int, Int)] = []
        q.append((x, y))
        dist[x][y] = 0
        
        while !q.isEmpty {
            let cur = q.removeFirst()
            
            if board[cur.0][cur.1] == "G" { ans = dist[cur.0][cur.1]; break }
            
            for dir in 0..<4 {
                var nx = cur.0 + dx[dir]
                var ny = cur.1 + dy[dir] 
                
                if nx < 0 || ny < 0 || nx >= row || ny >= col { continue }
                if dist[nx][ny] != -1 && dist[nx][ny] != dist[cur.0][cur.1] + 1 { continue }
                if board[nx][ny] == "D" { continue }
                
                while true {
                    nx += dx[dir]
                    ny += dy[dir]
                
                    if nx < 0 || ny < 0 || nx >= row || ny >= col { 
                        q.append((nx-dx[dir], ny-dy[dir]))
                        dist[nx-dx[dir]][ny-dy[dir]] = dist[cur.0][cur.1] + 1
                        break 
                    }
                    if dist[nx][ny] != -1 && dist[nx][ny] != dist[cur.0][cur.1] + 1 { break }
                    if board[nx][ny] == "D" { 
                        q.append((nx-dx[dir], ny-dy[dir]))
                        dist[nx-dx[dir]][ny-dy[dir]] = dist[cur.0][cur.1] + 1
                        break 
                    }
                }
            }
        }
    }
    
    for i in 0..<row {
        for j in 0..<col {
            if board[i][j] == "R" { bfs(x: i, y: j); break }
        }
    }
    
    return ans
}