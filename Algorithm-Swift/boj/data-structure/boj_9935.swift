//
//  boj_9935.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/15.
//

import Foundation

var strs = Array(String(readLine()!))
var bombs = Array(String(readLine()!))
let bombsCnt = bombs.count
var stack: [String] = []

for str in strs {
    stack.append(String(str))
    
    let len = stack.count
    var isBomb = true
    
    if len < bombsCnt { continue }
    
    for idx in 0..<bombsCnt {
        if String(bombs[idx]) != String(stack[len - (bombsCnt - idx)]) {
            isBomb = false
        }
    }
    
    if isBomb {
        for _ in 0..<bombsCnt {
            stack.removeLast()
        }
    }
}

if stack.isEmpty {
    print("FRULA")
} else {
    print(stack.joined())
}
