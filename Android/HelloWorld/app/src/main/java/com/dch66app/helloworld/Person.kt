package com.dch66app.helloworld

open class Person(val name: String, val age: Int, val sex: String) {

    fun eat() {
        when (sex) {
            "boy" -> println("$name is eating. He is $age years old.")
            "girl" -> println("$name is eating. She is $age years old.")
            else -> println("404 Not Found.")
        }
    }
}