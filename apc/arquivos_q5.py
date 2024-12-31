import csv

cursos = { '127' : 'Bacharelado em Ciência da Computação',
'132' : 'Arquitetura e Urbanismo',
'136' : 'Engenharia Civil',
'137' : 'Engenharia Elétrica',
'139' : 'Engenharia Florestal',
'158' : 'Licenciatura em Física',
'159' : 'Licenciatura em Química',
'160' : 'Licenciatura em Ciências Biológicas',
'161' : 'Licenciatura em Matemática',
'162' : 'Licenciatura em Lígua Portuguesa'
}
licenciatura = ['158','159','160','161','162']

filename = input()
f = open(filename, 'r', encoding='latin_1', newline='')
reader = csv.reader(f, delimiter=';')
soma = 0
cont = 0
total = 0
soma_idade = 0
soma_prof = 0
for row in reader:
    curso = row[1]
    if row[4] != "TP_PRES":
        total += 1
        soma_idade += float(row[2])
    if row[4]=="555": 
        cont += 1
        soma += float(row[5].replace(',', '.'))
    if curso in licenciatura and (row[10] == 'A' or row[10] == 'B'):
        soma_prof += 1
media = soma / cont
media_idade = soma_idade/total
print(f'Relatório ENADE 2017')
print(f'Curso: {cursos[curso]}')
if total > 0:
    print(f'Total de alunos inscritos: {total}') #não conta a primeira linha que é o sigla dos campos
if cont > 0:
    print(f'Total de alunos que realizaram o Enade: {cont}')
print(f'Média da idade dos alunos inscritos no ENADE: {media_idade:.2f}')
if soma_prof > 0:
    print(f'Total de alunos da licenciatura que pretendem ser professor: {soma_prof}')
print(f'Média geral dos alunos que realizaram o ENADE: {media:.2f}')
