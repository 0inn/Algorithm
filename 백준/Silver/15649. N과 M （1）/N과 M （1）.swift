//
//  boj_15649.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/13.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let (N, M) = (input[0], input[1])

var visit = Array(repeating: false, count: N+1)
var arr = Array(repeating: 0, count: M)

func sol(_ cnt: Int) {
    if cnt == M {
        for num in arr {
            print(num, terminator: " ")
        }
        print()
        return
    }
        
    for n in 1...N {
        if visit[n] { continue }
        arr[cnt] = n
        visit[n] = true
        sol(cnt+1)
        visit[n] = false
    }
}

sol(0)
