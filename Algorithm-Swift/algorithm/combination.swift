//
//  combination.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//

import Foundation

func combinatioin<T: Comparable>(_ arr: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if arr.count < n { return result }
    
    func cycle(_ idx: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in idx..<arr.count {
            cycle(i + 1, now + [arr[i]])
        }
    }
    
    cycle(0, [])
    
    return result
}
