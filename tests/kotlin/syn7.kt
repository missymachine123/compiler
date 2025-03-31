object Singleton {
    val name = "Singleton Object"
    fun greet() = println("Hello from $name")
}

fun main() {
    Singleton.greet()
}