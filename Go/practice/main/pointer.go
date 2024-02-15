package main

import "fmt"

func add3(n int) {
	n += 2
}

func add3prt(n *int) {
	*n += 2
}

func main() {
	n := 5
	add3(n)
	fmt.Println(n)
	add3prt(&n)
	fmt.Println(n)
}
