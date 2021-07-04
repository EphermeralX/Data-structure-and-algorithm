package stack

import "fmt"

type node struct {
	next *node
	val  interface{}
}

type LinkedListStack struct {
	topNode *node
}

func NewLinkedListStack() *LinkedListStack {
	return &LinkedListStack{nil}
}

func (a *LinkedListStack) IsEmpty() bool {
	return a.topNode == nil
}

func (a *LinkedListStack) Push(v interface{}) {
	a.topNode = &node{next: a.topNode, val: v}
}

func (a *LinkedListStack) Pop() interface{} {
	if a.IsEmpty() {
		return nil
	}
	v := a.topNode.val
	a.topNode = a.topNode.next
	return v
}

func (a *LinkedListStack) Top() interface{} {
	if a.IsEmpty() {
		return nil
	}
	return a.topNode.val
}

func (a *LinkedListStack) Flush() {
	a.topNode = nil
}

func (a *LinkedListStack) Print() {
	if a.IsEmpty() {
		fmt.Println("empty stack")
	} else {
		cur := a.topNode
		for nil != cur {
			fmt.Println(cur.val)
			cur = cur.next
		}
	}
}
