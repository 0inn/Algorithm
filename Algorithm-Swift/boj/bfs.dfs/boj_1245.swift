//
//  boj_1245.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/15.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]

var mountain = Array(repeating: Array(repeating: 0, count: M), count: N)
var visit = Array(repeating: Array(repeating: false, count: M), count: N)

let dx = [0, 0, -1, 1, -1, 1, -1, 1]
let dy = [-1, 1, 0, 0, -1, 1, 1, -1]

var isPeak = true
var ans = 0

for i in 0..<N {
    let arr = readLine()!.split(separator: " ").map { Int($0)! }
    mountain[i] = arr
}

func dfs(_ x: Int, _ y: Int) {
    let curHeight = mountain[x][y]

    for dir in 0..<8 {
        let nx = x + dx[dir]
        let ny = y + dy[dir]

        if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
        
        //  산봉우리 조건 확인 여기서 !!
        if mountain[nx][ny] > curHeight {
            isPeak = false
        }
        
        if visit[nx][ny] { continue }
        
        if mountain[nx][ny] == curHeight {
            visit[nx][ny] = true
            dfs(nx, ny)
        }
    }
}

for i in 0..<N {
    for j in 0..<M {
        if visit[i][j] { continue }
        
        isPeak = true
        dfs(i, j)
        if isPeak { ans += 1 }
    }
}

print(ans)
