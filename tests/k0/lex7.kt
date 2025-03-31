Ariana
missymachine
Online
Compiler

Ronny — Yesterday at 2:14 PM
glad that memeory leak is not problem
Ariana — Yesterday at 2:14 PM
im glas he was chill about it lol
yeaa
Ronny — Yesterday at 2:14 PM
I know right
hmm, so what's our plan for the next homework? I don't really want it to be piled all in a day or two so
Ariana — Yesterday at 2:15 PM
yeaa same
hm well we have the lab stuff on sunday
Ronny — Yesterday at 2:15 PM
I forgot about that
Ariana — Yesterday at 2:15 PM
so if you guys have time then we could do both
Ronny — Yesterday at 2:15 PM
😭
Ariana — Yesterday at 2:15 PM
well at least this lab is easy lol
its just writing test files
Ronny — Yesterday at 2:15 PM
I don't got much planned beside some other homework and stuff soo
Ariana — Yesterday at 2:16 PM
yea also I would want to work on it during the week too so we can spread out the work more 
Ronny — Yesterday at 2:16 PM
maybe 2 hours for today and then tomorrow on that lab and some ?
@Melissa
Ariana — Yesterday at 2:17 PM
hm what time today because I was going to go to the spring fling thing
Ronny — Yesterday at 2:17 PM
isn't that like 6 ish
Ariana — Yesterday at 2:17 PM
yea
Ronny — Yesterday at 2:18 PM
3-5?
or 3:30
Ariana — Yesterday at 2:19 PM
I would prefer to work on it tomorrow but if everyone is down we can do some today @Melissa 
Melissa — Yesterday at 2:22 PM
I won't be here tomorrow, so I could work on some stuff today, but I think it'd have to be by myself because I have some stuff cooking that's going to take a long time.
Especially if we're just working on the lab stuff today
Ariana — Yesterday at 2:24 PM
yea okay we could just do some labs stuff today individually
we could each write a few test files and then post them here 
Ariana — 8:02 PM
im writing the the test runner script btw when im done ill send the whole folder since it depends on the naming/organization of the files
Ariana — 8:10 PM
heres the lab with the correct directories and the testrunner
Attachment file type: archive
lab8.zip
209.82 KB
this is how I ran the testrunner, lmk if it works for you guys
Image
Ronny — 8:15 PM
sounds good , I will go do it after I finished up eating
Ronny — 9:30 PM
so we can just run this right?
Ariana — 9:33 PM
Yea just cd into tests
And run that command
Ronny — 9:34 PM
----------------------------------
all tests completed. Output saved in /mnt/c/Users/ronny/OneDrive/桌面/lab8/tests/output.log
Ariana — 9:38 PM
Can you check the output.log
Ronny — 9:39 PM
Running test: /mnt/c/Users/ronny/OneDrive/桌面/lab8/tests/k0/helloworld.kt

this filename: /mnt/c/Users/ronny/OneDrive/桌面/lab8/tests/k0/helloworld.kt
Parsing file: /mnt/c/Users/ronny/OneDrive/桌面/lab8/tests/k0/helloworld.kt
yyparse returns 0
No errors.
----------------------------------
Ariana — 9:39 PM
Okay cool
Ronny — 9:39 PM
yeah I can see there's only one
Ariana — 9:39 PM
Yea
When you put more in other files it also works tho
Ronny — 9:39 PM
I'm going to work on this:
Establish Lexical Coverage
Check whether your tests/k0 directory has tests that use every terminal symbol that is legal under k0. If not, construct new tests lex1.kt through lexN.kt until you have a test that uses each terminal symbol. Produce as many lexical error tests as you can think of. At the very least, for each regex that is bounded by beginning and ending characters, you should have tests where the ending characters are missing.
Ariana — 9:40 PM
Just making sure it works for now
Ronny — 9:40 PM
Probably just modify what we had before
Ariana — 9:40 PM
Yea we can add all the files now and it will run them all together
Ronny — 9:40 PM
Sounds good
Ariana — 9:42 PM
Cool I'll do the one after that
Ronny — 10:04 PM
Running test: /mnt/c/Users/ronny/OneDrive/桌面/lab8/tests/k0/tester.kt
Syntax error: syntax error at line 1, near token '...'
what is being runned hmm ,like what command line
Ariana — 10:06 PM
./k0 filename
what file are you using?
Ronny — 10:06 PM
Image
tester, for the syntax
Ariana — 10:07 PM
well our main isnt set for lexical stuff rn
Ronny — 10:07 PM
oh true huh
Ariana — 10:08 PM
yeaa
Ronny — 10:11 PM
I guess we will have to creat test case with correct grammar using those then
Ariana — 10:12 PM
hm
Ronny — 10:48 PM
I'm kind of surprised how many error we got
Ariana — 10:48 PM
wait really 😭
Ronny — 10:49 PM
yeah
Ariana — 10:49 PM
like bad?
Ronny — 10:49 PM
fun main() {
    var name = "John"
    val birthyear = 1975
    println(name)          // Print the value of name
    println(birthyear)     // Print the value of birthyear

    val name = "Kotlin"
    println(name.length) // Accesses the 'length' property of the String object
}
it was having problem with .length)
and this     cars[0] = "Opel"
Ariana — 10:49 PM
hm
Ronny — 10:51 PM
it should work if we are working with array hm
@Melissa
Ronny — 11:06 PM
I think we should support this ?
val cars = arrayOf("Volvo", "BMW", "Ford", "Mazda")
println(cars.size)
// Outputs 4
what else . is for hmm
Ariana — 11:07 PM
if it doesnt say in the kzero then idk
Ronny — 11:08 PM
I meant in general
Ariana — 11:08 PM
wait wym then
Ronny — 11:08 PM
the .
Ariana — 11:08 PM
i though we supported the .
Ronny — 11:08 PM
we do, but I think it might be in grammar
Ariana — 11:09 PM
oh
Ronny — 11:11 PM
println(name.length) // Accesses the 'length' property of the String object
this give error
val greatestValue = max(longValue1, longValue2)
but this is fine
i don't think we implement anything like .length
Ariana — 11:12 PM
hm yea i guess we need it idk
Ronny — 11:12 PM
Idk
oh well
Ariana — 11:30 PM
I wrote a few for both syntax and semantic in the error and k0 stuff
Ronny — 11:31 PM
Nice, I got half with the syntax example
we don't have to make it work for now right?
Ariana — 11:32 PM
No lol
Ronny — 11:32 PM
ok good lol
Ariana — 11:32 PM
are you ready to combine everything
?
Ronny — 11:34 PM
I can send what I got for now
Ariana — 11:34 PM
okay
ill add it
Ronny — 11:35 PM
fun main() {
    var name = "John"
    val birthyear = 1975
    println(name)          // Print the value of name
    println(birthyear)     // Print the value of birthyear
    
Expand
lex0.kt
1 KB
fun main() {
    var longValue1: Long = 9223372036854775807L
    val longValue2: Long = 9222372036854775807L

    val greatestValue = max(longValue1, longValue2)
    println("The greater value is: $greatestValue")
Expand
lex1.kt
1 KB
fun main() {
    var x = 1975
    println(x)
    x = x + 1
    println(x)
    x = x * 2
Expand
lex2.kt
1 KB
fun getWeatherAdvice(weather: String): String {
    return when (weather) {
        "sunny" -> "Wear sunglasses and sunscreen."
        "rainy" -> "Carry an umbrella."
        "windy" -> "Hold onto your hat!"
        "snowy" -> "Dress warmly and watch for icy roads."
Expand
lex3.kt
1 KB
fun main (){
    val myNum: Int = 5                // Int
    val myDoubleNum: Double = 5.99    // Double
    val myLetter: Char = 'D'          // Char
    val myBoolean: Boolean = true     // Boolean
    val myText: String = "Hello"      // String
Expand
lex4.kt
1 KB
Ariana — 11:39 PM
do you think this many is enough?
Image
Ronny — 11:40 PM
hmm maybe ?
I'm going to add a few more for if, else
Ariana — 11:41 PM
okayy
cool i just added like 9 more for the kotlin folder
Ronny — 11:49 PM
fun main() {
    val a = 10
    val b = 20

    // Using Relational and Equality Operators in if-else
    if (a < b) {
Expand
lex5.kt
1 KB
fun main() {
    var i = 0
    do {
      println(i)
      i++
      }
Expand
lex6.kt
1 KB
nice
I kind of just put most in one file
﻿
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