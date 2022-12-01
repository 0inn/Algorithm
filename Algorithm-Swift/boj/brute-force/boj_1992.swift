//
//  boj_1992.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/30.
//
//  쿼드트리

import Foundation

let N = Int(readLine()!)!
var arr: [[String]] = []
var ans: String = ""

for _ in 0..<N {
    let input = readLine()!.map { String($0) }
    arr.append(input)
}

func sol(_ n: Int, _ x: Int, _ y: Int) {
    var flag = true
    let num = arr[x][y]
    
    for i in x..<(x + n) {
        for j in y..<(y + n) {
            if num != arr[i][j] {
                flag = false
                break
            }
        }
    }
    
    if flag {
        ans += "\(num)"
    } else {
        ans += "("
        sol(n / 2, x, y)
        sol(n / 2, x, y + n / 2)
        sol(n / 2, x + n / 2, y)
        sol(n / 2, x + n / 2, y + n / 2)
        ans += ")"
    }
}

sol(N, 0, 0)

print(ans)
