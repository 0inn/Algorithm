//
//  boj_2468.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/11.
//
//  안전 영역

import Foundation

let N = Int(readLine()!)!
var arr = [[Int]]()
var maxRain = 0

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]
var visit = Array(repeating: Array(repeating: false, count: N), count: N)
var ans = 1

for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    arr.append(input)
    maxRain = max(maxRain, input.max()!)
}

func bfs(_ x: Int, _ y: Int, _ rain: Int) {
    var q = [(Int, Int)]()
    q.append((x, y))
    visit[x][y] = true
    
    while !q.isEmpty {
        let cur = q.removeFirst()
        
        for dir in 0..<4 {
            let nx = cur.0 + dx[dir]
            let ny = cur.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            if visit[nx][ny] || arr[nx][ny] <= rain { continue }
            
            q.append((nx, ny))
            visit[nx][ny] = true
        }
    }
}

for rain in 1..<maxRain {
    visit = Array(repeating: Array(repeating: false, count: N), count: N)
    var cnt = 0
    
    for i in 0..<N {
        for j in 0..<N {
            if visit[i][j] || arr[i][j] <= rain { continue }
            bfs(i, j, rain)
            cnt += 1
        }
    }
    
    ans = max(ans, cnt)
}

print(ans)
