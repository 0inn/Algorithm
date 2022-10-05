//
//  pg_12969.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  직사각형 별찍기

import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
let (a, b) = (n[0], n[1])

for _ in 0..<b {
    print(String(Array(repeating: "*", count: a)))
}
