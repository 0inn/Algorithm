//
//  topologicalSort.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/30.
//

import Foundation

var n = 7
var inDegree = Array(repeating: 0, count: n + 1)
var graph = [[Int]]()
var result = [Int]()

func topologicalSort() {
    var queue = [Int]()
    
    // 진입 차수가 0인 노드를 큐에 삽입
    for idx in 1...n {
        if inDegree[idx] == 0 { queue.append(idx) }
    }
    
    // 정렬이 완전히 수행되려면 n개 노드 방문
    for _ in 1...n {
        // 정렬 과정에서 큐가 비면 사이클이 발생한 것
        if queue.isEmpty {
            return
        }
        
        let cur = queue.first!
        queue.removeFirst()
        result.append(cur)
        
        for n in graph[cur] {
            inDegree[n] -= 1
            // 새롭게 진입차수가 0이 된 정점을 큐에 삽입
            if inDegree[n] == 0 {
                queue.append(n)
            }
        }
    }
}

graph = [[], [2, 5], [3], [4], [6], [6], [7], []]

for n in graph {
    for degree in n {
        inDegree[degree] += 1
    }
}

topologicalSort()

print(result)
