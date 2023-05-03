//
//  boj_2146.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/08.
//

import Foundation

let N = Int(readLine()!)!

struct Island {
    let x: Int
    let y: Int
}

var island: [Island] = []
var arr: [[Int]] = []
var narr: [[Int]] = []
var dist: [[Int]] = []
var minDist: Int = Int(1e9)

var q: [(Int, Int)] = []
var dq: [(Int, Int)] = []

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

// MARK: - 섬 번호 붙이기

func dfs(_ x: Int, _ y: Int) {
    dist[x][y] = 0
    narr[x][y] = island.count
    
    for dir in 0..<4 {
        let nx = x + dx[dir]
        let ny = y + dy[dir]
        
        if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
        if dist[nx][ny] != -1 || arr[nx][ny] == 0 { continue }
        
        narr[nx][ny] = island.count
        dfs(nx, ny)
    }
}

for _ in 0..<N {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    arr.append(row)
    dist.append(Array(repeating: -1, count: row.count))
}

narr = arr

for i in 0..<N {
    for j in 0..<N {
        if dist[i][j] != -1 || arr[i][j] == 0 { continue }
        island.append(Island(x: i, y: j))
        dfs(i, j)
    }
}

// MARK: - 가장 짧은 다리 구하기

func dequeue() -> (Int, Int) {
    if dq.isEmpty {
        dq = q.reversed()
        q.removeAll()
    }
    
    let cur = dq.popLast()!
    return cur
}

func bfs(_ x: Int, _ y: Int, _ n: Int) {
    dist = Array(repeating: Array(repeating: -1, count: N), count: N)
    q.append((x, y))
    dist[x][y] = 0
    
    while !q.isEmpty || !dq.isEmpty {
        let cur = dequeue()
        let curDist =  dist[cur.0][cur.1]
        
        for dir in 0..<4 {
            let nx = cur.0 + dx[dir]
            let ny = cur.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            if dist[nx][ny] != -1 || narr[nx][ny] == n { continue }
            if narr[nx][ny] > 0 { // 다른 섬 도착
                if curDist < minDist {
                    minDist = curDist
                }
                break
            }
            
            dist[nx][ny] = curDist + 1
            q.append((nx, ny))
        }
    }
}

for i in 0..<N {
    for j in 0..<N {
        if narr[i][j] == 0 { continue }
        bfs(i, j, narr[i][j])
    }
}

print(minDist)
