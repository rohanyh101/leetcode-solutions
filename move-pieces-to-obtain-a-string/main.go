package main

func canChange(start string, target string) bool {
	n := len(start)
	i, j := 0, 0

	for i < n || j < n {
		for i < n && start[i] == '-' {
			i++
		}

		for j < n && target[j] == '-' {
			j++
		}

		if i == n && j == n {
			return true
		}

		if i == n || j == n {
			return false
		}

		if start[i] != target[j] {
			return false
		}

		if start[i] == 'L' && i < j {
			return false
		}

		if start[i] == 'R' && i > j {
			return false
		}

		i++
		j++
	}

	return true
}

func main() {
	// Test cases
	testCases := []struct {
		start  string
		target string
	}{
		{"R_L_", "__LR"},
		{"_L__R__R_", "L______RR"},
		{"_R", "R_"},
		{"L_R_", "_LR_"},
		{"_L__R__R_", "L______RR"},
		{"R_L_", "__LR"},
		{"_R", "R_"},
		{"L_R_", "_LR_"},
	}

	for _, tc := range testCases {
		println(canChange(tc.start, tc.target))
	}
}
