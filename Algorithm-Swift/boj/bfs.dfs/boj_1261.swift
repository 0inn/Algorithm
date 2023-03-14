//
//  boj_1261.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/14.
//
//  알고스팟

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]

var arr: [[Character]] = []
var dist =  Array(repeating: Array(repeating: Int(1e9), count: N), count: M)

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

for _ in 0..<M {
    let row = Array(String(readLine()!))
    arr.append(row)
}

func bfs() {
    var q = Queue<(Int, Int)>()
    q.enqueue((0, 0))
    dist[0][0] = 0
    
    while !q.isEmpty {
        let cur = q.dequeue()!
        let x = cur.0
        let y = cur.1
        
        for dir in 0..<4 {
            let nx = x + dx[dir]
            let ny = y + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= M || ny >= N { continue }
            
            let nxtDist = dist[x][y] + Int(String(arr[nx][ny]))!
            if dist[nx][ny] > nxtDist {
                dist[nx][ny] = nxtDist
                q.enqueue((nx, ny))
            }
        }
    }
}

bfs()

print(dist[M-1][N-1])
