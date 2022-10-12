//
//  pg_42889.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/12.
//
//  실패율

import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var scores = [(Int, Double)]()
    var cnt = [Double](repeating: 0, count: N+2)
    var sum = Double(stages.count)
    
    for stage in stages {
        cnt[stage] += 1
    }
    
    (1...N).forEach { i in
        sum -= cnt[i-1]
        scores.append((i, cnt[i] / sum))
    }
    
    return scores.sorted { $0.1 > $1.1 }.map { $0.0 }
}
