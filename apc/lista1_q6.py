numbers = [int(x) for x in input().split()]
start, end = [int(x) for x in input().split()]
print(start, end)
new_numbers = numbers[start: end]
print(new_numbers)