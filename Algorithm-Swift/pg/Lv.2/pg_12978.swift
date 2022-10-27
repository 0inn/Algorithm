//
//  pg_12978.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/26.
//
//  배달

import Foundation

func solution1(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var visit = Array(repeating: Int.max, count: N + 1)
    var cities = [Int: [[Int]]]()
    var queue = [[Int]]()
    var ans = 0
    
    for i in 0...N {
        cities[i] = []
    }
    
    for r in road {
        cities[r[0]]!.append([r[1], r[2]])
        cities[r[1]]!.append([r[0], r[2]])
    }
    
    func bfs(_ start: Int) {
        queue.append([start, 0])
        visit[start] = 0
        
        while !queue.isEmpty {
            let cur = queue.first!
            queue.removeFirst()
            
            for city in cities[cur[0]]! {
                let nxtCity = city[0]
                let nxtCnt = city[1] + cur[1]
                if nxtCnt < visit[nxtCity] && nxtCnt <= k {
                    queue.append([nxtCity, nxtCnt])
                    visit[nxtCity] = nxtCnt
                }
            }
        }
    }
    
    bfs(1)
    
    for v in visit {
        if v != Int.max {
            ans += 1
        }
    }
    
    return ans
}

// 코드 개선
func solution2(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var dist = [Int](repeating: Int(1e9), count: N + 1)
    var graph = [[(Int, Int)]](repeating: [], count: N + 1)
    var q = [Int]()
    
    for r in road {
        graph[r[0]].append((r[1], r[2]))
        graph[r[1]].append((r[0], r[2]))
    }
    
    // 다익스트라
    q.append(1)
    dist[1] = 0
    
    while !q.isEmpty {
        let cur = q.first!
        q.removeFirst()
        
        for (nxtN, nxtW) in graph[cur] {
            let newWeight = dist[cur] + nxtW
            if newWeight < dist[nxtN] && newWeight <= k {
                q.append(nxtN)
                dist[nxtN] = newWeight
            }
        }
    }
    
    return dist.filter { $0 <= k }.count
}

// 플로이드 워셜
func solution3(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var dist = [[Int]](repeating: [Int](repeating: Int(1e9), count: N + 1), count: N + 1)

    for i in 1...N {
        dist[i][i] = 0
    }
    
    for r in road {
        dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2])
        dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2])
    }
    
    for k in 1...N {
        for i in 1...N {
            for j in 1...N {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
            }
        }
    }
    
    return dist[1].filter { $0 <= k }.count
}
