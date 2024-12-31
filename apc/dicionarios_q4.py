while True:
    try:
        info_alunos = {}
        n = int(input())
        for i in range(0,n):
            nome, email, *notas = input().split()
            info_alunos[nome] = {'email':email, 'notas': notas}

        aluno_consultado = input()
        if aluno_consultado not in info_alunos.keys():
            print(f'O aluno {aluno_consultado} não está na turma.')
        else:
            info_aluno = info_alunos.get(aluno_consultado)
            notas = info_aluno.get('notas')
            print(f'Destinatário: {info_aluno.get("email")}')
            media = sum([float(x) for x in notas])/len(notas)
            if media >= 5:
                print(f'O aluno {aluno_consultado} foi aprovado com média {media:.2f}.')
            else:
                print(f'O aluno {aluno_consultado} foi reprovado com média {media:.2f}.')
    except EOFError:
        break