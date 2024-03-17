package main

import (
	"fmt"
	"math"
)

func main() {
	testcases := []struct {
		intervals   [][]int
		newInterval []int
	}{
		// {
		// 	[][]int{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
		// 	[]int{4, 8},
		// },
		{
			[][]int{{1, 5}},
			[]int{0, 6},
		},
	}

	for _, tc := range testcases {
		fmt.Println(insert(tc.intervals, tc.newInterval))
	}
}

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}
	if newInterval[1] < intervals[0][0] {
		return append([][]int{newInterval}, intervals...)
	}
	merge := func(a, b []int) []int {
		// return []int{min(a[0], b[0]), max(a[1], b[1])} May be faster ?
		return []int{int(math.Min(float64(a[0]), float64(b[0]))), int(math.Max(float64(a[1]), float64(b[1])))}
	}

	res := make([][]int, 0, len(intervals))
	for idx, i := range intervals {
		// 反正只要不是全在右邊 or 全在左邊，就是有 overlap 了 (*´･д･)?
		if newInterval[1] < i[0] {
			res = append(res, newInterval)
			return append(res, intervals[idx:]...)
		}
		if newInterval[0] > i[1] {
			res = append(res, i)
		} else {
			newInterval = merge(newInterval, i)
		}
	}

	return append(res, newInterval)
}

type mergeState int

const (
	notMerge mergeState = iota
	inMerge
	merged
)

func insert_soUgLy(intervals [][]int, newInterval []int) [][]int {
	// Scan intervals and start merge processing if finding overlapping of newInterval
	// Time: O(n), Space: O(n), for storing new intervals by avoiding in-placing
	// updating.
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}

	checkOverlap := func(a, b []int) bool {
		return (a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]) || (a[0] <= b[0] && a[1] >= b[1])
	}

	res := make([][]int, len(intervals))
	ms, me, mergeS := 0, 0, notMerge

	// Before
	if newInterval[1] < intervals[0][0] {
		res = append(res, newInterval)
		mergeS = merged
	}

	// Merge in Intervals
	for idx, i := range intervals {
		switch mergeS {
		case notMerge:
			if checkOverlap(newInterval, i) {
				// Update ms (merge start)
				ms = newInterval[0]
				if i[0] < ms {
					ms = i[0]
				}
				// Update me (merge end)
				me = newInterval[1]
				if i[1] > me {
					me = i[1]
				}
				mergeS = inMerge
			} else if newInterval[1] < i[0] && ((idx > 0 && newInterval[0] > intervals[idx-1][1]) || idx == 0) {
				res = append(res, newInterval, i)
				mergeS = merged
			} else if newInterval[0] > i[1] && ((idx+1 < len(intervals) && newInterval[1] < intervals[idx+1][0]) || idx == len(intervals)) {
				res = append(res, i, newInterval)
				mergeS = merged
			} else {
				res = append(res, i)
			}
		case inMerge:
			if me < i[0] {
				res = append(res, []int{ms, me}, i)
				mergeS = merged
			} else if me <= i[1] {
				res = append(res, []int{ms, i[1]})
				mergeS = merged
			}
		case merged:
			res = append(res, i)
		}
	}
	if mergeS == inMerge {
		res = append(res, []int{ms, me})
	}

	// After Merge
	if mergeS == notMerge {
		res = append(res, newInterval)
	}

	return res
}
