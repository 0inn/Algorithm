//
//  boj_1182.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/04.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
var arr = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let S = input[1]
var ans = 0

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


for i in 1...N {
    let arrs = combinatioin(arr, i)
    ans += arrs.map { $0.reduce(0, +) }.filter { $0 == S }.count
}

print(ans)
