//
//  pg_12905.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/16.
//
//  가장 큰 정사각형 찾기

import Foundation

func solution(_ board:[[Int]]) -> Int {
    var arr = board
    var ans = 0
    
    if board[0].contains(1) { ans = 1 }
    // for r in 0..<board.count {
    //     if board[r][0] == 1 { ans = 1 }
    // }
    
    for r in 1..<board.count {
        for c in 1..<board[r].count {
            if board[r][c] == 0 { continue }
            var minN = min(arr[r-1][c-1], arr[r-1][c])
            minN = min(minN, arr[r][c-1])
            arr[r][c] = minN + 1
            ans = max(ans, minN + 1)
        }
    }

    return ans * ans
}
