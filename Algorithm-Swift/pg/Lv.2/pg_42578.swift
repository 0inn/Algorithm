//
//  pg_42578.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/23.
//
//  위장

import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict = [String: Int]()
    
    for cloth in clothes {
        if let c = dict[cloth[1]] {
            dict[cloth[1]] = c + 1
        } else {
            dict[cloth[1]] = 1
        }
    }
    
    return dict.values.map { $0 + 1 }.reduce(1, *) - 1
}
