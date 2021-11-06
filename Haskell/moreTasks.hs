mysinx::Int->Float->Float
mysinx n x = sum [((-1)^i * x ^ (2*i + 1)) / fromIntegral(factoriel (2 * i + 1)) | i <- [0..n]]
            where 
                factoriel 0 = 1
                factoriel x = product [1..x]

main::IO()
main = do print (mysinx 5 3.14)