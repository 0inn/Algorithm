//
//  boj_2110.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/11.
//
//  공유기 설치

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let C = input[1]
var arr = [Int]()

for _ in 0..<N {
    let num = Int(readLine()!)!
    arr.append(num)
}

var start = 0
var end = 1000000000
var ans = 0

arr.sort { $0 < $1 }

// check(mid) -> Bool
// : 결정 문제의 답이 이분적인가 ?
func check(_ mid : Int) -> Bool {
    var i = 0
    var idx = 1
    var cnt = 1
    
    while i + idx < arr.count {
        if abs(arr[i] - arr[i+idx]) < mid {
            idx += 1
        } else {
            i += idx
            idx = 1
            cnt += 1
        }
    }
    
    if cnt >= C {
        return true
    } else {
        return false
    }
}

// start + 1 == end 가 되는 시점은 전부 탐색한 상황
while start + 1 < end {
    let mid = (start + end) / 2
    
    if check(mid) {
        start = mid
    } else {
        end = mid
    }
}

// [T ~ F] 상황
print(start)
