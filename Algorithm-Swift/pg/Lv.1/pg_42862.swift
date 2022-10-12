//
//  pg_42862.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/12.
//
// 체육복

import Foundation

func solution1(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var ans = n - lost.count
    var losts = lost.sorted()
    var r = reserve.sorted()

    for i in 0..<losts.count {
        if let idx = r.firstIndex(of: losts[i]) {
            ans += 1
            r[idx] = -1
            losts[i] = -1
        }
    }

    for l in losts {
        if let idx = r.firstIndex(of: l-1) {
            ans += 1
            r[idx] = -1
        } else if let idx = r.firstIndex(of: l+1) {
            ans += 1
            r[idx] = -1
        }
    }

    return ans
}

func solution2(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var reserved = reserve.filter { !lost.contains($0) }.sorted()
    var losted = lost.filter { !reserve.contains($0) }.sorted()
    var ans = n - losted.count
    
    for lost in losted {
        if let idx = reserved.firstIndex(of: lost-1) {
            ans += 1
            reserved.remove(at: idx)
        } else if let idx = reserved.firstIndex(of: lost+1) {
            ans += 1
            reserved.remove(at: idx)
        }
    }
    
    return ans
}
