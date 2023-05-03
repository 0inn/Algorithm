import Foundation

func timeStringToInt(_ time: String) -> Int {
    let t = time
    let tArr = t.split(separator: ":").map { Int($0)! }
    return tArr[0] * 60 + tArr[1]
}

func solution(_ plan:[[String]]) -> [String] {
    var plans = plan.sorted { // 시간 오름차순 정렬
        timeStringToInt($0[1]) < timeStringToInt($1[1])
    }
    var stack: [(String, Int)] = []
    var ans: [String] = []
    var lastTime: Int = 0
    
    for i in 1..<plans.count {
        let diff = timeStringToInt(plans[i][1]) - timeStringToInt(plans[i-1][1])
        let time = diff - Int(plans[i-1][2])!
        lastTime = 0
        
        if time < 0 { // 과제를 전부 끝낼 수 없는 경우
            stack.append((plans[i-1][0], abs(time)))
        } else { // 과제를 끝낼 수 있는 경우
            ans.append(plans[i-1][0])
            lastTime = time
        }
        
        while lastTime > 0 && !stack.isEmpty {
            var (name, time) = stack.popLast()!
            if lastTime >= time {
                lastTime -= time
                ans.append(name)
            } else {
                time -= lastTime
                lastTime = 0
                stack.append((name, time))
            }
        }
    }
    
    ans.append(plans.last![0])
    while !stack.isEmpty {
        ans.append(stack.popLast()!.0)
    }
    
    return ans
}