//
//  heap.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//

import Foundation

class Heap {
    var items = [Int]()
    
    init(_ val: Int) {
        items.append(val)
        items.append(val)
    }
    
    func percolate_up() {
        var i = items.count - 1
        var parent = Int(i / 2)
        while parent > 0 {
            if items[i] > items[parent] {
                items.swapAt(i, parent)
            }
            i = parent
            parent = Int(i / 2)
        }
    }
    
    func insert(_ k: Int) {
        items.append(k)
        percolate_up()
    }
    
    func percolate_down(idx: Int) {
        let left = idx * 2
        let right = idx * 2 + 1
        var biggest = idx
        
        if left <= items.count - 1 && items[left] > items[biggest] {
            biggest = left
        }
        
        if right <= items.count - 1 && items[right] > items[biggest] {
            biggest = right
        }
        
        if biggest != idx {
            items.swapAt(idx, biggest)
            percolate_down(idx: biggest)
        }
    }
    
    func pop() -> Int {
        let popped = items[1]
        items[1] = items[items.count - 1]
        items.removeLast()
        percolate_down(idx: 1)
        return popped
    }
}

// 사용법
var heap = Heap.init(30)
heap.insert(20)
heap.insert(18)
heap.insert(9)
heap.insert(6)
heap.insert(50)

print(heap.items)
