import Data.List
--Task to see the average note
type Note = Double
type Student = String
type Record = [Double]

printL::[(Student,Note)]->Note
printL list = getAverage (filter (\(x, y) -> x == "Joro") list)

getAverage::[(Student,Note)]->Note
getAverage arr = (sum [y | (x, y) <- arr]) / fromIntegral (length arr)

--Task to make a chain
chain::Int->[Int]
chain 1 = [1]
chain n 
    | mod n 2 == 0 = n:chain (n `div` 2)
    | mod n 2 /= 0 = n:chain (3*n + 1)

 --Task to double all elementsof array
doubleAll::[Int]->[Int]
doubleAll list = [2*a | a <- list]


--Task1
--Define a function that takes a natural number n and a
-- digit m and returns a list of all natural numbers up to n that contain the digit m
func::Int->Int->[Int]
func n m = [y | y <-[1..n], p <- [1..(nrDigits y)], mod y (10^p) == m]

nrDigits::Int->Int
nrDigits x = if(x == 0) then 0 else 1 + nrDigits (x `div` 10)

--Task 2
--Define a function that accepts two whole numbers:
--n and k, and returns the sum of the first k prime numbers greater than or equal to n

task2::Int->Int->Int
task2 n k = sum (take k [y | y <- [2..],isPrime y == True, y >= n])

isPrime::Int->Bool
isPrime a = if(a == 2 || a == 3 || a == 5 || a == 7) then True
else if(mod a 2 /= 0 && mod a 3 /= 0 && mod a 5 /= 0 && mod a 7 /= 0) then True else False

--Task 3
--Define a function that accepts a number and returns the tuple (x, y) where x 
--is the sum of the digits on even indices of the number and y - the sum of the ones on odd indices

task3::Int->(Int,Int)
task3 n = convert(zip[([sum listEv n]) ([sum listOdd n]))

convert::[(Int,Int)]->(Int,Int)
convert [(x,y)] = (x,y)

digs :: Integral x => x -> [x]
digs 0 = []
digs x = digs (x `div` 10) ++ [x `mod` 10]

listEv::Int->[Int]
listEv 0 = []
listEv x =
    if((nrDigits x) == 2) then (x `div` 10) : listEv 0
    else if ((nrDigits x) < 2) then head (digs x) : listEv 0
    else head (digs x):listEv (x `mod` (10^((nrDigits x) - 2)))

listOdd::[Int]->[Int]
listOdd list = [sum [x | x <- list, n <- [1,3..length list - 1], x == list !! n]]



main::IO()
main = do print(task3 2728)
