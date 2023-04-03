//
//  bitMask.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/31.
//

import Foundation

func printLog(_ A: Int) {
    print("\(A)\n\(String(A, radix: 2))\n")
}

var A: Int = 920
let k = 5

printLog(A)

/*
 집합 연산
*/

A = (1<<10) - 1 // 10개의 원소 채우기
printLog(A)

A |= (1<<k)   // k번째 위치에 원소 추가
printLog(A)

A &= ~(1<<k)  // k번째 위치 원소 제거
printLog(A)

print((A & (1<<k) != 0) ? "포함 O\n" : "포함 X\n")   // k번째 원소 포함 여부 확인

A ^= (1<<k) // k번째 원소 토글
printLog(A)

/*
 두 집합 연산
*/

A = 44
let B = 50

print("A와 B의 교집합 \(String(A & B, radix: 2))")
print("A와 B의 합집합 \(String(A | B, radix: 2))")
print("A와 B의 차집합 \(String(A & ~B, radix: 2))\n")

printLog(A)

var subset = A

print("모든 부분집합 탐색")
while subset != 0 {
    print(String(subset, radix: 2))
    subset = A & (subset-1)
}
print()

A &= (A-1)  // 최소 원소 지우기
printLog(A)

A &= (~A+1) // 최소 원소 찾기
printLog(A)
