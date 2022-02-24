from collections import Counter
def findTheDifference( s: str, t: str) -> str:
    freq = Counter(s)
    freq2 = Counter(t)
    for k, v in freq2.items():
        if k in freq and freq[k] != v:
            return k
        elif k not in freq:
            return k


print(findTheDifference("abcd", "abcde"))