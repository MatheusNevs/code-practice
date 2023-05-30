cores = {'Preto' => '0',
      'Marrom' => '1',
      'Vermelho' => '2',
      'Laranja' => '3',
      'Amarelo' => '4',
      'Verde' => '5',
      'Azul' => '6',
      'Roxo' =>'7',
      'Cinza' => '8',
      'Branco' => '9'
    }
codigo = gets().chomp.split('-', )
resistencia = cores[codigo[0]].to_s + cores[codigo[1]].to_s
p(resistencia)

