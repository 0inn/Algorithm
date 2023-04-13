//
//  boj_1941.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/12.
//

import Foundation

var arr: [[String]] = []
var visit: [Bool] = Array(repeating: false, count: 25)
var point: [[Bool]] = Array(repeating: Array(repeating: false, count: 5), count: 5)
var ans: Int = 0, total: Int = 0, s: Int = 0

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

for _ in 0..<5 {
    let row = readLine()!.map { String($0) }
    arr.append(row)
}

func isConnected(_ n: Int) {
    total += 1
    let (x, y) = (n/5, n%5)
    point[x][y] = true
    if arr[x][y] == "S" { s += 1 }
    
    for dir in 0..<4 {
        let nx = (n/5) + dx[dir]
        let ny = (n%5) + dy[dir]
        
        let nxtn = (5*nx)+ny
        if nx < 0 || ny < 0 || nx >= 5 || ny >= 5 { continue }
        if !visit[nxtn] || point[nx][ny] { continue }
        isConnected(nxtn)
    }
}

func dfs(_ n: Int, _ cnt: Int) {
    if cnt == 7 { // 7명 뽑았을 때
        total = 0
        s = 0
        point = Array(repeating: Array(repeating: false, count: 5), count: 5)
        isConnected(n)
        if total == 7 && s >= 4 { // 전부 이어져있고, S가 4명 이상이면 정답
            ans += 1
        }
        return
    }
    
    for i in n..<25 { // 25명 중 7명 뽑기
        if visit[i] { continue }
        visit[i] = true
        dfs(i, cnt + 1)
        visit[i] = false
    }
}

dfs(0, 0)

print(ans)
