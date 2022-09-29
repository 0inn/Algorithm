//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution1(_ x:Int, _ n:Int) -> [Int64] {
    var arr = [Int64]()
    
    for i in 1...n {
        arr.append(Int64(x * i))
    }
    
    return arr
}

func solution2(_ x:Int, _ n:Int) -> [Int64] {
    return Array(1...n).map { Int64(x * $0) }
}

print(solution1(2, 5), solution2(2, 5))
