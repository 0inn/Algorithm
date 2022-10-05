//
//  pg_17681.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  [1차] 비밀지도

import Foundation

// 나의 풀이 : 하드 코딩
func solution1(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer: [String] = []
    
    zip(arr1, arr2).map {
        var a = String($0, radix: 2)
        var b = String($1, radix: 2)
        if a.count < n {
            var cnt = n - a.count
            while cnt > 0 {
            a = "0" + a
            cnt -= 1
            }
        }
        if b.count < n {
            var cnt = n - b.count
            while cnt > 0 {
            b = "0" + b
            cnt -= 1
            }
        }
        var ans = ""
        zip(a, b).map { ($0 == "1" || $1 == "1") ? (ans += "#") : (ans += " ") }
        answer.append(ans)
    }
    
    return answer
}

// 다른 사람의 풀이
func solution2(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    return (0..<n).map { String(String(arr1[$0]|arr2[$0]|2<<(n - 1), radix: 2).map { $0 == "1" ? "#" : " " }[1...n]) }
}
