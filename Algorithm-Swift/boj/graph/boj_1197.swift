//
//  boj_1197.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/06.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let V = input[0]
let E = input[1]

var graph: [[Int]] = []
var items: [Int] = Array(0...V)
var cnt = 0
var ans = 0

// Union - Find 알고리즘
func find(_ elem: Int) -> Int {
    if items[elem] != elem {
        items[elem] = find(items[elem])
    }
    return items[elem]
}

func union(_ first: Int, _ second: Int) {
    let firstParent = find(first)
    let secondParent = find(second)
    
    if firstParent < secondParent {
        items[secondParent] = firstParent
    } else {
        items[firstParent] = secondParent
    }
}

for _ in 0..<E {
    let info = readLine()!.split(separator: " ").map { Int($0)! }
    graph.append(info)
}

// 크루스칼 알고리즘
graph.sort { $0[2] < $1[2] }

for g in graph {
    if find(g[0]) != find(g[1]) {
        ans += g[2]
        union(g[0], g[1])
        cnt += 1
    }
    if cnt == V - 1 { break }
}

print(ans)
