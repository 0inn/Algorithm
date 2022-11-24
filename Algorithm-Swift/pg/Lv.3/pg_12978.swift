//
//  pg_12978.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/24.
//
//  합승 택시 요금

import Foundation

// 다익스트라
func solution1(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var graph = [Int: [(Int, Int)]]()
    let bothDist = Array(repeating: Int(1e9), count: n + 1)
    var dist = Array(repeating: Int(1e9), count: n + 1)
    var pq = Heap<EdgeData>(sort: <)
    var ans = Int(1e9)
    
    for i in 1...n {
        graph[i] = []
    }
    
    for fare in fares {
        graph[fare[0]]!.append((fare[1], fare[2]))
        graph[fare[1]]!.append((fare[0], fare[2]))
    }
    
    func dijkstra(_ s: Int, _ dist: [Int]) -> [Int] {
        var dist = dist
        dist[s] = 0
        pq.insert(EdgeData(node: s, cost: 0))
        
        while !pq.isEmpty {
            let cur = pq.delete()
            let (curNode, curDist) = (cur.node, cur.cost)
            
            if dist[curNode] < curDist {
                continue
            }
            
            for (nxtNode, nxtCost) in graph[curNode]! {
                let nxtDist = curDist + nxtCost
                
                if nxtDist < dist[nxtNode] {
                    dist[nxtNode] = nxtDist
                    pq.insert(EdgeData(node: nxtNode, cost: nxtDist))
                }
            }
        }
        
        return dist
    }
    
    let firstArr = dijkstra(s, bothDist)
    
    for i in 1...n {
        dist = Array(repeating: Int(1e9), count: n + 1)
        let arr = dijkstra(i, dist)
        let a = arr[a]
        let b = arr[b]
        ans = min(ans, firstArr[i] + a + b)
    }
    
    return ans
}

// 플로이드 워샬
func solution2(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var dist = [[Int]](repeating: [Int](repeating: Int(1e9), count: n + 1), count: n + 1)
    var ans = Int(1e9)
    
    for i in 1...n {
        dist[i][i] = 0
    }
    
    for fare in fares {
        dist[fare[0]][fare[1]] = fare[2]
        dist[fare[1]][fare[0]] = fare[2]
    }
    
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                if dist[i][j] > dist[i][k] + dist[k][j] {
                    dist[i][j] = dist[i][k] + dist[k][j]
                }
            }
        }
    }
    
    ans = dist[s][a] + dist[s][b]
    
    for i in 1...n {
        ans = min(ans, dist[s][i] + dist[i][a] + dist[i][b])
    }
    
    return ans
}
