//
//  boj_21608.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/02/15.
//
//  상어 초등학교

import Foundation

let N = Int(readLine()!)!

var arr = Array(repeating: Array(repeating: 0, count: N), count: N)
var seat = [Int: (Int , Int)]()
var empty = Array(repeating: Array(repeating: 0, count: N), count: N)
var likeFriends = [Int: [Int]]()

let dx = [0, 0, -1, 1]
let dy = [-1, 1, 0, 0]

// 비어있는 칸 수 저장하는 배열
for i in 0..<N {
    for j in 0..<N {
        if i == 0 || i == N - 1 {
            if j == 0 || j == N - 1 {
                empty[i][j] = 2
            } else {
                empty[i][j] = 3
            }
        } else if j == 0 || j == N - 1 {
            empty[i][j] = 3
        } else {
            empty[i][j] = 4
        }
    }
}

// 주변 인접한 칸 -1 해주는 함수
func calculateEmpty(x: Int, y: Int) {
    empty[x][y] = -1
    
    for dir in 0..<4 {
        let nx = x + dx[dir]
        let ny = y + dy[dir]
        
        if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
        if empty[nx][ny] == -1 { continue }
        empty[nx][ny] -= 1
    }
}

// 갈 수 있는 곳 겹칠 때, 행과 열 기준으로 위치 구하는 함수
func makePoint(point: [(Int, Int)]) -> (Int, Int) {
    let select = point.sorted {
        if $0.0 == $1.0 {
            return $0.1 < $1.1
        } else {
            return $0.0 < $1.0
        }
    }
    
    return select.first ?? (-1, -1)
}

// 인접한 칸 중 빈칸 많은 칸 구하는 함수
func checkEmpty(_ arr: [(Int, Int)]) -> (Int, Int) {
    var result = 0
    var point = [(Int, Int, Int)]()
    
    if arr.isEmpty {
        for i in 0..<N {
            for j in 0..<N {
                if result <= empty[i][j] {
                    result = empty[i][j]
                    point.append((result, i, j))
                }
            }
        }
    } else {
        for (i, j) in arr {
            if result <= empty[i][j] {
                result = empty[i][j]
                point.append((result, i, j))
            }
        }
    }
    
    let maximum = point.sorted { $0.0 < $1.0 }.last!.0
    let resultPoint = point.filter { $0.0 == maximum }.map { ($0.1, $0.2) }
    
    return makePoint(point: resultPoint)
}

// 좋아하는 학생 인접한 수 구하는 함수
func checkLike(likes: [(Int, Int)]) -> (Int, Int) {
    var arounds = Array(repeating: Array(repeating: 0, count: N), count: N)
    var result = 0
    var point = [(Int, Int, Int)]()
    
    for like in likes {
        for dir in 0..<4 {
            let nx = like.0 + dx[dir]
            let ny = like.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            if empty[nx][ny] == -1 { continue }
            
            arounds[nx][ny] += 1
            if result <= arounds[nx][ny] {
                result = arounds[nx][ny]
                point.append((result, nx, ny))
            }
        }
    }
    
    if point.isEmpty {
        return checkEmpty([])
    } else {
        let maximum = point.sorted { $0.0 < $1.0 }.last!.0
        let resultPoint = point.filter { $0.0 == maximum }.map { ($0.1, $0.2) }
        
        return checkEmpty(resultPoint)
    }
}

for _ in 0..<N * N {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let student = input[0]
    let likes = input[1...4]
    var checkLikes = [(Int, Int)]()
    
    likeFriends[student, default: []] = likes.map { Int(exactly: $0)! }
    
    for like in likes {
        if let exist = seat[like] {
            checkLikes.append(exist)
        }
    }
    
    if !checkLikes.isEmpty {
        // 좋아하는 학생 있다면
        let point = checkLike(likes: checkLikes)
        seat[student, default: (-1, -1)] = point
        calculateEmpty(x: point.0, y: point.1)
    }
    // 없다면
    else {
        let point = checkEmpty([]) // 빈자리 중 인접한 빈자리 많은 칸으로 정하기
        seat[student, default: (-1, -1)] = point
        calculateEmpty(x: point.0, y: point.1)
    }
}

var ans = 0

// 만족도 구하는 함수
for student in seat {
    let num = student.key
    let point = student.value
    var sum = 0
    var result = 0
    
    for like in likeFriends[num]! {
        for dir in 0..<4 {
            let nx = point.0 + dx[dir]
            let ny = point.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            
            if seat[like]! == (nx, ny) {
                sum += 1
            }
        }
    }
    
    if sum == 1 {
        result = 1
    } else if sum == 2 {
        result = 10
    } else if sum == 3 {
        result = 100
    } else if sum == 4 {
        result = 1000
    }
    
    ans += result
}

print(ans)
