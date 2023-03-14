//
//  boj_1062.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/14.
//
//  가르침

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
var K = input[1]

var words = Array(repeating: 0, count: 50)
var alphabet = 0
var ans = 0

for i in 0..<N {
    let word = readLine()!.map { String($0) }
    for alpha in word {
        words[i] |= 1 << (Int(Character(alpha).asciiValue! - Character("a").asciiValue!))
    }
}

func dfs(_ depth: Int, _ start: Int) {
    var cnt = 0
    
    if depth == K { // 배울 K개 글자
        for i in 0..<N {
            if words[i] & alphabet == words[i] { // 읽을 수 있는 단어인 경우
                cnt += 1    // 세기
            }
        }
        ans = max(ans, cnt) // 읽을 수 있는 단어 최댓값 구하기
    }
    
    for i in start...25 {
        if (alphabet & (1 << i)) == 0 { // 안 배운 알파벳이면
            alphabet |= (1 << i) // 추가
            dfs(depth + 1, i)
            alphabet &= ~(1 << i) // 제거
        }
    }
}

func sol() -> Int {
    if K < 5 {
        return 0
    }
    
    alphabet |= 1 << (Int(Character("a").asciiValue! - Character("a").asciiValue!))
    alphabet |= 1 << (Int(Character("n").asciiValue! - Character("a").asciiValue!))
    alphabet |= 1 << (Int(Character("t").asciiValue! - Character("a").asciiValue!))
    alphabet |= 1 << (Int(Character("i").asciiValue! - Character("a").asciiValue!))
    alphabet |= 1 << (Int(Character("c").asciiValue! - Character("a").asciiValue!))
    
    K -= 5
    
    dfs(0, 0)
    
    return ans
}

print(sol())
