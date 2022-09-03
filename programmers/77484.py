## 로또의 최고 순위와 최저 순위

def solution(lottos, win_nums):
    unknown_count = 0
    hit_count = 0
    
    for lotto in lottos:
        if lotto == 0:
            unknown_count += 1
            continue
        
        if lotto in win_nums:
            hit_count += 1

    max_rank = 7 - (hit_count + unknown_count) if hit_count + unknown_count > 1 else 6
    min_rank = 7 - hit_count if hit_count > 1 else 6
    
    return [max_rank, min_rank]