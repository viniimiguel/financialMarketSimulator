# Finance

## Descrição

O projeto **Finance** é uma simulação interativa do mercado financeiro, focada em demonstrar como eventos e crises impactam o valor de uma moeda. Atualmente, o programa permite simular crises econômicas e políticas que afetam diretamente o valor de uma moeda e o comportamento do governo. No futuro, será adicionada uma funcionalidade dinâmica de investidores, onde cada investidor terá parâmetros únicos para compra e venda, escolhendo os momentos ideais com base no preço das moedas, influenciados por eventos simulados. O objetivo é criar uma experiência rica e educativa sobre a dinâmica do mercado financeiro.

## Pré-requisitos
- **Git**
- Compilador **C++**
- **Cmake** ou **vcpkg**

### Recursos utilizados
- Linguagem: **C++**
- Biblioteca: **cURL**
  

### Instalação do cURL com vcpkg
1. Instalação:
   ```bash
   git clone https://github.com/viniimiguel/financialMarketSimulator.git

2. Certifique-se de ter o **vcpkg** instalado no seu sistema. Caso não tenha, siga os passos:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh  # Linux/macOS
   .\bootstrap-vcpkg.bat  # Windows
3. Instalando o curl com **vcpkg**
   ```bash
   ./vcpkg install curl  # Linux/macOS
   .\vcpkg.exe install curl  # Windows
4. Configure o Cmake para usar o vcpkg (Caso nao esteja usando o visual studio)
   ```bash
   export VCPKG_ROOT=/path/to/vcpkg  # Linux/macOS
   set VCPKG_ROOT=C:\path\to\vcpkg  # Windows
   cmake -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake ..



