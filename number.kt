fun main() {
    // Test integers
    val int1 = 10
    val int2 = 5

    println("Integer Tests:")
    println("Addition: $int1 + $int2 = ${add(int1, int2)}")
    println("Subtraction: $int1 - $int2 = ${subtract(int1, int2)}")
    println("Multiplication: $int1 * $int2 = ${multiply(int1, int2)}")
    println("Division: $int1 / $int2 = ${divide(int1, int2)}")

    // Test floating-point numbers
    val double1 = 10.5
    val double2 = 2.5

    println("\nFloating-Point Tests:")
    println("Addition: $double1 + $double2 = ${add(double1, double2)}")
    println("Subtraction: $double1 - $double2 = ${subtract(double1, double2)}")
    println("Multiplication: $double1 * $double2 = ${multiply(double1, double2)}")
    println("Division: $double1 / $double2 = ${divide(double1, double2)}")
}

// Functions for integer operations
fun add(a: Int, b: Int): Int {
    return a + b
}

fun subtract(a: Int, b: Int): Int {
    return a - b
}

fun multiply(a: Int, b: Int): Int {
    return a * b
}

fun divide(a: Int, b: Int): Int {
    if (b == 0) throw IllegalArgumentException("Division by zero is not allowed")
    return a / b
}

// Functions for floating-point operations
fun add(a: Double, b: Double): Double {
    return a + b
}

fun subtract(a: Double, b: Double): Double {
    return a - b
}

fun multiply(a: Double, b: Double): Double {
    return a * b
}

fun divide(a: Double, b: Double): Double {
    if (b == 0.0) throw IllegalArgumentException("Division by zero is not allowed")
    return a / b
}
