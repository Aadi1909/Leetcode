class Solution(object):
    def checkValid(self, matrix):
        n = len(matrix)
        for row in matrix:
            row_xor = 0
            for num in row:
                if num < 1 or num > n:
                    return False 
                row_xor ^= (1 << (num - 1))
            if row_xor != (1 << n) - 1:
                return False
            
        for j in range(n):
            col_xor = 0
            for i in range(n):
                num = matrix[i][j]
                if num < 1 or num > n:
                    return False
                col_xor ^= (1 << (num - 1))
            if col_xor != (1 << n) - 1:
                return False

        return True
