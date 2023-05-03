//
//  boj_1182.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/13.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let (N, M) = (input[0], input[1])
var arr = readLine()!.split(separator: " ").map { Int($0)! }

var visit = Array(repeating: false, count: N)
var ans: Int = 0

func sol(_ idx: Int, _ sum: Int, _ isFirst: Bool) {
    if sum == M && !isFirst { // 종료 조건
        ans += 1
    }
    
    for i in idx..<N {
        if visit[i] { continue }
        visit[i] = true
        sol(i, sum + arr[i], false)
        visit[i] = false
    }
}

sol(0, 0, true)

print(ans)
