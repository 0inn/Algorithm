//
//  union-find.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//

import Foundation

var items = [Int]()

func find(_ element: Int) -> Int {
    if items[element] == element {
        return element
    }
    return find(items[element])
}

func union(_ first: Int, _ second: Int) {
    let firstParent = find(first)
    let secondParent = find(second)
    if firstParent < secondParent {
        items[secondParent] = firstParent
    } else {
        items[firstParent] = secondParent
    }
}
