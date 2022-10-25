//
//  pg_42628.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//
//  이준우선순위큐

import Foundation

func solution(_ operations:[String]) -> [Int] {
    var queue = [Int]()
    
    for op in operations {
        var arr = op.split(separator: " ")
        let num = Int(arr[1])!
        if arr[0] == "I" {
            queue.append(num)
            queue.sort { $0 > $1 }
        } else if !queue.isEmpty {
            if num == 1 {
                queue.removeFirst()
            } else {
                queue.removeLast()
            }
        }
    }
    
    return [queue.first ?? 0, queue.last ?? 0]
}
