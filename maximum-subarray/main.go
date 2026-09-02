package main

func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxSum := nums[0]
	currentSum := nums[0]

	for i := 1; i < len(nums); i++ {
		currentSum = Max(nums[i], currentSum+nums[i])
		maxSum = Max(maxSum, currentSum)
	}

	return maxSum
}

func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func main() {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	result := maxSubArray(nums)
	println(result) // Output: 6
}
