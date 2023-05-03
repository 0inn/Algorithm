//
//  boj_10800.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/28.
//

import Foundation

struct Ball {
    var color: Int
    var size: Int
    var idx: Int
}

let N = Int(readLine()!)!

var balls: [Ball] = []
var colors: [Int] = Array(repeating: 0, count: N+1)
var ans: [Int] = Array(repeating: 0, count: N)

for i in 0..<N {
    let info = readLine()!.split(separator: " ").map { Int($0)! }
    balls.append(Ball(color: info.first!-1, size: info.last!, idx: i))
}

balls.sort { $0.size < $1.size }
    
var idx = 0
var sum = 0
for i in 0..<balls.count {
    var cur = balls[i]
    
    /// 자신보다 작은 값들만
    while balls[idx].size < cur.size {
        sum += balls[idx].size
        colors[balls[idx].color] += balls[idx].size
        idx += 1
    }
    
    /// 같은 색인 경우 빼기
    ans[cur.idx] = sum - colors[cur.color]
}

for ans in ans {
    print(ans)
}
