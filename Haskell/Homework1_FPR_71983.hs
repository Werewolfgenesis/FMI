main::IO()
main = do
    print(chain 10)

findSumLast3::Int -> Int -> Int -> Int--sum of the last 3 members of the sequence
findSumLast3 a b n = (findSumN a b (n-1)) + 
                     (findSumN a b (n-2)) + 
                     (findSumN a b (n-3))

findSumN::Int -> Int -> Int -> Int
findSumN a b n = if(n < 0) then a --bottom of recursion/we don't have negative positions in a sequence
else (((pow 2 n)*b) + (findSumN a b (n-1)))--sequence from the task description

pow::Int->Int->Int--function to calculate the power of an integer
pow a b = if(b == 0) then 1 else a * pow a (b - 1)

isSquare::Int->Bool
isSquare a = if((square a 0) == True) then True 
             else False --just using the result of the 'square' function

square::Int-> Int -> Bool
square a b= if(a < b*b) then False --negative root and when we move to the next whole number
            else if (a == b*b) then True --if they are equal we have found the sqrt
            else square a (b+1) --otherwise we move on to the next integer and try again

isPrime::Integer->Bool--function to check whether a number is prime
isPrime a = if(a == 2 || a == 3 || a == 5 || a == 7) then True
else if(mod a 2 /= 0 && mod a 3 /= 0 && mod a 5 /= 0 && mod a 7 /= 0) then True else False

isSpecial::Integer -> Int -> Bool
isSpecial n k = if(n < 10^k) then True--bottom of recursion 
                else if(isPrime (mod n (10^k))) then (isSpecial (div n 10) k)--check whether each k element number is prime
                       --the function continues until the base case is executed
                else False --if any of the numbers is not prime then return false 

chain::Int->[Int]
chain 1 = [1]
chain n 
    | mod n 2 == 0 = n:chain (n `div` 2)
    | mod n 2 /= 0 = n:chain (3*n + 1)