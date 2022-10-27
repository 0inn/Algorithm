//
//  permutation.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//

import Foundation

func permutation<T: Comparable>(_ arr: [[T]], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if arr.count < n { return result }
    
    var visit = Array(repeating: false, count: arr.count)
    
    func cycle(_ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in 0..<arr.count {
            if visit[i] { continue }
            visit[i] = true
            cycle(now)
            visit[i] = false
        }
    }
    
    cycle([])
    
    return result
}
