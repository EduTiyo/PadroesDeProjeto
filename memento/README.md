
O padrão Memento é utilizado para salvar e restaurar o estado anterior de um objeto sem expor os detalhes de sua implementação. Ele permite que um objeto (originador) crie mementos contendo seu estado atual e, posteriormente, possa restaurar esse estado. Isso é útil em situações onde é necessário desfazer operações realizadas em um objeto.

O padrão resolve problemas de encapsulamento ao permitir que o próprio objeto originador crie os mementos, evitando que outros objetos invadam seu espaço privado para coletar dados de estado. O memento armazena uma cópia do estado do objeto, mas seu conteúdo não é acessível a outros objetos além do originador.

Os mementos são armazenados em objetos cuidadores, que os manipulam apenas através de uma interface limitada. Isso garante que o estado do objeto contido no memento permaneça intacto. Quando é necessário desfazer uma operação, o cuidador recupera o memento mais recente e o passa de volta ao originador para restaurar seu estado.

No exemplo de um editor de texto, o padrão Memento permite que o editor salve o estado atual em mementos e os armazene em uma pilha dentro de um histórico. Quando o usuário deseja desfazer uma operação, o histórico recupera o memento mais recente e o passa de volta ao editor, que restaura seu estado anterior.
