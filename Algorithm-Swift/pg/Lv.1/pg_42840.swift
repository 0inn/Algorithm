//
//  pg_42840.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/07.
//
//  모의고사

import Foundation

func solution(_ answers:[Int]) -> [Int] {
    let f = [1, 2, 3, 4, 5]
    let s = [2, 1, 2, 3, 2, 4, 2, 5]
    let t = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    var scores = [0, 0, 0]
    var ans = 0
    var answer = [Int]()
    
    for i in 0 ..< answers.count {
        if answers[i] == f[i % 5] { scores[0] += 1 }
        if answers[i] == s[i % 8] { scores[1] += 1 }
        if answers[i] == t[i % 10] { scores[2] += 1 }
    }

    for score in scores {
        ans = max(ans, score)
    }
    
    for i in 0..<scores.count {
        if ans == scores[i] { answer.append(i+1) }
    }
    
    return answer
}
