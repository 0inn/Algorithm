//
//  boj_1946.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/02/14.
//
//  신입사원

import Foundation

let file = FileIO()
let T = file.readInt()

for _ in 0..<T {
    let N = file.readInt()
    
    var scores: [Int: Int] = [:]
    var ans = N
    
    for _ in 0..<N {
        let first = file.readInt()
        let second = file.readInt()
        
        scores[first, default: 0] = second
    }
    
    let sorted = scores.sorted { $0.key < $1.key }
    var min = 100001
    
    for score in sorted {
        if score.value < min {
            min = score.value
        } else {
            ans -= 1
        }
    }
    
    print(ans)
}
