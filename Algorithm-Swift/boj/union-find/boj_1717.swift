//
//  boj_1717.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int(String($0))! }

let N = input[0]
let M = input[1]

var items = Array(0...N)

for _ in 0..<M {
    let cmd = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    let a = cmd[0]
    let b = cmd[1]
    let c = cmd[2]
    
    if a == 0 {
        union(b, c)
    } else {
        if find(b) == find(c) {
            print("YES")
        } else {
            print("NO")
        }
    }
}

func find(_ element: Int) -> Int{
    if items[element] != element {
        items[element] = find(items[element])
    }
    return items[element]
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
