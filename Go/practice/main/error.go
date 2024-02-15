package main

import (
	"errors"
	"fmt"
)

type user struct {
	name     string
	password string
}

func findUser(users []user, name string) (v *user, err error) {
	for _, u := range users {
		if u.name == name {
			return &u, nil
		}
	}
	return nil, errors.New("not found")
}

func main() {
	u, err := findUser([]user{{"han", "1234"}, {"li", "1111"}}, "li1")
	if err != nil {
		fmt.Println(err)
		return // 结束程序
	}
	fmt.Println(u.name)

	if u, err := findUser([]user{{"han", "1234"}}, "li"); err != nil {
		fmt.Println(err)
		return
	} else {
		fmt.Println(u.name)
	}
}
