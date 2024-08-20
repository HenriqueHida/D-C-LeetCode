# Solução LeetCode: mergeKLists

Este repositório contém uma solução para o problema "mergeKLists" do LeetCode. O script inclui:

- Uma função `mergeKLists` que implementa a solução.
- Manipulação de entradas para listas ligadas.
- Medição do tempo de execução.

## Descrição do Problema

Você recebe uma matriz de `k` listas ligadas `lists`, onde cada lista ligada está classificada em ordem crescente.

Mescle todas as listas ligadas em uma lista ligada ordenada e retorne-a.

### Exemplo:

cpp
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

As listas ligadas são:

1->4->5
1->3->4
2->6

Mesclando-as em uma lista ordenada: 1->1->2->3->4->4->5->6

Restrições:
- k == lists.length
- 0 <= k <= 10^4
- 0 <= lists[i].length <= 500
- -10^4 <= lists[i][j] <= 10^4
- lists[i] está classificada em ordem crescente.
- A soma do comprimento de lists[i] não excederá 10^4.