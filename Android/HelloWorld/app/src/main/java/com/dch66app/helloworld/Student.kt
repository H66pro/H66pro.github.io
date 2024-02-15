package com.dch66app.helloworld

class Student(name: String, age: Int, sex: String) : Person(name, age, sex), Study {
    override fun readBooks() {
        println("$name is reading.")
    }

    override fun doHomework() {
        println("$name is doing homework.")
    }


}

//class Student : Person {
//    constructor(name: String, age:Int, sex: String) : super(name, age, sex) {
//
//    }
//}