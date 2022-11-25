//
//  pg_138476.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/25.
//
//  귤 고르기

import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dict = [Int: Int]()
    var except = tangerine.count - k
    var ans = 0

    for tang in tangerine {
        if let cnt = dict[tang] {
            dict[tang] = cnt + 1
        } else {
            dict[tang] = 1
        }
    }

    var arr = dict.sorted { $0.1 < $1.1 }.map { [ $0.0, $0.1 ] }

    for i in 0..<arr.count {
        except -= arr[i][1]
        if i == arr.count - 1 {
            ans = 1
            break
        }
        if except < 0 {
            ans = arr.count - i
            break
        } else if except == 0 {
            ans = arr.count - (i + 1)
            break
        }
    }

    return ans
}
