//
//  boj_1106.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/02.
//
//  호텔

import Foundation

struct Info {
    var v: Int
    var w: Int
    
    init(_ v: Int, _ w: Int) {
        self.v = v
        self.w = w
    }
}

let input = readLine()!.split(separator: " ").map { Int($0)! }

let C = input[0]
let N = input[1]

let MAX = 100000
var infos = [Info]()
var dp = Array(repeating: 0, count: MAX + 1)

for _ in 0..<N {
    let info = readLine()!.split(separator: " ").map { Int($0)! }
    let v = info[0]
    let w = info[1]
    infos.append(Info(v, w))
}

for i in 0..<N {
    for j in infos[i].v...MAX {
        dp[j] = max(dp[j], dp[j - infos[i].v] + infos[i].w)
    }
}

for i in 1...MAX{
    if dp[i] >= C {
        print(i)
        break
    }
}
