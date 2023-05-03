//
//  boj_2252.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/05/03.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let (N, M) = (input[0], input[1])
var line: [[Int]] = Array(repeating: [], count: N+1)
var inDegree: [Int] = Array(repeating: 0, count: N+1)
var q: [Int] = []
var ans: [Int] = []

for _ in 0..<M {
    let heights = readLine()!.split(separator: " ").map { Int($0)! }
    line[heights[0]].append(heights[1])
    inDegree[heights[1]] += 1
}

for i in 1...N {
    if inDegree[i] == 0 {
        q.append(i)
    }
}

while !q.isEmpty {
    let cur = q.removeFirst()
    ans.append(cur)
    
    for nxt in line[cur] {
        inDegree[nxt] -= 1
        if inDegree[nxt] == 0 {
            q.append(nxt)
        }
    }
}

ans.forEach {
    print($0, terminator: " ")
}
