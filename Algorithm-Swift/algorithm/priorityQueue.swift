//
//  priority queue.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/24.
//

struct EdgeData: Comparable {
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        return lhs.cost < rhs.cost
    }
    
    let node: Int
    let cost: Int
}

let pq = Heap<EdgeData>(sort: <)
