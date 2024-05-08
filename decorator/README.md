
O padrão Decorator é utilizado para adicionar novos comportamentos a objetos, envolvendo-os em invólucros que contêm os comportamentos adicionais. Ele permite acoplar dinamicamente novas funcionalidades a objetos existentes sem alterar sua estrutura.

Imagine uma biblioteca de notificação que inicialmente suporta apenas notificações por email. Com o padrão Decorator, novos métodos de notificação, como SMS, Facebook e Slack, podem ser adicionados sem modificar a classe base Notificador. Isso é feito através da criação de decoradores que implementam a mesma interface que o objeto base.

A herança, muitas vezes usada para alterar o comportamento de objetos, tem limitações, como a incapacidade de alterar o comportamento de um objeto existente durante a execução e a restrição de herança de uma única classe pai. O Decorator supera essas limitações usando Agregação ou Composição, permitindo que um objeto tenha referências a múltiplos objetos e delegue funcionalidades a eles.

Um decorador é um objeto que pode ser ligado a um objeto alvo, contendo o mesmo conjunto de métodos e delegando a ele todos os pedidos que recebe. O envoltório pode alterar o resultado antes ou depois de passar o pedido para o alvo, adicionando comportamentos adicionais.

No exemplo das notificações, o comportamento básico de notificação por email permanece na classe base Notificador, e os outros métodos de notificação são transformados em decoradores. O cliente pode então envolver o objeto base em decoradores que coincidem com suas preferências de notificação, criando uma pilha de decoradores.

Essa abordagem permite que o cliente trabalhe com objetos "puros" ou decorados sem precisar saber a diferença, desde que sigam a mesma interface. O padrão Decorator pode ser aplicado a diferentes comportamentos, como formatação de mensagens ou composição de listas de destinatários, permitindo que o cliente adicione comportamentos personalizados conforme necessário.
