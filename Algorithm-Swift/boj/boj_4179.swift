//
//  boj_4179.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/07.
//
//  불!

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let R = input[0]
let C = input[1]

var miro: [[Character]] = []
var fireDist = Array(repeating: Array(repeating: -1, count: C), count: R)
var dist = Array(repeating: Array(repeating: -1, count: C), count: R)

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

var roads: [(Int, Int)] = []
var fires: [(Int, Int)] = []

for r in 0..<R {
    let column = Array(String(readLine()!))
    for c in 0..<C {
        if column[c] == "J" {
            roads.append((r, c))
            dist[r][c] = 0
        } else if column[c] == "F" {
            fires.append((r, c))
            fireDist[r][c] = 0
        }
    }
    miro.append(column)
}

while !fires.isEmpty {
    let cur = fires.removeFirst()
    let x = cur.0
    let y = cur.1
    
    for dir in 0..<4 {
        let nx = x + dx[dir]
        let ny = y + dy[dir]
        
        if nx < 0 || ny < 0 || nx >= R || ny >= C { continue }
        if miro[nx][ny] == "#" || fireDist[nx][ny] >= 0 { continue }
        
        fireDist[nx][ny] = fireDist[x][y] + 1
        fires.append((nx, ny))
    }
}

while !roads.isEmpty {
    let cur = roads.removeFirst()
    let x = cur.0
    let y = cur.1
    
    for dir in 0..<4 {
        let nx = x + dx[dir]
        let ny = y + dy[dir]
        
        if nx < 0 || ny < 0 || nx >= R || ny >= C { // 범위 벗어나면 탈출 성공
            print(dist[x][y] + 1)
            exit(0)
        }
        if miro[nx][ny] == "#" || dist[nx][ny] >= 0 { continue }
        if fireDist[nx][ny] <= dist[x][y] + 1 && fireDist[nx][ny] != -1 { continue } // 불 확산된 경우 제외
        
        dist[nx][ny] = dist[x][y] + 1
        roads.append((nx, ny))
    }
}

print("IMPOSSIBLE")

