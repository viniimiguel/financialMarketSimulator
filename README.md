

# 📈 Simulador de Mercado de Ações

Bem-vindo ao **Simulador de Mercado de Ações**, um projeto completo com back-end em Java (Spring Boot), C++ para cálculos de alta performance e front-end em Angular.

Neste simulador, você poderá **comprar e vender ações** com o objetivo de **obter lucro**, enfrentando a volatilidade natural de um mercado financeiro. É uma ótima forma de entender o funcionamento de uma bolsa de valores em um ambiente controlado, interativo e educativo.

Freatures futuras:
- Criação de mercado de criptomoedas
- Tema claro
- Recuperação de senha

<h1>Front em desenvolvimento</h1>


https://github.com/user-attachments/assets/45c6d2e4-dad9-405b-a687-29a5264d0564




---

## 🚀 Tecnologias Utilizadas

- ⚙️ **Back-end:** Java 21 + Spring Boot  
- 💻 **Módulo de performance:** C++ 20  
- 🌐 **Front-end:** Angular + TypeScript  
- 🛠️ **Builds & Dependências:** CMake, Node.js, NPM, libcurl
- 💾 **Banco de Dados:** MySQL

---

## 🧾 Requisitos do Projeto

Antes de executar o projeto, é necessário ter os seguintes softwares instalados:

### 🔧 Java 21 (lembre-se de criar o seu application.properties)
```bash
sudo apt update
sudo apt install openjdk-21-jdk
java -version
```

### 🔧 C++ 20 (g++)
```
sudo apt update
sudo apt install g++  
g++ --version
```

### 🔧 Cmake
```
sudo apt install cmake
cmake --version
```

### 🔧 libcurl
```
sudo apt install libcurl4-openssl-dev

```

### 🔧 MySQL Server
```
sudo apt update
sudo apt install mysql-server
sudo systemctl start mysql
mysql --version
```

### 🔧 Node.js & NPM 
```
sudo apt install nodejs npm
node -v
npm -v
```

### 🔧 Angular CLI
```
npm install -g @angular/cli
ng version
```

## Como rodar o projeto:

1° clone o repositorio:
```
git clone git@github.com:viniimiguel/financialMarketSimulator.git
cd financialMarketSimulator
```
2° Back-end:
```
cd finance
mvn clean package
cd target
java -jar finance-0.0.1-SNAPSHOT.jar 
```
3° Modulo C++:
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make
g++ main.cpp cppFiles/*.cpp groqIa/groq.cpp groqIa/api.cpp -IheaderFiles -o main -lcurl
./main.cpp
```
4° Front-end:
```
cd frontend
npm install
ng serve
```


