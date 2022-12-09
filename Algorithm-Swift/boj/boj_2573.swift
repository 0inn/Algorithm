//
//  boj_2573.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/08.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]
var arr = Array(repeating: Array(repeating: 0, count: M), count: N)
var visit = Array(repeating: Array(repeating: false, count: M), count: N)
var iceCnt = 0
var ans = 0

let dx = [0, 0, -1, 1]
let dy = [1, -1, 0, 0]

for i in 0..<N {
    arr[i] = readLine()!.split(separator: " ").map { Int($0)! }
}

func melting() {
    var nxtArr = Array(repeating: Array(repeating: 0, count: M), count: N)
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] != 0 {
                var ocean = 0
                
                for dir in 0..<4 {
                    let nx = i + dx[dir]
                    let ny = j + dy[dir]
                    
                    if arr[nx][ny] != 0 { continue }
                    if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
                    
                    // 주변이 바다인 경우 -> 빙하 녹이기
                    ocean += 1
                }
                
                nxtArr[i][j] = ocean > arr[i][j] ? 0 : arr[i][j] - ocean
            }
        }
    }
    
    arr = nxtArr
}

func bfs(x: Int, y: Int) {
    var queue = [(Int, Int)]()
    queue.append((x, y))
    visit[x][y] = true
    
    while !queue.isEmpty {
        let cur = queue.removeFirst()
        let curx = cur.0
        let cury = cur.1
        
        for dir in 0..<4 {
            let nx = curx + dx[dir]
            let ny = cury + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
            if visit[nx][ny] || arr[nx][ny] == 0 { continue }
            
            queue.append((nx, ny))
            visit[nx][ny] = true
        }
    }
}

var allMelt = arr.map { $0.reduce(0, +) }.reduce(0, +)

while true {
    if allMelt == 0 {
        ans = 0
        break
    }
    
    melting()
    ans += 1
    visit = Array(repeating: Array(repeating: false, count: M), count: N)
    iceCnt = 0
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] != 0 && !visit[i][j] {
                bfs(x: i, y: j)
                iceCnt += 1
            }
        }
    }
    
    if iceCnt >= 2 {
        break
    }
    
    allMelt = arr.map { $0.reduce(0, +) }.reduce(0, +)
}

print(ans)
