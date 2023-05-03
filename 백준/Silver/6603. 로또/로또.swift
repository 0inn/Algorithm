//
//  boj_6603.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/13.
//

import Foundation

var arr: [Int] = []
var k: Int = 0
var visit: [Bool] = []

func sol(_ idx: Int, _ ans: [Int]) {
    var ans = ans
    if ans.count == 6 {
        for num in ans {
            print(num, terminator: " ")
        }
        print()
        return
    }
    
    for i in idx...k {
        if visit[i] { continue }
        ans.append(arr[i])
        visit[i] = true
        sol(i, ans)
        ans.removeLast()
        visit[i] = false
    }
}

while true {
    arr = readLine()!.split(separator: " ").map { Int($0)! }
    k = arr[0]
    visit = Array(repeating: false, count: arr.count)
    
    if k == 0 { break } // 종료 조건
    
    sol(1, [])
    print()
}
