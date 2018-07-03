package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	argsWithProg := os.Args
	argsWithoutProg := strconv.Atoi(os.Args[1])
	arg := os.Args[3]
	fmt.Println(argsWithProg)
	fmt.Println(argsWithoutProg)
	fmt.Println(arg)

}
