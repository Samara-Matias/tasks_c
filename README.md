# Gerenciador de tarefas em C

Programa de linha de comando para criar, acompanhar e organizar tarefas. Os dados ficam em um arquivo binário (`tarefas.dat`), então continuam disponíveis depois que o programa é fechado.

## Uso

O programa exibe um menu com as opções:

```
1 - Adicionar tarefa
2 - Listar tarefas
3 - Alterar status
4 - Remover tarefa
5 - Buscar tarefa
6 - Quadro de resumo
0 - Sair
```

Ao escolher a opção 0, as tarefas são salvas em `tarefas.dat` antes do encerramento. Se o arquivo não existir na primeira execução, ele é criado automaticamente.

## Dados

Cada tarefa possui os seguintes campos:

- **id**: número inteiro gerado automaticamente
- **título**
- **descrição**, que pode ficar em branco
- **prioridade**: baixa, média ou alta
- **status**: pendente, em andamento ou concluída

Os campos de prioridade e status são representados por `enum`. Novas tarefas começam sempre como pendentes.