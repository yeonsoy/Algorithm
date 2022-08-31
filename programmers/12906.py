## 같은 숫자는 싫어

def solution(arr):
    answer = []
    for el in arr:
        if len(answer) == 0:
            answer.append(el)
        else:
            if answer[-1] == el:
                continue
            else:
                answer.append(el)
    return answer