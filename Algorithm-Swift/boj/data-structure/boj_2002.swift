//
//  boj_2002.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/31.
//
//  추월

import Foundation

let N = Int(readLine()!)!

var cars = [String: Int]()
var result = [Int]()
var ans = 0

for i in 0..<N {
    let car = String(readLine()!)
    cars[car, default: 0] = i
}

for _ in 0..<N {
    let outCar = String(readLine()!)
    result.append(cars[outCar]!)
}

for i in 0..<N {
    for j in (i + 1)..<N {
        if result[i] > result[j] {
            ans += 1
            break
        }
    }
}

print(ans)
