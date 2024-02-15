package com.dch66app.helloworld

fun main() {
    printParams(str = "Lily")
}

fun printParams(num: Int = 6, str: String) {
    println("$str is $num")
}