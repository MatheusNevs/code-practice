vowels = "AaÀàÁáÂâÄäEeÈèÉéÊêËëIiÌìÍíÎîÏïOoÒòÓóÔôÖöUuÙùÚúÛûÜü"
consonants = 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ'
repeats = [0,0]

sentence = gets().chomp()
for l in sentence.chars
    if consonants.include?(l)
        repeats[0] += 1
    end
    if vowels.include?(l)
        repeats[1] += 1
    end
end


p repeats

