trainees = ['Jéssica', 'Paulo', 'Braga', 'Daniel', 'Kaleb']
instrutores = ['Bernardo', 'Padovesi', 'Arthur', 'Luiz', 'Caetano']
for i in 0...trainees.size
    chosen_trainee = trainees.sample
    trainees.delete(chosen_trainee)
    chosen_instrutor = instrutores.sample
    instrutores.delete(chosen_instrutor)
    puts(chosen_trainee + ' X ' + chosen_instrutor)
end