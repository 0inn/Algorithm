//
//  boj_1863.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/08.
//
//  스카이라인 쉬운거

import Foundation

let n = Int(readLine()!)!
var skylines = [(Int, Int)]()
var stack = [Int]()
var ans = 0

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    skylines.append((input[0], input[1]))
}

var heights = skylines.sorted { $0.0 < $1.0 }.map { $0.1 }
stack.append(heights[0])

for idx in 1..<heights.count {
    let height = heights[idx]
    
    if !stack.isEmpty && height < stack.last! {
        while true {
            if stack.isEmpty || height >= stack.last! { break }
            stack.removeLast()
            ans += 1
        }
        if (!stack.isEmpty && stack.last! != height) || stack.isEmpty {
            stack.append(height)
        }
    } else {
        stack.append(height)
    }
}

print(ans + stack.filter { $0 != 0 }.count)
