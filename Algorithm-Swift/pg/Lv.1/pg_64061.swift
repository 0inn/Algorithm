//
//  pg_64061.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/13.
//
//  크레인 인형뽑기 게임

import Foundation

func solution(_ boards:[[Int]], _ moves:[Int]) -> Int {
    var board = boards
    var arr = [Int]()
    var ans = 0
    
    for move in moves {
        var m = move
        for i in 0..<board.count {
            let doll = board[i][m-1]
            if doll != 0 {  // 인형 집을 수 있는 경우
                arr.append(doll)
                board[i][m-1] = 0
                if arr.count >= 2 {
                    // 인형 터뜨리기
                    if arr[arr.count-1] == arr[arr.count-2] {
                        ans += 2
                        arr.removeSubrange(arr.count-2...arr.count-1)
                    }
                }
                break
            }
        }
    }
    
    return ans
}
