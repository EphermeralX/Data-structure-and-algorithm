from typing import List
import itertools

def counting_sort(a: List[int]):
    if len(a) <= 1: return
    
    counts = [0] * (max(a) + 1)
    for num in a:
        counts[num] += 1
    counts = list(itertools.accumulate(counts))

    a_sorted = [0] * len(a)
    for num in reversed(a):
        index = counts[num] - 1
        a_sorted[index] = num
        counts[num] -= 1
    
    a[:] = a_sorted


if __name__ == "__main__":
    a1 = [1, 2, 3, 4]
    counting_sort(a1)
    print(a1)

    a2 = [1, 1, 1, 1]
    counting_sort(a2)
    print(a2)

    a3 = [4, 5, 0, 9, 3, 3, 1, 9, 8, 7]
    counting_sort(a3)
    print(a3)