//
//  pg_17677.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/29.
//
//  [1차] 뉴스 클러스터링

import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    var dict1 = [String: Int]()
    var dict2 = [String: Int]()
    var total = Set<String>()
    var s1 = Array(str1.lowercased())
    var s2 = Array(str2.lowercased())
    var inter = 0
    var union = 0
    
    for i in 0..<s1.count-1 {
        let tmpStr = String(s1[i]) + String(s1[i+1])
        if !tmpStr.allSatisfy ({ $0.isLetter }) {
            continue
        }
        if let cnt = dict1[tmpStr] {
            dict1[tmpStr] = cnt + 1
        } else {
            dict1[tmpStr] = 1
        }
        total.insert(tmpStr)
    }
    
    for i in 0..<s2.count-1 {
        let tmpStr = String(s2[i]) + String(s2[i+1])
        if !tmpStr.allSatisfy ({ $0.isLetter }) {
            continue
        }
        if let cnt = dict2[tmpStr] {
            dict2[tmpStr] = cnt + 1
        } else {
            dict2[tmpStr] = 1
        }
        total.insert(tmpStr)
    }
    
    for str in total {
        inter += min(dict1[str] ?? 0, dict2[str] ?? 0)
        union += max(dict1[str] ?? 0, dict2[str] ?? 0)
    }
    
    if dict1.isEmpty && dict2.isEmpty {
        return 65536
    }
    
    return Int(floor(Double(inter) / Double(union) * 65536))
}
