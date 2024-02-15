package main

import "fmt"

type user2 struct {
	name     string
	password string
}

func (u user2) checkPassword(password string) bool {
	return u.password == password
}

func (u *user2) resetPassword(password string) {
	u.password = password
}

func main() {
	a := user2{"han", "1234"}
	a.resetPassword("1111")
	fmt.Println(a.checkPassword("1111"))
}
