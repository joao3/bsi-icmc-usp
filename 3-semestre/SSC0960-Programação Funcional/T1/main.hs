main :: IO ()
main = do
    linha <- getLine
    let jogadas = divideEmJogadas (map stringParaNum (words linha)) 1
    let jogadasFormatadas = formataJogadas jogadas 1
    let pontuacaoTotal = calculaPontos jogadas
    print(concat jogadasFormatadas ++ show pontuacaoTotal)

stringParaNum :: String -> Int
stringParaNum x = read x :: Int

foiStrike :: (Eq a, Num a) => [a] -> Bool
foiStrike [10] = True
foiStrike _ = False

foiSpare :: (Foldable t, Eq a, Num a) => t a -> Bool
foiSpare jogada = (length jogada > 1) && (sum jogada == 10)

divideEmJogadas :: (Eq a1, Eq a2, Num a1, Num a2) => [a2] -> a1 -> [[a2]]
divideEmJogadas [] _ = []
divideEmJogadas h 10 = [h]
divideEmJogadas (10:t) count = [10]:divideEmJogadas t (count + 1)
divideEmJogadas (h:g:t) count = [h, g]:divideEmJogadas t (count + 1)
divideEmJogadas (h:t) count = [h]:divideEmJogadas t (count + 1)

formataUltimaJogada :: (Eq a, Num a, Show a) => [a] -> [Char]
formataUltimaJogada h
    | head h == 10 = "X " ++ segundoArremesso ++ " " ++ terceiroArremesso
    | head h + h!!1 == 10 = show (head h) ++ " / " ++ terceiroArremesso
    | otherwise = show (head h) ++ " " ++ show (h!!1) ++ " | "
    where
        segundoArremesso = if h!!1 == 10 then "X" else show (h!!1)
        terceiroArremesso
          | h!!1 + h!!2 == 10 = "/ | "
          | h!!2 == 10 = "X | "
          | otherwise = show(h!!2) ++ " | "

formataJogadas :: (Eq a1, Eq a2, Num a1, Num a2, Show a2) => [[a2]] -> a1 -> [[Char]]
formataJogadas [] _ = []
formataJogadas (h:t) 10 = [formataUltimaJogada h]
formataJogadas (h:t) count
    | foiStrike h = ("X" ++ " _ | "):formataJogadas t (count + 1)
    | foiSpare h = (show (head h) ++ " / | "):formataJogadas t (count + 1)
    | otherwise = (show (head h) ++ " " ++ show(h!!1) ++ " | "):formataJogadas t (count + 1)

calculaPontos :: (Num a, Eq a) => [[a]] -> a
calculaPontos [] = 0
calculaPontos (h:t)
    | foiStrike h = if foiStrike (head t) then 10 + 10 + head(t!!1) + calculaPontos t else 10 + head (head t) + head t!!1 + calculaPontos t
    | foiSpare h = 10 + head (head t) + calculaPontos t
    | otherwise = sum h + calculaPontos t