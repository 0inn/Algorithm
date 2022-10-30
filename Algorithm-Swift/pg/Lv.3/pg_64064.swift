//
//  pg_64064.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/30.
//
//  불량 사용자

import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var idArr = [(String, [String])]()
    var bIdArr = [String]()
    var ans = Set<Set<String>>()
    
    // (banned_id, [user_id]) 저장
    for i in 0..<banned_id.count {
        var bId = banned_id[i]
        bIdArr = []
        
        for j in 0..<user_id.count {
            var isBanned = false
            var uId = user_id[j]
            
            if bId.count != uId.count { continue }
            if (zip(uId, bId).filter { $0 == $1 || $1 == "*" }).count == bId.count {
                isBanned = true
            }
            if isBanned { bIdArr.append(uId) }
        }
        
        idArr.append((bId, bIdArr))
    }

    // dfs 탐색
    func dfs(_ idx: Int, _ array: Set<String>) {
        var arr = array
        if idx == banned_id.count {
            ans.insert(arr)
            return
        }
        for i in idArr[idx].1 {
            if !arr.contains(i) {
                arr.insert(i)
                dfs(idx + 1, arr)
                arr.remove(i)
            }
        }
    }
    
    dfs(0, [])
    
    return ans.count
}
