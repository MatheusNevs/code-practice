alunos = {}
n = int(input())
for _ in range(0,n):
    aluno, nota = input().split(",")
    alunos[aluno] = float(nota)

nota_cliente = float(input())
alunos_nota_igual = []
for aluno in alunos.keys():
    if alunos[aluno] == nota_cliente:
        alunos_nota_igual.append(aluno)

if len(alunos_nota_igual) > 0:
    print(*sorted(alunos_nota_igual, key = str.lower), sep = '/')
else:
    print('Você foi o único aluno com essa nota.')