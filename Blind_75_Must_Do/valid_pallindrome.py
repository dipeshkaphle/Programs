class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ''.join(map(lambda x: x.lower() if x.isalpha() else x, filter(lambda x: x.isalnum(),list(s))))
        print(st)
        return st==st[::-1]
