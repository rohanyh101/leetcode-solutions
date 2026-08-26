package main

func minAreaRect(points [][]int) int {
	pointMap := make(map[int]map[int]bool)
	for _, point := range points {
		x, y := point[0], point[1]
		if _, exists := pointMap[x]; !exists {
			pointMap[x] = make(map[int]bool)
		}
		pointMap[x][y] = true
	}

	minArea := int(^uint(0) >> 1) // Initialize to maximum integer value

	for i := 0; i < len(points); i++ {
		for j := i + 1; j < len(points); j++ {
			x1, y1 := points[i][0], points[i][1]
			x2, y2 := points[j][0], points[j][1]

			if x1 != x2 && y1 != y2 {
				if pointMap[x1][y2] && pointMap[x2][y1] {
					area := abs(x2-x1) * abs(y2-y1)
					if area < minArea {
						minArea = area
					}
				}
			}
		}
	}

	if minArea == int(^uint(0)>>1) {
		return 0
	}

	return minArea
}

func abs(value int) int {
	if value < 0 {
		return -value
	}
	return value
}

func main() {
	points := [][]int{{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}}
	minAreaRect(points)
}
