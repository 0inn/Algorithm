//
//  boj_1774.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/13.
//
//  수 묶기

import Foundation

let N = Int(readLine()!)!
var underZero = [Int]()
var upperZero = [Int]()
var ans = 0

for _ in 0..<N {
    let input = Int(readLine()!)!
    
    if input <= 0 {
        underZero.append(input)
    } else {
        upperZero.append(input)
    }
}

underZero.sort { $0 < $1 }
upperZero.sort { $0 > $1 }

func solution(_ arr: [Int]) -> Int {
    var i = 0
    var result = 0

    while i < arr.count - 1 {
        if arr[i] == 1 || arr[i + 1] == 1{
            result += (arr[i] + arr[i + 1])
            i += 2
            continue
        }
        result += (arr[i] * arr[i + 1])
        i += 2
    }
    
    if arr.count % 2 != 0 {
        result += arr.last!
    }
    
    return result
}

ans = solution(underZero)
ans += solution(upperZero)

print(ans)
