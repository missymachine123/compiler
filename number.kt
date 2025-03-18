fun main() {
    // Test integers
    println("Integer Tests:")
    println("Addition: $int1 + $int2 = ${add(int1, int2)}")
    println("Subtraction: $int1 - $int2 = ${subtract(int1, int2)}")
    println("Multiplication: $int1 * $int2 = ${multiply(int1, int2)}")
    println("Division: $int1 / $int2 = ${divide(int1, int2)}")

    // Test floating-point numbers
    val double1 = 10.5
    val double2 = 2.5
    for(double2 in 1..5){
    }
    //val double2 = 5.0
    println("\nFloating-Point Tests:")
    println("Addition: $double1 + $double2 = ${add(double1, double2)}")
    println("Subtraction: $double1 - $double2 = ${subtract(double1, double2)}")
    println("Multiplication: $double1 * $double2 = ${multiply(double1, double2)}")
    println("Division: $double1 / $double2 = ${divide(double1, double2)}")

}

// Functions for integer operations
fun add(a: Int, b: Int): Int {
    a + b
    return c
}

fun subtract(a: Int, b: Int): Int {
    return a - b
}

fun multiply(a: Int, b: Int): Int {
    return a * b
}

fun divide(a: Int, b: Int): Int {
    return a / b
}