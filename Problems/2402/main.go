package main

import (
	"container/heap"
	"fmt"
	"sort"

	"github.com/Elven9/my-leetcode/ds"
)

func main() {
	testcases := []struct {
		n        int
		meetings [][]int
	}{
		{
			2,
			[][]int{{0, 10}, {1, 5}, {2, 7}, {3, 4}},
		},
		{
			3,
			[][]int{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}},
		},
		{
			2,
			[][]int{{0, 10}, {1, 2}, {12, 14}, {13, 15}},
		},
		{
			3,
			[][]int{{3, 7}, {12, 19}, {16, 17}, {1, 17}, {5, 6}},
		},
	}

	for i, t := range testcases {
		fmt.Println("Testcase", i, "result:", mostBooked(t.n, t.meetings))
	}
}

type meeting struct {
	End  int
	Room int
}

type revokeQueue []meeting

func (h revokeQueue) Len() int { return len(h) }
func (h revokeQueue) Less(i, j int) bool {
	if h[i].End == h[j].End {
		return h[i].Room < h[j].Room
	}
	return h[i].End < h[j].End
}
func (h revokeQueue) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *revokeQueue) Push(x any)   { *h = append(*h, x.(meeting)) }
func (h *revokeQueue) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func mostBooked(n int, meetings [][]int) int {
	// Solution:
	//
	// - sort meetings start first
	// - one min heap to record latest revokable meeting
	// - one array to record meeting rooms usage count
	// - one min heap to record lowest empty room
	//
	// Time Complexity: O(nlogn), Space Complexity: O(k)

	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i][0] < meetings[j][0]
	})

	revokeQ := &revokeQueue{}
	roomUsageCount := make([]int, n)

	// Init empty room
	emptyRoom := &ds.MinHeap{}
	for i := 0; i < n; i++ {
		emptyRoom.Push(i)
	}
	heap.Init(emptyRoom)

	// Processing Task
	for i := 0; i < len(meetings); i++ {
		task := meetings[i]
		// Clean finished meeting
		for revokeQ.Len() != 0 && (*revokeQ)[0].End <= task[0] {
			m := heap.Pop(revokeQ)
			heap.Push(emptyRoom, m.(meeting).Room)
		}
		if emptyRoom.Len() == 0 {
			// Process Delay Meetings
			duration := task[1] - task[0]
			(*revokeQ)[0].End += duration
			roomUsageCount[(*revokeQ)[0].Room]++
			heap.Fix(revokeQ, 0)
		} else {
			newMeeting := meeting{
				End:  task[1],
				Room: heap.Pop(emptyRoom).(int),
			}
			roomUsageCount[newMeeting.Room]++
			heap.Push(revokeQ, newMeeting)
		}
	}

	// Generate Result
	res, mostMeetings := 0, -1
	for i, usage := range roomUsageCount {
		if usage > mostMeetings {
			mostMeetings = usage
			res = i
		}
	}

	return res
}
