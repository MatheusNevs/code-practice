# recebe uma operação
# e retorna se é impar/par/primo
# com o resultado

signs = ['+', '-', '*', '^', '√']
sign = ''

operation = gets().chomp()

for i in operation.split("")
    if i in signs
        sign = i
        puts i
    end
end

operation = operation.split(sign)
print(operation, sign )