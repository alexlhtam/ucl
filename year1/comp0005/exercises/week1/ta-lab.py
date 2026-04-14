'''
Given an array of integer numbers that represent the values of each coin, 
and given a target amount, 
determine the minimum number of coins needed to create this amount. 
At first, try to solve this problem with regular coins (i.e., 1,5,10,20,50),
then try with different irregular coin values (e.g., 1,7,12, 38).

Example 1
Given coin values (1, 2, 5,10,20,50), with 
Target amount = 7; solution = 2 coins (5,2)
Target amount = 150; solution = 3 coins (50,50,50)
Target amount = 28; solution = 4 coins (20,5,2,1)
 
Example 2
Given coin values (1,4,6), with:
Target amount = 7; solution = 2 coins (6,1)
Target amount = 9; solution = 3 coins (4,4,1)
 
Only the number of coins is required, the coins used are not important for this exercise.

Hint
Which amounts require the fewest coins?
'''

class CoinCounter:
    def __init__(self, coin_values=None):
        if not coin_values:
            self.values = [50, 20, 10, 5, 2, 1]
        else:
            self.values = sorted(coin_values, reverse = True)

    
    def greedy_calc(self, target):
        total = 0
        for c in self.values:
            total += target // c
            target %= c
        return total

    def greedy_test(self):
        return self.greedy_calc(7) == 2 and self.greedy_calc(150) == 3 and self.greedy_calc(28) == 4


    def dp_calc(self, target):
        dp = [float('inf')] * (target + 1) 
        dp[0] = 0
        
        for amount in range(1, target + 1):
            for coin in self.values:
                if (amount - coin) >= 0:
                    dp[amount] = min(dp[amount-coin] + 1, dp[amount])


'''
Given an integer number n, 
write two functions (one recursively and another iteratively) that output the nth Fibonacci number. 
A Fibonacci sequence is a series of numbers which starts from 0 and 1 and continues with each number (Fibonacci number) being the sum of the two preceding numbers. 
What’s the difference in space complexity between the iterative and recursive method? '''

def r_fib(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return r_fib(n-1) + r_fib(n-2)

def i_fib(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        nums = [0, 1]
        while len(nums) < n:
            nums.append(nums[-1] + nums[-2])

        return nums[-1]

'''
Write an algorithm to check whether, given an input sequence of characters, 
the sequence contains balanced parenthesis. 

For example:
 
((x*2)+(x-2)) – a[3] / a[10] is balanced
(((x*2)+(x-2)) – a[3] / a[10] is not balanced

Hint
Use a stack to keep track of relevant information.
'''

def check_paren(s):
    valid_chars = ["(", ")", "[", "]"]
    dict = {}
    for c in valid_chars:
        dict[c] = 0

    for c in s:
        if c in valid_chars:
            dict[c] += 1


    print(dict)

    return dict["("] == dict[")"] and dict["["] == dict["]"]
     
def check_ordered_parens(s):
    pairs = {
        ")": "(",
        "]": "["
    }
    
    stack = []

    for c in s:
        if c in pairs.values():
            stack.append(c)
        elif c in pairs:
            if not stack or stack.pop() != pairs[c]:
                return False

    return len(stack) == 0



if __name__ == "__main__":
    # c = CoinCounter()
    # print(c.greedy_test())

    # print(r_fib(10))

    # print(i_fib(10))

    # print(check_ordered_parens("((x*2)+(x-2)) – a[3] / a[10] "))

    # print(check_ordered_parens("(((x*2)+(x-2)) – a[3] / a[10] "))

    pass
