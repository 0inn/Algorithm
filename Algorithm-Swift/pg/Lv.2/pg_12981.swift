//
//  pg_12981.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/17.
//
//  영어 끝말잇기

import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var persons = Array(repeating: 0, count: n)
    var arr = [String]()
    
    persons[0] = 1
    if words[0].count == 1 {
        return [1, 1]
    }
    arr.append(words[0])
    for i in 1..<words.count {
        persons[i % n] += 1
        arr.append(words[i])
        if (words[i-1].last! != words[i].first!) || (arr.filter { $0 == words[i] }.count > 1) || (words[i].count == 1) {
            return [(i % n) + 1, persons[i % n]]
        }
    }
    
    return [0, 0]
}
