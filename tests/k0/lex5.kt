fun getWeatherAdvice(weather: String): String {
    return when (weather) {
        "sunny" -> "Wear sunglasses and sunscreen."
        "rainy" -> "Carry an umbrella."
        "windy" -> "Hold onto your hat!"
        "snowy" -> "Dress warmly and watch for icy roads."
        else -> "Check the weather again!"
    }
}

fun main() {
    val advice = getWeatherAdvice("rainy")
    println(advice) // Output: Carry an umbrella.
}