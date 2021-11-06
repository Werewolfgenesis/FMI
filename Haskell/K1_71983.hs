main::IO()
main = do print (checkSequence)
          

checkSequence::[Int]->Bool
checkSequence []  = True
checkSequence [x,y] = if(x < y && x /= 0 && y /= 0) then True else False
checkSequence lst = if((head lst <= lst !! 1) && head lst /= 0)
    then checkSequence (drop 1 lst) 
        else False

removeNb::Int->[(Int,Int)]
removeNb n = [(x,y) | x <- [0..n-1], y <- [0..n-1], x*y == (sum [0..n]) - (x+y)]


type Point = (Double, Double)
line::Point->Point->(Double->Double)
line p1 p2 = f
        where
            f x = snd p1 +  (x - fst p1) * (snd p2 - snd p1) / (fst p2 - fst p1)

liesOn :: (Double -> Double) ->(Point -> Bool)
liesOn line = g
       where
           g point = if(y == line point diagonal) then True else False

diagonal::(Double->Double)
diagonal = line (0,0) (1,1)

point::Point
point = (x,y)

onDiag::Bool
onDiag = liesOn diagonal
