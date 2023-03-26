import Foundation

func solution(_ scores:[[Int]]) -> Int {
    let wanho = scores[0]
    var ans = 1
    var maxScore = 0
    
    let scores = scores.sorted { $0[0] == $1[0] ? $0[1] < $1[1] : $0[0] > $1[0] }
    
    for score in scores {
        if score[1] < maxScore { // 인센티브 받지 못함
            if score == wanho {
                return -1
            }
        } else {
            maxScore = max(score[1], maxScore) // 동료 평가 점수 최대값으로 갱신
            
            if score.reduce(0, +) > wanho.reduce(0, +) { // 완호보다 점수 높은 사람이 있다면 등수 갱신
                ans += 1
            }
        }
    }
    
    return ans
}