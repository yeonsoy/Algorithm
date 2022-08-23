## 폰켓몬

def solution(nums):
    answer = 0
    numbers = {}
    for num in nums:
        if numbers.get(num, None):
            numbers[num] += 1
        else:
            numbers[num] = 1
            
    answer = len(numbers) if len(numbers) <= len(nums) / 2 else len(nums) / 2
    
    return answer