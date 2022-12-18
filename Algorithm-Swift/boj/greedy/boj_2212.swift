//
//  boj_2212.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/18.
//
//  센서

import Foundation

let N = Int(readLine()!)!
let K = Int(readLine()!)!
var input = readLine()!.split(separator: " ").map { Int($0)! }

var arr = Array(Set(input))
arr.sort { $0 < $1 }
let len = arr.count
var dist = [Int]()

for i in 1..<len {
    let diff = arr[i] - arr[i-1]
    dist.append(diff)
}

dist.sort { $0 > $1 }

for _ in 0..<(K-1) {
    //  런타임 에러 안나게 배열 접근 범위 제한
    if dist.isEmpty { break }
    dist.removeFirst()
}

print(dist.reduce(0, +))

/*
 런타임 에러 조건
 - 배열에 할당된 크기를 넘어서 접근했을 때 ✓
 - 전역 배열의 크기가 메모리 제한을 초과할 때
 - 지역 배열의 크기가 스택 크기 제한을 넘어갈 때
 - 0으로 나눌 떄
 - 라이브러리에서 예외를 발생시켰을 때
 - 재귀 호출이 너무 깊어질 때
 - 이미 해제된 메모리를 또 참조할 때
 */
