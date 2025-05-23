fun fib(n : Int) : Int {
 var m : Int = 0;
 if (n < 2) {
    return 1;
    }
	 m = fib(n-1);
	 m = m + 1;
	 return m;
}

fun main() {
  var i : Int = 5;
  i = fib(i);
}