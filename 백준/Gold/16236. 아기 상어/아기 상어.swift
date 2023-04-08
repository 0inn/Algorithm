//
//  boj_16236.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/08.
//

import Foundation

let N = Int(readLine()!)!

struct Shark {
    var x: Int
    var y: Int
    var cnt: Int
}

var arr: [[Int]] = []
var dist: [[Int]] = []
var shark: Shark = Shark(x: 0, y: 0, cnt: 0)
var x: Int = 0, y: Int = 0
var nx: Int = 0, ny: Int = 0, nd: Int = 0
var nxt: [(Int, Int, Int)] = []
var sharkCnt: Int = 2
var ans: Int = 0

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

var q: [(Int, Int)] = []
var dq: [(Int, Int)] = []
var minDist: Int = Int(1e9)

for i in 0..<N {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    for j in row.indices {
        if row[j] == 9 {
            shark = Shark(x: i, y: j, cnt: 2)
        }
    }
    arr.append(row)
    dist.append(Array(repeating: -1, count: N))
}

arr[shark.x][shark.y] = 0

func dequeue() -> (Int, Int) {
    if dq.isEmpty {
        dq = q.reversed()
        q.removeAll()
    }
    
    let cur = dq.popLast()!
    return cur
}

// MARK: - 다음 위치까지 최단 거리 구하기

func bfs() {
    dist = Array(repeating: Array(repeating: -1, count: N), count: N)
    dist[shark.x][shark.y] = 0
    q.append((shark.x, shark.y))
    
    while !q.isEmpty || !dq.isEmpty {
        let cur = dequeue()
        
        for dir in 0..<4 {
            let nx = cur.0 + dx[dir]
            let ny = cur.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            if dist[nx][ny] != -1 || arr[nx][ny] > sharkCnt { continue }
            if (arr[nx][ny] < sharkCnt && arr[nx][ny] > 0 && (x != nx && y != ny)) { continue }
            if (x, y) == (nx, ny) {
                if dist[cur.0][cur.1] + 1 < minDist {
                    minDist = dist[cur.0][cur.1] + 1
                    nxt.append((nx, ny, minDist))
                }
                break
            }
            
            dist[nx][ny] = dist[cur.0][cur.1] + 1
            q.append((nx, ny))
        }
    }
}

while true {
    nxt = []
    minDist = Int(1e9)
    
    //print("현재 상어: \(shark) 상어 크기: \(sharkCnt)")
    
    for i in 0..<N {
        for j in 0..<N {
            if arr[i][j] == 0 { continue }
            if arr[i][j] < sharkCnt {
                (x, y) = (i, j)
                bfs()
            }
        }
    }
    
    if nxt.isEmpty { // 다음 위치로 갈 수 없다면 종료
        //print("return at \((x, y))")
        break
    }
    
    nxt.sort { // 가장 위쪽 물고기 -> 왼쪽 물고기 순으로 정렬
        if $0.2 == $1.2 {
            if $0.0 == $1.0 {
                return $0.1 < $1.1
            } else {
                return $0.0 < $1.0
            }
        } else {
            return $0.2 < $1.2
        }
    }
    
    (nx, ny, nd) = nxt.first!
    arr[nx][ny] = 0
    ans += nd
    
    //print("최단거리: \(nd)")
    
    shark.x = nx
    shark.y = ny
    shark.cnt -= 1
    if shark.cnt == 0 {
        sharkCnt += 1
        shark = Shark(x: nx, y: ny, cnt: sharkCnt)
    }
}

print(ans)
