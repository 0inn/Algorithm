//
//  main.swift
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/03.
//

import Foundation

struct Info {
    let n: Int
    var w: Int
}

let input = readLine()!.split(separator: " ").map { Int($0)! }
let (N, Q) = (input[0], input[1])

let INF = Int.max
var mootube: [[Info]] = Array(repeating: [], count: N+1)

func inputN() {
    for _ in 0..<N-1 {
        let n = readLine()!.split(separator: " ").map { Int($0)! }
        let (p, q, r) = (n[0], n[1], n[2])
        mootube[p].append(Info(n: q, w: r))
        mootube[q].append(Info(n: p, w: r))
    }
}

func findMootube(k: Int, v: Int) -> Int {
    var nums = Array(repeating: INF, count: N+1)
    var check = Array(repeating: false, count: N+1)
    check[v] = true
    
    var queue = [Info]()
    queue.append(Info(n: v, w: INF))
    var idx = 0
    
    while queue.count > idx {
        let cur = queue[idx]
        
        nums[cur.n] = min(nums[cur.n], cur.w)
        
        for nxt in mootube[cur.n] {
            if !check[nxt.n] {
                check[nxt.n] = true
                let nxtw = min(cur.w, nxt.w)
                queue.append(Info(n: nxt.n, w: nxtw))
            }
        }
        
        idx += 1
    }
    
    return nums.filter { $0 >= k && $0 != INF }.count
}

func inputQ() {
    for _ in 0..<Q {
        let n = readLine()!.split(separator: " ").map { Int($0)! }
        let (k, v) = (n[0], n[1])
        let ans = findMootube(k: k, v: v)
        print(ans < 0 ? 0 : ans)
    }
}

inputN()
inputQ()
