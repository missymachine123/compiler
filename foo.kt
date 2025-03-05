fun main() {
   // Test 1: Empty Square Brackets with Newlines
   val emptyListWithNewlines = []
   println("Test 1: Empty Square Brackets with Newlines -> $emptyListWithNewlines") // Output: []

   // Test 2: Single Element with Newlines
   val singleElementWithNewlines = [
       42
   ]
   println("Test 2: Single Element with Newlines -> $singleElementWithNewlines") // Output: [42]

   // Test 3: Multiple Elements with Newlines
   val multipleElementsWithNewlines = [1,2]
   println("Test 3: Multiple Elements with Newlines -> $multipleElementsWithNewlines") // Output: [1, 2, 3]

   // Test 4: Collection with Expressions and Newlines
   val collectionWithExpressionsAndNewlines = [
       1 + 1,
       2 * 2,
       3 / 3,
   ]
   println("Test 4: Collection with Expressions and Newlines -> $collectionWithExpressionsAndNewlines") // Output: [2, 4, 1]
}
