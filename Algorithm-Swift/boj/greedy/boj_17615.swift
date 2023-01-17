//
//  boj_17615.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/17.
//

import Foundation

let N = Int(readLine()!)!
let balls = Array(readLine()!).map { String($0) }
var ans = 500001

func swapBalls(arr: [String], swapBall: String, noneSwapBall: String) -> Int {
    let balls = arr
    var swap = false
    var cnt = 0
    
    for ball in balls {
        if ball == swapBall { swap = true }
        if ball == noneSwapBall && swap { cnt += 1 }
    }
    
    return cnt
}

ans = min(swapBalls(arr: balls, swapBall: "R", noneSwapBall: "B"),
          swapBalls(arr: balls, swapBall: "B", noneSwapBall: "R"))
ans = min(ans, swapBalls(arr: balls.reversed(), swapBall: "R", noneSwapBall: "B"))
ans = min(ans, swapBalls(arr: balls.reversed(), swapBall: "B", noneSwapBall: "R"))

print(ans)
