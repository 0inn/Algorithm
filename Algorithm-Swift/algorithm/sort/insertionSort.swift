//
//  insertionSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/29.
//

import Foundation

var list = [3, 0, 2, 1, 6, 5, 4, 7]

func insertionSort(_ array: [Int]) -> [Int] {
    var sortedArray = array             // 1
    for index in 1..<sortedArray.count {         // 2
        var currentIndex = index
        while currentIndex > 0 &&
                sortedArray[currentIndex] < sortedArray[currentIndex - 1] { // 3
            sortedArray.swapAt(currentIndex - 1, currentIndex)
            currentIndex -= 1
        }
    }
    return sortedArray
}

print(insertionSort(list))
