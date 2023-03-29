//
//  heap.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/24.
//

import Foundation

struct Heap<T> {
    var nodes: [T] = []
    var sortedNodes: [T] = []
    private let sort: (T, T) -> Bool
    
    init(sort: @escaping (T, T) -> Bool) {
        self.sort = sort
    }
    
    init(array: [T], sort: @escaping (T, T) -> Bool) {
        self.sort = sort
        configureHeap(from: array)
    }
    
    var isEmpty: Bool {
        nodes.isEmpty
    }
    
    mutating func configureHeap(from array: [T]) {
        let nodes = array
        for node in nodes {
            insert(node)
        }
    }
    
    mutating func insert(_ element: T) {
        var index = nodes.count
        nodes.append(element)
        
        while index > 0, sort(nodes[index], nodes[(index-1)/2]) {
            nodes.swapAt(index, (index-1)/2)
            index = (index-1)/2
        }
    }
    
    mutating func delete() -> T {
        if nodes.count == 1 {
            return nodes.removeLast()
        }
        
        let result = nodes.first!
        nodes.swapAt(0, nodes.count - 1)
        _ = nodes.popLast()
        
        var index = 0
        
        while index < nodes.count {
            let leftChild = index * 2 + 1
            let rightChild = leftChild + 1
            
            let children = [leftChild, rightChild]
                .filter { $0 < nodes.count && sort(nodes[$0], nodes[index]) }
                .sorted { sort(nodes[$0], nodes[$1]) }
            
            if children.isEmpty {
                break
            }
            
            nodes.swapAt(index, children[0])
            index = children[0]
        }
        
        return result
    }
}
