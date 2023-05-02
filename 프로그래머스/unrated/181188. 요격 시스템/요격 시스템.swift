import Foundation

func solution(_ targets:[[Int]]) -> Int {
    var ans = 0, end = 0
    var targets = targets.sorted { 
        $0[1] == $1[1] ? $0[0] < $1[0] : $0[1] < $1[1]
    }
    
    for target in targets {
        if end <= target[0] {
            ans += 1
            end = target[1]
        }
    }
    
    return ans
}