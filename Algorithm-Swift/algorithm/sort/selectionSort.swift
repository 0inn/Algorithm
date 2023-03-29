//
//  selectionSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/29.
//

import Foundation

var list = [3, 0, 2, 1, 6, 5, 4, 7]

func selectionSort(_ array: [Int]) -> [Int] {
  guard array.count > 1 else { return array }  // 1

  var a = array                    // 2

  for x in 0 ..< a.count - 1 {     // 3

    var lowest = x
    for y in x + 1 ..< a.count {   // 4
      if a[y] < a[lowest] {
        lowest = y
      }
    }

    if x != lowest {               // 5
      a.swapAt(x, lowest)
    }
  }
  return a
}

print(selectionSort(list))
