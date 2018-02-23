# Simulador de Processador com Algoritmo de Tomasulo (GSIM)
Este trabalho foi desenvolvido para a disciplina de Arquitetura e Organização de Computadores II (Ciência da Computação - UEM) em Julho/2017 por Ricardo Henrique Brunetto (ra94182@uem.br)

## Funcionalidade
Dado um arquivo de entrada em assembly MIPS, o simulador o executa e permite que o usuário faça uso dos comandos:
- `stats`: Mostra o status do processador no momento da execução.
- `print memory`: Mostra a memória RAM.
- `run`: Inicia o processamento.
- `-d`: Mostra o processador a cada ciclo de clock [Estacoes de Reserva, Banco de Registradores e Fila de Instruções].
- `show config`: Mostra as configurações atuais do GSIM (instruções reconhecidas e quantidades de Estacoes de Reserva).
- `instr help`: Mostra um menu para detalhes de uma instrução especifica.
- `clear`: Limpa o terminal.
- `help`: Exibe ajuda.
- `quit`: Encerra o GSIM.
Inicialmente, o pulso de clock se emite a cada `[ENTER]`. O comando `continue` finaliza o processamento (ciclo continuo)..

## Especificações Tecnológicas
Todo o programa foi escrito em C. O `makefile` local pode ser perfeitamente utilizado, visto que não há dependências externas que requeiram complexidade.

## Implementação
[Em construção...]

## Lista de Afazeres
- [x] Iniciar Processador
  - [x] Função de Decodificação
- [x] MakeFile
  - [x] Integrar Tradutor
- [x] Alterações do Tradutor
  - [x] Não permitir escrever no registrador ZERO
  - [x] Manipulação de inteiros com bit-shift
  - [x] Uso da estrutura de definição
- [ ] Implementar cache
- [x] Implementar clock
- [x] Implementar barramentos
  - [x] Implementar fila para o CDB
- [x] Implementar ULA
  - [x] Integrar com a Estação de Reserva
- [x] Implementar despacho de instruções
- [x] Vetores sendo inseridos ao inverso
- [x] Reconhecer números negativos

### Limitações e Sugestões
- Não fora implementado o componente de cache. Segue como sugestão para trabalhos futuros.
- Não há um relatório com documentação formal ou análises. Segue como sugestões para trabalhos futuros.

## Licença
Este projeto segue a licença [Creative Commons Attribution-ShareAlike (BY-SA)](https://creativecommons.org/licenses/by-sa/4.0/), que está detalhada no arquivo [`LICENSE.md`](LICENSE.md).
<p align="center">
  <img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png">
</p>
