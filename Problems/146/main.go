package main

func main() {

}

type MYListNode struct {
	Val  int
	Key  int
	Next *MYListNode
	Prev *MYListNode
}

type LRUCache struct {
	Cap    int
	Size   int
	QHead  *MYListNode
	QTail  *MYListNode
	Htable map[int]*MYListNode
}

func Constructor(capacity int) LRUCache {
	// Solution 1:
	// An hash table for O(1) get
	// -> Array
	// -> map datastructure provided by golang
	// A linked list for O(1) put
	head := &MYListNode{
		Val: -1,
	}
	tail := &MYListNode{
		Val:  -1,
		Prev: head,
	}
	head.Next = tail

	return LRUCache{
		Cap:    capacity,
		Size:   0,
		QHead:  head,
		QTail:  tail,
		Htable: make(map[int]*MYListNode),
	}
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.Htable[key]; ok && v != nil {
		// Update Queue
		v.Prev.Next, v.Next.Prev = v.Next, v.Prev

		v.Next, v.Prev = this.QHead.Next, this.QHead
		this.QHead.Next, v.Next.Prev = v, v

		return v.Val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if v, ok := this.Htable[key]; ok && v != nil {
		v.Val = value
		// Update Queue
		v.Prev.Next, v.Next.Prev = v.Next, v.Prev

		v.Next, v.Prev = this.QHead.Next, this.QHead
		this.QHead.Next, v.Next.Prev = v, v
		return
	}
	if this.Size == this.Cap {
		// Delete Target
		dtar := this.QTail.Prev
		dtar.Prev.Next, dtar.Next.Prev = dtar.Next, dtar.Prev
		this.Htable[dtar.Key] = nil
		this.Size--
	}
	// Add New Node
	newNode := &MYListNode{
		Val:  value,
		Key:  key,
		Next: this.QHead.Next,
		Prev: this.QHead,
	}
	this.QHead.Next.Prev = newNode
	this.QHead.Next = newNode
	this.Htable[key] = newNode
	this.Size++
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
