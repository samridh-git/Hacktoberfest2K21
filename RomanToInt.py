class Solution:
    def romanToInt(self, s: str) -> int:
        defval = {
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000
    }
        val,last = 0,0
        for x in s[::-1]:
            temp = defval[x]
            if temp >= last:
                val += temp
                last = temp
            else:
                val -= temp
                last = temp 
        return val
