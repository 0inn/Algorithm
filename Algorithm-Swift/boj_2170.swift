//
//  boj_2170.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/03.
//
//  선 긋기

import Foundation

let file = FileIO()
let N = file.readInt()
var lines = [(Int, Int)]()
var ans = 0
var start = 0
var end = 0

for _ in 0..<N {
    var lineFirst = file.readInt()
    var lineSecond = file.readInt()
    if lineFirst > lineSecond {
        swap(&lineFirst, &lineSecond)
    }
    lines.append((lineFirst, lineSecond))
}

lines.sort { $0.0 < $1.0 }

start = lines[0].0
end = lines[0].1

for i in 1..<lines.count {
    let (first, second) = lines[i]
    
    if first <= end {   // 시작점 바뀌지 않음
        if second <= end {  // 선분 포함됨
            continue
        } else {
            end = second
        }
    } else {
        ans += (end - start)
        start = first
        end = second
    }
}

ans += (end - start)
print(ans)
