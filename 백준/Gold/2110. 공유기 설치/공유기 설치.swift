//
//  boj_2110.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/12.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let (N, C) = (input[0], input[1])
var houses: [Int] = []
var ans: Int = 1

for _ in 0..<N {
    let house = Int(readLine()!)!
    houses.append(house)
}

houses.sort()

var low = 0
var high = houses.last! + 1

func check(_ mid: Int) -> Bool {
    var cnt = 1
    var diff = 0
    
    for i in 1..<houses.count {
        diff += houses[i] - houses[i-1]
        if diff >= mid { // 공유기 설치
            diff = 0
            cnt += 1
        }
    }
    
    return cnt >= C
}

while low + 1 < high {
    let mid = (low + high) / 2
    
    if check(mid) {
        low = mid
    } else {
        high = mid
    }
}

print(low)
