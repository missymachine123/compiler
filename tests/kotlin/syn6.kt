fun main() {
    try {
        checkValue(-1)  // Should throw an exception
    } catch (e: Exception) {
        println("Caught exception: ${e.message}")
    }
}