--1234 -> [1,2,3,4]
digs :: Integral x => x -> [x]
digs 0 = []
digs x = digs (x `div` 10) ++ [x `mod` 10]

--check if a nukmber is prime
isPrime::Int->Bool
isPrime a = if(a == 2 || a == 3 || a == 5 || a == 7) then True
           else if(mod a 2 /= 0 && mod a 3 /= 0 && mod a 5 /= 0 && mod a 7 /= 0) then True else False

--Number of digits in a number
nrDigits::Int->Int
nrDigits x = if(x == 0) then 0 else 1 + nrDigits (x `div` 10)

--sort a list
--Data.list -> sort

--check if a number is Even
isEven::Int->Bool
isEven n = if(n `mod` 2 == 0) then True

            else False
          
--
factoriel::Int->Int->Int->Int
factoriel n count product 
            | count > n = product
            | otherwise factoriel n (count + 1) (product * counter)


--check if a nr is square
isSquare::Integer->Integer->Bool
isSquare n k = if(n < k^2) then False
                else if (n == k^2) then True
                else isSquare n (k+1)