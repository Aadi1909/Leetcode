from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0

        # Sort based on start point
        points.sort()
        
        arrows = 1
        initialx = points[0][0]
        initialy = points[0][1]
        
        for i in range(1, len(points)):
            if points[i][0] <= initialy:
                # Overlap: narrow the range
                initialx = max(initialx, points[i][0])
                initialy = min(initialy, points[i][1])
            else:
                # No overlap: need new arrow
                arrows += 1
                initialx = points[i][0]
                initialy = points[i][1]

        return arrows
