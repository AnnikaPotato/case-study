class Solution:
    def __init__(self, EU: list[list], pnum:int, anum:int) -> None:
        self.EU = EU
        self.count = [0] * pnum
        self.totalcount = 0
        self.pnum = pnum
        self.anum = anum
        self.weights = [0] * pnum
        pass

    def backtrack(self, ptr: int, remains: int):
        if ptr == self.anum - 1:
            self.totalcount += 1
            t1 = 0
            t2 = 0
            for i in range(self.pnum):
                self.weights[i] += remains * self.EU[ptr][i]
                if self.weights[i] > t1:
                    t1, t2 = self.weights[i], t1

                elif self.weights[i] > t2:
                    t2 = self.weights[i]

            for i in range(self.pnum):
                if self.weights[i] >= t2:
                    self.count[i] += 1

            for i in range(self.pnum):
                self.weights[i] -= remains * EU[ptr][i]
            return
        
        else:
            for i in range(0, remains + 1, 2):
                for j in range(self.pnum):
                    self.weights[j] += i * EU[ptr][j]
                
                self.backtrack(ptr + 1, remains - i)
                
                for j in range(self.pnum):
                    self.weights[j] -= i * EU[ptr][j]
            return
EU = [
[96, 0, 100, 97, 22],
[100, 73, 100, 100, 0],
[82, 100, 7, 45, 100],
[83, 100, 83, 100, 68],
[100, 0, 50, 100, 50],
[67, 50, 83, 67, 87]
]

currObj = Solution(EU, 5, 6)
currObj.backtrack(0, 100)
print("The number of times that P1, P2, P3, P4, and P5 becomes one of top two")
print(currObj.count)
print('\nTotal tested times')
print(currObj.totalcount)