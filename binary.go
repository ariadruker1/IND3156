package main

import "fmt"

func main() {
	var x uint = 8
	var me uint = 0
	fmt.Println(x)
	fmt.Println(me)
	x = x & me
	fmt.Println(x)
	fmt.Println(me)
}
