//
//  boj_1644.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/13.
//

import Foundation

let N = Int(readLine()!)!
var arr: [Int] = [0, 0]
var ans = 0, num = 2, sum = 0

var s = 0, e = 0

// MARK: - 소수 구하기

while num <= N {
    arr.append(num)
    num += 1
}
arr.append(0)

for i in 2...arr.count-1 {
    if arr[i] == 0 { continue }
    
    for j in stride(from: i+i , to: arr.count, by: i) {
        arr[j] = 0
    }
}

arr = arr.filter { $0 != 0 }

// MARK: - 구간합 구하기

while s < arr.count {
    if sum >= N {
        if sum == N {
            ans += 1
        }
        
        sum -= arr[s]
        s += 1
    } else {
        if e == arr.count {
            break
        }
        sum += arr[e]
        e += 1
    }
}

print(ans)
