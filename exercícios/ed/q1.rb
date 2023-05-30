names = gets().split
repeated_name = names[0]
repeats = 0
for name in names
    if names.count(name) > repeats
        repeats = names.count(name)
        repeated_name = name
    end
end
p repeated_name