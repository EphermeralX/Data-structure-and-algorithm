package sort

import (
	"fmt"
	"testing"
)

func TestBubbleSort(t *testing.T) {
	arr := []int{1, 5, 9, 6, 3, 7, 5, 10}
	fmt.Println("Before sort：", arr)
	BubbleSort(arr, len(arr))
	fmt.Println("After sort：", arr)
}

func TestInsertionSort(t *testing.T) {
	arr := []int{1, 5, 9, 6, 3, 7, 5, 10}
	fmt.Println("Before sort：", arr)
	InsertionSort(arr, len(arr))
	fmt.Println("After sort：", arr)
}

func TestSelectionSort(t *testing.T) {
	arr := []int{1, 5, 9, 6, 3, 7, 5, 10}
	fmt.Println("Before sort：", arr)
	SelectionSort(arr, len(arr))
	fmt.Println("After sort：", arr)
}
