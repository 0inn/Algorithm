//
//  pg_42842.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/17.
//
//  카펫

import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var total = brown + yellow
    var column = 0
    var x = 0
    var y = 0
    
    for row in 1..<total/2 {
        if total % row != 0 { continue }
        column = total / row
        if (row - 2) * (column - 2) == yellow {
            x = max(row, column)
            y = min(row, column)
        }
    }
    
    return [x, y]
}
