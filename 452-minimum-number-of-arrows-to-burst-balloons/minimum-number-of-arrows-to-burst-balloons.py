class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        #Find the overlapping intervals
        points.sort()
        initialx = points[0][0]
        initialy = points[0][1]
        arrows = 1
        for i in range(1, len(points)):
            if initialx <= points[i][0] <= initialy or initialx <= points[i][1] <= initialy:
                initialx = min(initialx, points[i][0])
                initialy = min(initialy, points[i][1])
            
            else:
                initialx = points[i][0]
                initialy = points[i][1]
                arrows += 1

        return arrows


