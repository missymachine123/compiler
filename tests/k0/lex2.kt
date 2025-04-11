fun main() {
    var longValue1: Long = 9223372036854775807L
    val longValue2: Long = 9222372036854775807L

    val greatestValue = max(longValue1, longValue2)
    println("The greater value is: $greatestValue")
}