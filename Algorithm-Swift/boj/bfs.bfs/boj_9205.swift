//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/13.
//
//  맥주 마시면서 걸어가기

import Foundation

let t = Int(readLine()!)!
var home = [Int]()
var stores = [[Int]]()
var rock = [Int]()

// 입력 받기
for _ in 0..<t {
    let n = Int(readLine()!)!
    home = readLine()!.split(separator: " ").map { Int(String($0))! }
    stores.removeAll()
    for _ in 0..<n {
        stores.append(readLine()!.split(separator: " ").map { Int(String($0))! })
    }
    rock = readLine()!.split(separator: " ").map { Int(String($0))! }
    bfs()
}

// bfs 탐색
func bfs() {
    var queue = [[Int]]()
    var visit = Array(repeating: false, count: stores.count)
    queue.append(home)
    
    while !queue.isEmpty {
        let x = queue.first![0]
        let y = queue.first![1]
        queue.removeFirst()
        
        //  락 페스티벌 도착 시 "happy" 출력
        if abs(x - rock[0]) + abs(y - rock[1]) <= 1000 {
            print("happy")
            return
        }
        //  갈 수 있는 편의점 탐색
        else {
            for i in 0..<stores.count {
                if abs(x - stores[i][0]) + abs(y - stores[i][1]) <= 1000 {
                    if (!visit[i]) {
                        visit[i] = true
                        queue.append(stores[i])
                    }
                }
            }
        }
    }
    //  편의점 전부 다 돌아도 락 페스티벌 도착 못할 시 "sad" 출력
    print("sad")
}
