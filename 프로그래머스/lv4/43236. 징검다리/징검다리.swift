import Foundation

var rocks: [Int] = []
var dists: [Int] = []
var n: Int = 0

func check(_ mid: Int) -> Bool {
    var cnt = 0
    var remove = 0
    
    for i in dists.indices {
        if cnt > n { return false }
        if (dists[i] + remove) < mid {
            cnt += 1
            remove += dists[i]
        } else {
            remove = 0
        }
    }
    
    return true
}

func solution(_ distance:Int, _ array:[Int], _ N:Int) -> Int {
    rocks = array.sorted()
    n = N
    var low = 0
    var high = distance
    
    dists.append(rocks.first!)
    for i in 1..<rocks.count {
        dists.append(rocks[i] - rocks[i-1])
    }
    dists.append(distance)
    
    while low + 1 < high {
        let mid = (low + high) / 2
        
        if check(mid) {
            low = mid
        } else {
            high = mid
        }
    }
    
    return low
}