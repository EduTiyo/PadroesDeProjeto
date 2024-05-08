O padrão Prototype é utilizado para copiar objetos existentes sem tornar o código dependente de suas classes. Ele delega o processo de clonagem para o próprio objeto que está sendo clonado, utilizando uma interface comum para todos os objetos que suportam clonagem. Isso permite clonar um objeto sem acoplar o código à classe do objeto, sendo útil quando se sabe apenas a interface que o objeto segue, mas não sua classe concreta.

A implementação do método clonar é semelhante em todas as classes, criando um novo objeto da classe atual e carregando todos os valores de campo do objeto antigo para o novo. Esse método pode até mesmo copiar campos privados, já que a maioria das linguagens de programação permite que objetos acessem campos privados de outros objetos da mesma classe.

Um objeto que suporta clonagem é chamado de protótipo. Quando se tem muitos campos e configurações possíveis, clonar objetos pode ser uma alternativa às subclasses. Ao criar um conjunto de objetos configurados de várias formas, clonar um protótipo se torna uma maneira eficiente de obter objetos sem construí-los do zero.





