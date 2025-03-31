//Calling a Function with Incorrect Arguments
fun add(a: Int, b: Int): Int {
    return a + b
}

fun main() {
    val result = add("5", 10) 
    println(result)
}