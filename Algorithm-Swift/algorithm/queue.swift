//
//  queue.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/18.
//

import Foundation

struct Queue<T> {
    private var queue = [T]()
    
    public var count: Int {
        return queue.count
    }
    
    public var isEmpty: Bool {
        return queue.isEmpty
    }
    
    public mutating func enqueue(_ element: T) {
        queue.append(element)
    }
    
    public mutating func dequeue() -> T? {
        return isEmpty ? nil : queue.removeFirst()
    }
    
    public var front: T? {
        return queue.first
    }
}
