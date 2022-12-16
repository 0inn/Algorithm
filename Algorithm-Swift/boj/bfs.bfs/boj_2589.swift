//
//  boj_2589.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/16.
//
//  보물섬

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]

var tMap = Array(repeating: Array(repeating: "", count: M), count: N)
var dist = Array(repeating: Array(repeating: -1, count: M), count: N)

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

var ans = 0

for i in 0..<N {
    let arr = readLine()!.map { String($0) }
    tMap[i] = arr
}

func bfs(_ x: Int, _ y: Int) {
    var q = [(Int, Int)]()
    q.append((x, y))
    dist[x][y] = 0
    
    while !q.isEmpty {
        let cur = q.removeFirst()
        
        for dir in 0..<4 {
            let nx = cur.0 + dx[dir]
            let ny = cur.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
            if dist[nx][ny] != -1 || tMap[nx][ny] == "W" { continue }
            
            dist[nx][ny] = dist[cur.0][cur.1] + 1
            q.append((nx, ny))
        }
    }
}

for i in 0..<N {
    for j in 0..<M {
        if tMap[i][j] == "W" { continue }
        
        dist = Array(repeating: Array(repeating: -1, count: M), count: N)
        
        bfs(i, j)
        
        ans = max(ans, dist.map { $0.max()! }.max()!)
    }
}

print(ans)
