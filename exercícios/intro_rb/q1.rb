def prime?(number)
    return '' if number < 2
  
    (2...number).each do |divisor|
        return '' if number % divisor == 0
    end
  
    return 'Primo/'
  end

  
def even?(number)
    return 'Ímpar' if number % 2 != 0
    return 'Par'
end


operations = {}
operations['+'] = -> (x1,x2) {x1 + x2}
operations['-'] = -> (x1, x2) {x1 - x2}
operations['*'] = -> (x1,x2) {x1*x2}
operations[''] = -> (x1,x2) {x1**x2}
operations['√'] = -> (x) {Math.sqrt(x)}
sign = ''
entry = gets().chomp()
for c in entry.chars
    begin
        Float(c)
    rescue => exception
        sign = c
        break
    end
end

operation = operations[sign]
if sign == '√'
    x = entry.delete('√').to_i
    ans = operation.call(x)
else
    x1, x2 = entry.split(sign).map {|number| number.to_i}
    ans = operation.call(x1, x2)
end


puts('Resultado = '+ ans.to_s)
is_prime = prime?(ans)
is_even = even?(ans)
puts(is_prime + is_even)
