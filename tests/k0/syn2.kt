//if-else, when
fun main() {
    val x = 20
        val y = 18
    if (x > y) {
    println("x is greater than y")
    }
    
    val num = 10
    if (num > 0) {
        println("Positive number")
    } else {
        println("Negative number")
    }

    val max = if (a > b) a else b

        val day = 2
        val dayName = when (day) {
        1 -> "Monday"
        2 -> "Tuesday"
        3 -> "Wednesday"
        else -> "Invalid day"
    }
    println(dayName)
 }