//
//  pg_64062.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/16.
//
//  징검다리 건너기

import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var start = 1
    var end = 200000000

    while start <= end {
        let mid = (start + end) / 2

        var cnt = 0
        for i in 0..<stones.count {
            if stones[i] <= mid {
                cnt += 1
                if cnt == k {
                    break
                }
            } else {
                cnt = 0
            }
        }

        if cnt == k {
            end = mid - 1
        } else {
            start = mid + 1
        }
    }

    return start
}
