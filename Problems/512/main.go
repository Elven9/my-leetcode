package main

import (
	"fmt"
)

func main() {

	maxProduct := maxProduct_dp

	fmt.Println(maxProduct([]int{2, 3, -2, 4}))
	fmt.Println(maxProduct([]int{-2, 0, -1}))
	fmt.Println(maxProduct([]int{-2, 3, -4}))
	fmt.Println(maxProduct([]int{7, -2, -4}))
}

func maxProduct(nums []int) int {
	// 0 will be an corner case, when we encounter 0, we should reset the count
	result := nums[0]
	lMax := 1
	lMin := 1

	for _, n := range nums {
		if n == 0 {
			if 0 > result {
				result = 0
			}
			lMax = 1
			lMin = 1
		} else if n > 0 {
			if lMax*n > result {
				result = lMax * n
			}
			lMax *= n
			lMin *= n
		} else {
			// Negative
			if lMin*n > result {
				result = lMin * n
			}
			tmp := lMax
			lMax = lMin * n
			if 1 > lMax {
				lMax = 1
			}
			lMin = tmp * n
		}
	}

	return result
}

func maxProduct_dp(nums []int) int {
	result := nums[0]
	pMax := nums[0]
	pMin := nums[0]

	for idx, n := range nums {
		if idx == 0 {
			continue
		}
		tmpMin := pMax * n
		if pMin*n < tmpMin {
			tmpMin = pMin * n
		}
		if n < tmpMin {
			tmpMin = n
		}

		tmpMax := pMax * n
		if pMin*n > tmpMax {
			tmpMax = pMin * n
		}
		if n > tmpMax {
			tmpMax = n
		}

		if tmpMax > result {
			result = tmpMax
		}
		pMax = tmpMax
		pMin = tmpMin
	}

	return result
}
