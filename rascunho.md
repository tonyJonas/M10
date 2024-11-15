Perguntas:
- O que é esse arquivo .dae ('ParedesBake.dae')?
- Onde está esses arquivos com materiais fornecidos?
  - Waypoints / Limites da pista
  - PAredesBake.dae
- Qual papel dos arquivos .world e .launch para o funcionamento da simulação?
- Os limites da pista a gente coloca no CSV ou no arquivo .world?
- Os limites não seriam a própria parede por exemplo? Ou é outra coisa?
- Os waypoints (pontos centrais) já estão definidos no CSV ou precisamos ainda definir? Ou seja, essa tarefa de configuração dos waypoints precisamos apenas importar ou precisamos criar do 0?

**Tarefas:**
  - Importar o arquivo ParedesBake.dae: Coloque-o no diretório de modelos ou meshes no DRfC, garantindo que esteja acessível para o simulador Gazebo.
  - Criar o arquivo .world: Usando um editor de texto, crie um novo arquivo `.world` ou edite um já existente para incluir a malha `ParedesBake.dae` como um modelo estático na simulação.
  - Configurar colisões: Adicione componentes de colisão no arquivo `.world` para que o carrinho detecte as paredes e limites do cenário durante o treinamento.
  - **Importe os arquivos CSV**: Utilize os arquivos CSV para definir os pontos centrais (waypoints) e os limites da pista.
  - **Configuração dos Waypoints**: Crie uma lista com os pontos centrais (extraídos do CSV) e configure-os no arquivo de configuração do DRfC. Esses waypoints servirão como referência para o carrinho seguir o caminho ideal.
  - **Definição dos Limites**: Adicione os limites da pista como restrições adicionais na função de recompensa, de forma que o carrinho seja penalizado se sair do trajeto.
  - Localizar o arquivo `.launch` do DRfC e ajustar o caminho para o seu arquivo `.world`.Exemplo no `.launch` (precisará testar e ajustar):
   ```xml
   <arg name="world_name" default="path/to/your/custom_world.world"/>
   <include file="$(find gazebo_ros)/launch/empty_world.launch">
       <arg name="world_name" value="$(arg world_name)"/>
   </include>
```

# Objetivo da Atividade

Nesta atividade, os alunos irão trabalhar com um cenário personalizado usando o arquivo de malha `ParedesBake.dae`. A tarefa é configurar este cenário no **DeepRacer-for-Cloud (DRfC)**, integrando o arquivo `.dae` com o simulador, configurando os waypoints e limites, e finalmente executando o treinamento do carrinho para que ele aprenda a navegar pelo ambiente de forma otimizada.

## Materiais Fornecidos

- **Arquivo de malha**: `ParedesBake.dae`
- **Arquivos CSV contendo**:
  - **Waypoints**: Ponto central da pista, representando o trajeto ideal para o carrinho (desprezem a coordenada Z dos arquivos, o Blender criou automaticamente).
  - **Limites da pista**: Posições dos extremos, que indicam as bordas da pista.

## Passos da Atividade

### 1. Preparação do Ambiente de Trabalho
   - Acesse o ambiente **DeepRacer-for-Cloud (DRfC)** que será utilizado para a simulação e o treinamento do carrinho.
   - Familiarize-se com a estrutura de arquivos do DRfC e com o papel dos arquivos `.world` e `.launch` para o funcionamento da simulação.

### 2. Configuração do Cenário no Gazebo
   - **Importe o arquivo `ParedesBake.dae`**: Coloque-o no diretório de modelos ou meshes no DRfC, garantindo que esteja acessível para o simulador Gazebo.
   - **Criar o arquivo `.world`**: Usando um editor de texto, crie um novo arquivo `.world` ou edite um já existente para incluir a malha `ParedesBake.dae` como um modelo estático na simulação.
   - **Configurar Colisões**: Adicione componentes de colisão no arquivo `.world` para que o carrinho detecte as paredes e limites do cenário durante o treinamento.

### 3. Definição dos Waypoints e Limites
   - **Importe os arquivos CSV**: Utilize os arquivos CSV para definir os pontos centrais (waypoints) e os limites da pista.
   - **Configuração dos Waypoints**: Crie uma lista com os pontos centrais (extraídos do CSV) e configure-os no arquivo de configuração do DRfC. Esses waypoints servirão como referência para o carrinho seguir o caminho ideal.
   - **Definição dos Limites**: Adicione os limites da pista como restrições adicionais na função de recompensa, de forma que o carrinho seja penalizado se sair do trajeto.

### 4. Configuração do Arquivo `.launch`
   - Localize o arquivo `.launch` do DRfC e ajuste o caminho para o seu arquivo `.world`.
   
   Exemplo no `.launch` (precisará testar e ajustar):

``` xml
<arg name="world_name" default="path/to/your/custom_world.world"/>
<include file="$(find gazebo_ros)/launch/empty_world.launch">
    <arg name="world_name" value="$(arg world_name)"/>
</include>
```



---------------

# Trabalho — Laboratório de dados

Cada grupo deve escolher uma base de dados “interessante” e com bom potencial para exploração. Com essa base de dados, o grupo deverá fazer uma análise exploratória dos dados, com técnicas de visualização das informações. Vocês devem usar pacotes do Python como Matplotlib, Pandas entre outros (escolha livre). Faz parte do trabalho a escolha adequada dos pacotes necessários para as tarefas desejadas. Idealmente, os dados devem permitir ao grupo algum tipo de análise estatística e, se possível, inferências diversas.

Objetivamente, o que deve ser entregue por cada grupo é:

- Um relatório com a descrição da base de dados escolhida, as análises realizadas e suas conclusões;
- Todos os arquivos de dados e de código utilizados; e
- Um vídeo entre 10 e 15 minutos, com a participação de todos os componentes, com uma apresentação resumida do trabalho. Não é necessária grande “produção” para esse vídeo.

Os datasets devem ser de qualidade, e os dados não podem ser sintéticos. Há muitos datasets no [Kaggle](https://www.kaggle.com/datasets/), mas cuidado: muitos deles são de péssima qualidade. Se você não tem certeza sobre a qualidade de um dataset, pergunte aos professores ou monitores, ou use uma fonte confiável como o [World Bank](https://data.worldbank.org/), o governo federal [[1]](https://dados.gov.br/) [[2]](https://portaldatransparencia.gov.br/download-de-dados) ou alguns de seus órgãos/agências [[3]](https://sidra.ibge.gov.br/home/ipca15/brasil) [[4]](https://dadosabertos.bndes.gov.br/) [[5]](https://dadosabertos.ana.gov.br/search?tags=dados%2520abertos), o banco central ([brasileiro](https://www3.bcb.gov.br/sgspub/localizarseries/localizarSeries.do?method=prepararTelaLocalizarSeries) ou [americano](https://fred.stlouisfed.org/docs/api/fred/)) entre vários outros.

## Apresentação dos datasets

Descreva aqui seus datasets, e inclua sua origem/fonte (URL, órgão responsável (se houver), ano de publicação).

Algumas perguntas a serem respondidas:

- O que significa uma observação do dataset?
- O que significa cada variável/coluna do dataset? Quais são valores são aceitáveis para cada variável/coluna (e.g., strings, inteiros, endereço de email)?

Dê também exemplos de observações e como elas são representadas nos datasets.

## Carregamento e tratamento

Você deve carregar os dados em memória usando a biblioteca pandas.

```python
# Exemplo de código para carregar dados
# df = pd.read_csv("caminho/para/seu/dataset.csv")
```

Você deve tratar os dados, colocando-os em formato adequado para análise caso eles não já tenham sido pré-tratados. Descarte colunas que não vai usar, assegure-se que o data type delas está correto, etc.

```python
# Exemplo de código para tratamento de dados
# df = df.drop(columns=["coluna_irrelevante"])
```

## Testes de coerência

Antes de começar a analisar seus dados, pense sobre o que eles significam.

**Você consegue pensar em condições que os dados devem obedecer para serem válidos?**

Formule perguntas em linguagem natural sobre a consistência e a coerência do seu dataset. Por exemplo, se seu dataset envolve postagens de uma rede social, um usuário não pode ter posts anteriores à sua data de cadastro; se você está analisando dados de pesca, o total pescado em um dia por uma embarcação não pode superar sua capacidade de transporte, etc.

Muitos dados são invalidados pela existência de duplicatas ou por dados faltantes, então é interessante checar tais casos.

Escreva suas condições de validade abaixo. Para cada condição pensada, inclua tanto uma descrição/raciocínio em linguagem natural, quanto o código que foi usado para checá-la.

- Não crie testes desnecessários, i.e., que são sempre verdadeiros;
- Note que muitas bases de dados brutas (que ainda não foram limpadas) contém erros; encontre-os. Idealmente o professor não deve conseguir encontrar nenhum problema que já não tenha sido apontado por você.

### Condição 1

[Descrição do teste de coerência]

```python
# Código para checar a condição 1
```

### Condição *n*

[Descrição do teste de coerência]

```python
# Código para checar a condição *n*
```

## Descrição estatística do dataset

Apresente estatísticas básicas sobre o seu dataset (médias, medianas, variância, etc.). Faça também uma análise dos dados atípicos (*outliers*) do dataset. Por que você acha que esses dados são atípicos? Você acha que são erros de medida, casos extraordinários, …?

```python
# Código para análise estatística
```

Faça também gráficos que descrevam variáveis de interesse do dataset, como por exemplo scatterplots.

- Evite criar gráficos com informações que seriam melhor representadas por tabelas;
- Lembre-se das recomendações das [regras de visualização de dados](https://datascience.quantecon.org/tools/visualization_rules.html).

# Pergunta

Inclua aqui perguntas que você consegue responder com o seu dataset.

Faça pequenas análises sobre o problema que incluam gráficos. Vejam esse [estudo de caso de reincidência criminal](https://datascience.quantecon.org/applications/recidivism.html), e repare nos gráficos mostrados.

- Inclua ao menos três figuras (e.g., tabelas, gráficos gerados pela biblioteca matplotlib ou outras). Lembre-se de incluir títulos e descrições; figuras devem ser o mais autocontidas o possível.
- Note que não se espera respostas conclusivas sobre as perguntas que você escolheu responder;
- Você deve expressar sua opinião/resposta, e embasá-la com dados, mas também deve conjecturar sobre possíveis invalidações e limitações da sua resposta;
  - Por exemplo, talvez outros dados não-coletados pudessem responder melhor a pergunta, talvez haja incerteza sobre as medidas feitas, etc.;
- Pense neste trabalho como um relatório a ser publicado: escreva em linguagem clara e formal.

```python
# Código para gerar gráficos e responder perguntas
```
```