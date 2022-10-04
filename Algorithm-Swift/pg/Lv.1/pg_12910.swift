//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    let ans = arr.filter{ $0 % divisor == 0 }.sorted()
    // ans.isEmpty()로 하니까 시간초과 ..
    return ans.count == 0 ? [-1] : ans
}

print(solution([5, 9, 7, 10], 5))
