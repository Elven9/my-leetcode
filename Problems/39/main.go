package main

import "fmt"

func main() {

	combinationSum := combinationSum_recursive

	fmt.Println(combinationSum([]int{2, 3, 6, 7}, 7))
	fmt.Println(combinationSum([]int{2, 3, 5}, 8))
	fmt.Println(combinationSum([]int{2}, 1))
}

func combinationSum_recursive(candidates []int, target int) [][]int {
	result := make([][]int, 0)

	combinationSum_recu_impl(candidates, target, 0, []int{}, &result)

	return result
}

func combinationSum_recu_impl(candidates []int, target int, candIdx int, curRes []int, result *[][]int) {
	if target == 0 {
		*result = append(*result, curRes)
		return
	}

	for i := candIdx; i < len(candidates); i++ {
		if target-candidates[i] >= 0 {
			tmp := make([]int, len(curRes))
			copy(tmp, curRes)
			tmp = append(tmp, candidates[i])
			combinationSum_recu_impl(candidates, target-candidates[i], i, tmp, result)
		}
	}
}
