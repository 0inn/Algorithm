//
//  pg_68644.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  두 개 뽑아서 더하기

import Foundation

// 조합
func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return result }
    func cycle(_ index: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    cycle(0, [])
    return result
}

func solution1(_ numbers:[Int]) -> [Int] {
    var nums = combination(numbers, 2)
    var ans = [Int](Set(nums.map { $0[0] + $0[1] })).sorted()
    return ans
}

func solution2(_ numbers:[Int]) -> [Int] {
    var ans = [Int]()
    for i in 0..<numbers.count {
        for j in i+1..<numbers.count {
            let num = numbers[i] + numbers[j]
            if (!ans.contains(num)) {
                ans.append(num)
            }
        }
    }
    return ans.sorted()
}
