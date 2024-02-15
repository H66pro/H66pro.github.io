package main

import "fmt"

type user struct {
	name     string
	password string
}

func main() {
	a := user{name: "han", password: "1234"}
	b := user{"han", "1234"}
	c := user{name: "han"}
	var d user
	d.name = "han"
	d.password = "1234"

	fmt.Println(a, b, c, d)
	fmt.Println(checkPassword(a, "1234"))
	fmt.Println(checkPassword2(&a, "1234"))
}

func checkPassword(u user, password string) bool {
	return u.password == password
}

func checkPassword2(u *user, password string) bool {
	return u.password == password
}
