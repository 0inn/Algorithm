//
//  countingSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/29.
//

import Foundation

var list = [3, 0, 2, 1, 6, 5, 4, 7]

func countingSort(_ array: inout [Int]) -> [Int] {
    let maxElement = array.max() ?? 0

    // count 배열 생성
    var countArray = [Int](repeating: 0, count: Int(maxElement + 1))
    for element in array {
      countArray[element] += 1
    }
    
    // sum 배열 계산
    for index in 1 ..< countArray.count {
      let sum = countArray[index] + countArray[index - 1]
      countArray[index] = sum
    }
    
    var sortedArray = [Int](repeating: 0, count: array.count)
    for index in stride(from: array.count - 1, through: 0, by: -1) {
      let element = array[index]
      countArray[element] -= 1
      sortedArray[countArray[element]] = element
    }
    
    return sortedArray
}

print(countingSort(&list))
