fun main() {
    val a = 10
    val b = 20

    // Using Relational and Equality Operators in if-else
    if (a < b) {
        println("a is less than b")
    } else if (a > b) {
        println("a is greater than b")
    }

    if (a <= b) {
        println("a is less than or equal to b")
    } else if (a >= b) {
        println("a is greater than or equal to b")
    }

    if (a != b) {
        println("a is not equal to b")
    } else if (a == b) {
        println("a is equal to b")
    }

    if (a === b) { // Reference equality
        println("a and b refer to the same object")
    } else if (a !== b) { // Reference inequality
        println("a and b do not refer to the same object")
    }

    // Time-based test with if-else
    val time = 22
    if (time < 10) {
        println("Good morning.")
    } else if (time < 20) {
        println("Good day.")
    } else {
        println("Good evening.")
    }
}
