package main

func main() {

}

func generate(numRows int) [][]int {
	res := make([][]int, 0)

	// Generate The List
	res = append(res, []int{1})
	for row := 2; row <= numRows; row++ {
		tmp := make([]int, 0)
		tmp = append(tmp, 1)
		for cen := 1; cen < row-1; cen++ {
			tmp = append(tmp, res[row-2][cen-1]+res[row-2][cen])
		}
		tmp = append(tmp, 1)
		res = append(res, tmp)
	}

	return res
}
