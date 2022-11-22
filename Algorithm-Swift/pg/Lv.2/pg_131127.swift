//
//  pg_131127.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/22.
//
//  할인 행사

import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var dict = [String: Int]()
    var ans = 0

    for day in 0...(discount.count - 10) {
        for i in 0...9 {
            let today = discount[day+i]
            if let food = dict[today] {
                dict[today] = food + 1
            } else {
                dict[today] = 1
            }
        }

        var isAns = true

        for i in 0..<want.count {
            if dict[want[i]] == nil {
                isAns = false
                break
            } else if dict[want[i]]! < number[i] {
                isAns = false
                break
            }
        }

        if isAns {
            ans += 1
        }

        dict.removeAll()
    }

    return ans
}
