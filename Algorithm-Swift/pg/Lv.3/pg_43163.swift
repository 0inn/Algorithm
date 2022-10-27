//
//  pg_43163.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//
//  단어 변환

import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var cnt = 0
    var q = [String]()
    var dist = [String: Int]()
    
    for word in words {
        dist[word] = Int(1e9)
    }
    
    func canSwitch(_ str1: String, _ str2: String) -> Bool {
        cnt = zip(Array(str1), Array(str2)).map { $0 != $1 }.filter { $0 }.count
        return cnt == 1 ? true : false
    }
    
    func bfs(_ word: String) {
        q.append(word)
        dist[word] = 0
        
        while !q.isEmpty {
            let cur = q.first!
            q.removeFirst()
            
            for nxt in words {
                if !canSwitch(cur, nxt) { continue }
                if dist[cur]! + 1 < dist[nxt]! {
                    q.append(nxt)
                    dist[nxt]! = dist[cur]! + 1
                }
            }
        }
    }
    
    bfs(begin)
    
    return dist[target] ?? 0
}
