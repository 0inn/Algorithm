import Foundation

var arr: [[String]] = []
var cycle: [[[Bool]]] = []
var N: Int = 0
var M: Int = 0
var ans: [Int] = []

// 상 하 좌 우
let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

var cnt: Int = 0
var start: (Int, Int, Int) = (0, 0, 0)

func move(_ x: Int, _ y: Int, _ dir: Int) {
    if (x, y, dir) == start && cycle[x][y][dir] { // 사이클 발생
        ans.append(cnt)
        return
    }
    
    cycle[x][y][dir] = true
    
    var nxt: (Int, Int, Int) = (0, 0, 0)
    
    if arr[x][y] == "S" { // 직진
        switch dir {
            case 0:
                nxt = (1, 0, 0)
            case 1:
                nxt = (-1, 0, 1)
            case 2:
                nxt = (0, 1, 2)
            default:
                nxt = (0, -1, 3)
        }
    } else if arr[x][y] == "L" { // 좌
        switch dir {
            case 0:
                nxt = (0, 1, 2)
            case 1:
                nxt = (0, -1, 3)
            case 2:
                nxt = (-1, 0, 1)
            default:
                nxt = (1, 0, 0)
        }
    } else { // 우
        switch dir {
            case 0:
                nxt = (0, -1, 3)
            case 1:
                nxt = (0, 1, 2)
            case 2:
                nxt = (1, 0, 0)
            default:
                nxt = (-1, 0, 1)
        }        
    }
    
    var nx = x + nxt.0
    var ny = y + nxt.1
    let nd = nxt.2
    
    if nx < 0 {
        nx = N - 1
    } else if nx >= N {
        nx = 0
    }
    
    if ny < 0 {
        ny = M - 1
    } else if ny >= M {
        ny = 0
    }
    
    cnt += 1
    
    move(nx, ny, nd)
}

func solution(_ grid:[String]) -> [Int] {
    for str in grid {
        arr.append(Array(str).map { String($0) })
    }
    
    N = arr.count
    M = arr[0].count
    
    cycle = Array(repeating: Array(repeating: [false, false, false, false], count: M), count: N)
    
    // 처음 시작하는 격자의 경우, 모든 방향 고려
    for i in 0..<N {
        for j in 0..<M {
            for dir in 0..<4 {
                if cycle[i][j][dir] { continue }
                cnt = 0
                start = (i, j, dir)
                move(i, j, dir)
            }
        }
    }
    
    return ans.sorted()
}