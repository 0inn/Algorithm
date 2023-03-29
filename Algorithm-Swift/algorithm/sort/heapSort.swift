//
//  heapSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/29.
//

import Foundation

var list = [3, 0, 2, 1, 6, 5, 4, 7]

extension Heap {
    public mutating func heapSort() -> [T] {
        for _ in stride(from: (nodes.count - 1), through: 0, by: -1) {
            sortedNodes.append(delete())
        }
        return sortedNodes
    }
}

public func heapSort<T>(_ a: [T], _ sort: @escaping (T, T) -> Bool) -> [T] {
    var h = Heap(array: a, sort: sort)
    return h.heapSort()
}

print(heapSort(list, >))
