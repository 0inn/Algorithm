import Foundation

func permutation(_ arr: [Int], _ n: Int) -> [[Int]] {
    var result: [[Int]] = []
    var visit = Array(repeating: false, count: arr.count)
    
    func cycle(_ now: [Int]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in 0..<arr.count {
            if visit[i] { continue }
            visit[i] = true
            cycle(now + [arr[i]])
            visit[i] = false
        }
    }
    
    cycle([])
    
    return result
}

func solution(_ n:Int, _ weak:[Int], _ dist:[Int]) -> Int {
    var weaks = weak
    var dists = dist.sorted { $0 > $1 } // 최소 인원을 구하기 위해 내림차순 정렬
    var distLen = dists.count
    var ans = distLen + 1
    
    // 원형을 처리하기 위해 배열을 2배로 늘리기
    for i in 0..<weak.count-1 {
        weaks.append(n + weak[i])
    }
    
    var cnt = 0
    var cur = 0
    
    for start in weak.indices {
        // 친구를 투입할 수 있는 경우의 수 순열로 구하기
        for people in permutation(dists, distLen) {
            cnt = 1 // 친구 한 명 추가
            cur = weaks[start] + people[cnt-1] // 한 명이 점검할 수 있는 위치
            
            // 취약 지점 어디까지 점검할 수 있는지 탐색
            for idx in start+1..<start+weak.count {
                // 아직 탐색할 수 없는 취약 지점이 존재한다면
                if cur < weaks[idx] {
                    cnt += 1 // 친구 한 명 더 추가
                    if cnt > distLen { break } // 친구 전부 투입한 경우 끝냄
                    
                    cur = weaks[idx] + people[cnt-1] // 한 명 더 추가한 상황에서 점검할 수 있는 위치
                }
            }
            
            // 최소 인원 구하기 위해 정답 갱신
            ans = min(ans, cnt)
        }
    }
    
    // 만약 친구 전부 투입해도 취약 지점 점검할 수 없다면 -1 출력
    return ans > distLen ? -1 : ans
}