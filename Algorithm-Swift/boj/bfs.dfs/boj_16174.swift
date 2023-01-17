//
//  boj_16174.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/17.
//

import Foundation

let N = Int(readLine()!)!
var arr = Array(repeating: Array(repeating: 0, count: N), count: N)
var visit = Array(repeating: Array(repeating: false, count: N), count: N)
var ans = "Hing"

for i in 0..<N {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    for j in 0..<input.count {
        arr[i][j] = input[j]
    }
}

func dfs(_ x: Int, _ y: Int) {
    let move = arr[x][y]
    visit[x][y] = true
    
    if move == -1 {
        ans = "HaruHaru"
        return
    }
    
    let nx = x + move
    let ny = y + move
    
    if nx >= 0 && nx < N {
        if !visit[nx][y] {
            dfs(nx, y)
        }
    }
    
    if ny >= 0 && ny < N {
        if !visit[x][ny] {
            dfs(x, ny)
        }
    } else {
        return
    }
}

dfs(0, 0)

print(ans)
