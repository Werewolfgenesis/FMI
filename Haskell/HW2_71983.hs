main::IO()
main = do
    print(chain 10)
    
--Task1

kur za tupiq haskel!!!!!

formElem::Double->Double->Double
formElem p n = sum[1/m**p | m <- [1.0 .. n]]
generate::Double->Double->[Double]
generate p n = [formElem p m | m<-[1.0 .. n]]
--Task2
listSquares::Integer->Integer->[(Integer, Integer)]
listSquares a b = [(k, sumDel k)| k <- [a .. b], isSquare k 0]
                where sumDel n = sum[d^2 | d <- [1 .. n], mod n d == 0] 
isSquare::Integer->Integer->Bool
isSquare n k = if(n < k^2) then False
                else if (n == k^2) then True
                else isSquare n (k+1)

isEven::Int->Bool
isEven n = if(n `mod` 2 == 0) then True
            else False
