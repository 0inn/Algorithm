//
//  radixSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/29.
//

import Foundation

var list = [10, 3, 0, 2, 1, 21, 6, 5, 4, 7]

func radixSort(_ array: inout [Int]) -> [Int] {
  let radix = 10  // 0 ~ 9
  var done = false
  var index: Int
  var digit = 1  // 일의 자리부터 시작

  while !done {
    done = true

    var buckets: [[Int]] = []

    for _ in 1...radix {
      buckets.append([])
    }

    for number in array {
      index = number / digit
      buckets[index % radix].append(number)
      if done && index > 0 {
        done = false
      }
    }

    var i = 0

    for j in 0..<radix {
      let bucket = buckets[j]
      for number in bucket {
        array[i] = number
        i += 1
      }
    }

    digit *= radix
  }
    
    return array
}


print(radixSort(&list))
