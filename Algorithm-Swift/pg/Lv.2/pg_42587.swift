//
//  pg_42587.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/26.
//
//  프린터

import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var idx = Array(0..<priorities.count)
    var arr = priorities
    var ans = 0
    
    while true {
        let front = arr.first!
        let idxFront = idx.first!
        arr.removeFirst()
        idx.removeFirst()
        
        if arr.isEmpty {
            return ans + 1
        }
        
        let sortArr = arr.sorted { $0 > $1 }
        if front >= sortArr[0] {
            ans += 1
            if idxFront == location {
                return ans
            }
        } else {
            arr.append(front)
            idx.append(idxFront)
        }
    }
}
