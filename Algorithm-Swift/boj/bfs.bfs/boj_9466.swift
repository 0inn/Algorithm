//
//  boj_9466.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/28.
//

import Foundation

let t = Int(readLine()!)!

for _ in 0..<t {
    let n = Int(readLine()!)!
    
    var arr = [Int]()
    var visit = Array(repeating: false, count: n + 1)
    var match = Array(repeating: false, count: n + 1)
    var cnt = 0
    
    func dfs(_ n: Int) {
        visit[n] = true
        
        let nxt = arr[n]
        if !visit[nxt] {
            dfs(nxt)
        } else if !match[nxt] { // cycle 존재
            var i = nxt
            while true {
                if i == n { break }
                cnt += 1
                i = arr[i]
            }
            cnt += 1
        }
        
        match[n] = true
    }
    
    func solution(_ graph: [Int]) {
        for i in 1...n {
            if visit[i] { continue }
            dfs(i)
        }
    }
    
    arr = readLine()!.split(separator: " ").map { Int(String($0))! }
    arr.insert(0, at: 0)
    
    solution(arr)
    print(n - cnt)
}
