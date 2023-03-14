//
//  boj_1263.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/14.
//
//  시간관리

import Foundation

let N = Int(readLine()!)!

var works = [(Int, Int)]()

for _ in 0..<N {
    let work = readLine()!.split(separator: " ").map { Int($0)! }
    works.append((work[0], work[1]))
}

works.sort {
    $0.1 == $1.1 ? $0.0 > $1.0 : $0.1 > $1.1
}

var time = Int(1e9)

for work in works {
    time = min(time, work.1)
    time -= work.0
}

if time < 0 {
    time = -1
}

print(time)
