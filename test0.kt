fun main() {
	var test1 : Int = 0
	var test2 : Int = 0
        // infinite loop
	while (true) {
		test1 = test1 + 1
	}

	// While loop with incrementing variable
	test1 = 0
	while (test1 < 10) {
		test1 = test1 + 1
	}

	// While loop with different expression
	test2 = 0
	while (test2 != 1) {
		test2 = 1
	}

	// While loop with function call
	while (random()) {
		println("X")
	}

	// For loop
	for (test1 in 0..20) {
		println("X")
	}
}