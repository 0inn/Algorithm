//
//  boj_1068.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/01.
//
//  트리

import Foundation

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map { Int(String($0))! }
let node = Int(readLine()!)!

var tree = [Int:[Int]]()
var parent = Array(repeating: -1, count: N)
var visit = Array(repeating: false, count: N)
var root = -1
var ans = 0

for i in 0..<N {
    // 루트 노드가 0이 아닐 가능성 존재
    if arr[i] == -1 {
        root = i
    }
    
    if let _ = tree[arr[i]] {
        tree[arr[i]]!.append(i)
    } else {
        tree[arr[i]] = [i]
    }
    
    parent[i] = arr[i]
}

func dfs(_ n: Int) {
    visit[n] = true
    
    if n == node {
        // 해당 노드를 지웠을 때, 부모 노드가 리프노드가 되는 경우 고려
        if tree[parent[n]]!.filter({ $0 != n }).isEmpty {
            ans += 1
        }
        return
    }
    
    if tree[n] == nil {
        ans += 1
    } else {
        for nxt in tree[n]! {
            if visit[nxt] { continue }
            dfs(nxt)
        }
    }
}

// 루트 노드를 지울 경우, ans = 0
if node != root {
    dfs(root)
}

print(ans)
