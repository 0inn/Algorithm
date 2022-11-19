//
//  pg_92344.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/19.
//
//  파괴되지 않은 건물

import Foundation

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    var game = board
    var score = Array(repeating: Array(repeating: 0, count: board[0].count + 1), count: board.count + 1)
    var ans = 0

    for s in skill {
        let type = s[0] == 1 ? -1 : 1
        let n = s[5] * type

        score[s[1]][s[2]] += n
        score[s[3]+1][s[4]+1] += n
        score[s[1]][s[4]+1] += n * (-1)
        score[s[3]+1][s[2]] += n * (-1)
    }

    for i in 0..<score.count {
        for j in 1..<score[0].count {
            score[i][j] += score[i][j-1]
        }
    }

    for i in 0..<score[0].count {
        for j in 1..<score.count {
            score[j][i] += score[j-1][i]
        }
    }

    for i in 0..<game.count {
        for j in 0..<game[i].count {
            game[i][j] += score[i][j]
            if game[i][j] > 0 { ans += 1 }
        }
    }

    return ans
}
