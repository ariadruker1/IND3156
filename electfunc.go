package main

import "fmt"

func vote(x int) int {
	fmt.Println("you have voted for:")
	var CatherineEvans = 1
	var RaymondLouie = 2
	var HeatherDeal = 4
	if x == CatherineEvans {
		fmt.Println("Catherine Evans VISION")
	}
	if x == RaymondLouie {
		fmt.Println("Raymond Louie Wong VISION")
	}
	if x == RaymondLouie+CatherineEvans {
		fmt.Println("Catherine Evans and  Raymond Louie VISION")
	}
	if x == HeatherDeal {
		fmt.Println("Heather Deal VISION")
	}
	if x == HeatherDeal+CatherineEvans {
		fmt.Println("Heather Deal and Christine Evans VISION")
	}
	if x == HeatherDeal+RaymondLouie {
		fmt.Println("Heather Deal and Raymond Louie VISION")
	}
	if x == HeatherDeal+CatherineEvans+RaymondLouie {
		fmt.Println("Heather Deal, Catherine Evans and Raymond Louie VISION")
	}

	return x
}
func main() {
	vote(7)
}
