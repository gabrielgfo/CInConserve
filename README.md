# CInConserve

## 📝 Descrição
Projeto de EDOO (Estrutura de Dados Orientada a Objetos) que utiliza conceitos de Programação Orientada a Objetos (OOP), é um sistema de informação e, por isso, tem CRUD (Create, Read, Update and Delete) implementado na interface.
Esse programa:
- Permite cadastrar pássaros individuais;
- Organizá-los com base na ordens taxonômicas;
- Dividir aves em riscos de extinção (Not Endangered, Vulnerable, Endangered & Critically Endangered);
- Atualizar erros nos dados fornecidos; e
- Remover pássaros que foram libertos/saíram do sistema da CInConserve.

## 🏗️ Estrutura
```
📂include/
├── 📄Anseriformes.hpp
├── 📄Bird.hpp
├── 📄Falconiformes.hpp
├── 📄Galliformes.hpp
├── 📄Passeriformes.hpp
└── 📄Psittaciformes.hpp
📂src/
├── 📄Anseriformes.cpp
├── 📄Bird.cpp
├── 📄Falconiformes.cpp
├── 📄Galliformes.cpp
├── 📄Passeriformes.cpp
└── 📄Psittaciformes.cpp
📄main.cpp
📄README.md
```

## 🧮 Como Executar
```
g++ -o main main.cpp .\src\Anseriformes.cpp .\src\Bird.cpp .\src\Falconiformes.cpp .\src\Galliformes.cpp .\src\Passeriformes.cpp .\src\Psittaciformes.cpp
```
