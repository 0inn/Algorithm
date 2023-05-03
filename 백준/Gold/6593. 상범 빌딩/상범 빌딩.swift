//
//  boj_6593.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/08.
//

import Foundation

var L: Int = 0
var R: Int = 0
var C: Int = 0

struct Point {
    let z: Int
    let x: Int
    let y: Int
}

var start: Point = Point(z: 0, x: 0, y: 0)
var arr: [[[String]]] = []
var dist: [[[Int]]] = []
var isPossible: Bool = false
var time: Int = 0
var q: [Point] = []
var dq: [Point] = []

// 상 하 좌 우 위 아래
let dz = [0, 0, 0, 0, -1, 1]
let dx = [-1, 1, 0, 0, 0, 0]
let dy = [0, 0, -1, 1, 0, 0]

func dequeue() -> Point {
    if dq.isEmpty {
        dq = q.reversed()
        q.removeAll()
    }
    
    let cur = dq.popLast()!
    return cur
}

func solution() -> String {
    isPossible = false
    time = 0
    
    q.append(start)
    dist[start.z][start.x][start.y] = 0
    
    while !q.isEmpty || !dq.isEmpty {
        let cur = dequeue()
        
        for dir in 0..<6 {
            let nz = cur.z + dz[dir]
            let nx = cur.x + dx[dir]
            let ny = cur.y + dy[dir]
            
            if nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C { continue }
            if arr[nz][nx][ny] == "#" || dist[nz][nx][ny] != -1 { continue }
            if arr[nz][nx][ny] == "E" {
                isPossible = true
                time = dist[cur.z][cur.x][cur.y] + 1
                break
            }
            
            dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1
            q.append(Point(z: nz, x: nx, y: ny))
        }
    }
    
    return isPossible ? "Escaped in \(time) minute(s)." : "Trapped!"
}

while true {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    (L, R, C) = (input[0], input[1], input[2])
    arr = []
    dist = []
    
    if L == 0 && R == 0 && C == 0 {
        break
    }
    
    for l in 0..<L {
        arr.append([])
        dist.append([])
        for r in 0..<R {
            let row = readLine()!.map { String($0) }
            arr[l].append(row)
            dist[l].append(Array(repeating: -1, count: row.count))
            for c in 0..<C {
                if arr[l][r][c] == "S" {
                    start = Point(z: l, x: r, y: c)
                }
            }
        }
        _ = readLine()!
    }
    
    print(solution())
}
