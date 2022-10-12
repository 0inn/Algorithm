//
//  pg_77484.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/12.
//
// 로또의 최고 순위와 최저 순위

import Foundation

func solution1(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var plus = 0
    var same = 0
    var score = [6, 6, 5, 4, 3, 2, 1]
    
    for lotto in lottos {
        if lotto == 0 {
            plus += 1
        } else if win_nums.contains(lotto) {
            same += 1
        }
    }
    
    return [score[same+plus], score[same]]
}

func solution2(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var score = [6, 6, 5, 4, 3, 2, 1]
    
    var plus = lottos.filter { $0 == 0 }.count
    var same = lottos.filter { win_nums.contains($0) }.count
    
    return [score[same+plus], score[same]]
}
