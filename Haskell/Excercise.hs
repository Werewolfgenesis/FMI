func1::(Int->Int)->[Int]->(Int->Int)
func1 g list = (\x -> f g list x 1 0) 

f g [] _ _ sum = sum
f g (y:ys) x n sum = f g ys x (n+1) (sum + y*(g (x^n)))

main::IO()
main = do
        print ((func1 (\x -> 2*x) [1..3]) 2)

--1*(2*2) + 2*(2*4) + 3*(2*8) = 68