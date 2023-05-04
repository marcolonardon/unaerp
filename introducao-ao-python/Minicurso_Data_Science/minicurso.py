#Minicurso Data Science do dia 03/05/23
#Por Alecio Nunes

import pandas as pd
import numpy as np


pnad = pd.read_csv("https://github.com/neylsoncrepalde/introducao_ao_r/blob/master/dados/pes_2012.csv?raw=true")

pnad.head()


novo_nome = {"V0101":"Ano",
            "V0302":"Sexo", 
             "V8005":"Idade",
             "V0404":"Cor",
             "V4720":"Renda",
             "V4803":"Escolaridade",
             "V4718":"Rendimento"}
             
pnad.rename(columns=novo_nome, inplace = True)

pnad.shape

pnad['UF']

pnad['UF'].value_counts()

pnad['UF'].value_counts() / pnad.shape[0]

pnad.Idade.mean()

pnad.Idade.median()
pnad.Idade.var()
pnad.Idade.std()

pnad.describe()

pnad.dtypes
pnad.columns

pnad['Rendimento'] = pd.to_numeric(pnad['Rendimento'], errors='coerce')
pnad['Renda'] = pd.to_numeric(pnad['Renda'], errors='coerce')

import matplotlib.pyplot as plt
import seaborn as sns

sns.set(style='whitegrid')

plt.scatter(pnad.Idade, pnad.Renda)
plt.title("Idade por renda")
plt.show()

sns.boxplot(x=pnad.Sexo, y=pnad.Renda)
plt.ylim(0, 3000)
plt.show()


sns.boxplot(x=pnad.Cor, y=pnad.Renda)
plt.ylim(0, 3000)
plt.show()


plt.figure(figsize=(14,5))
sns.boxplot(x=pnad.Sexo, y=pnad.Renda, hue=pnad.Cor)
plt.ylim(0, 3000)
plt.show()


amostra = pnad.loc[(pnad.Idade >=18) & (pnad.Idade <=80) & (pnad.Idade >=0)]

amostra.describe()

amostra.groupby('Sexo').agg({'Rendimento' : 'mean'})

amostra.groupby(['Cor', 'Sexo']).agg({'Rendimento' : 'mean'})


dado = amostra.groupby('Idade').agg({'Renda':'mean'})
dado.reset_index(inplace = True)
dado

import statsmodels.formula.api as smf

modelo1 = smf.ols(formula='Renda ~ Idade', data=dado).fit()
print(modelo1.summary())


yhat1 = modelo1.predict(dado.Idade)

plt.figure(figsize=(10,5))
plt.scatter(x=dado.Idade, y=dado.Renda)
plt.plot(dado.Idade, yhat1, c='red')
plt.xlabel('Idade')
plt.ylabel('Média da renda')
plt.show()




yhat2 = modelo2.predict(dado.Idade)

plt.figure(figsize=(10,5))
plt.scatter(x=dado.Idade, y=dado.Renda)
plt.plot(dado.Idade, yhat2, c='red')
plt.xlabel('Idade')
plt.ylabel('Média da renda')
plt.show()


import re

amostra.Escolaridade.value_counts()


amostra.loc[amostra.Escolaridade == 'Sem instrução e menos de 1 ano', 'Escolaridade'] = '0'

anos_mais = re.compile(' anos ou mais')
anos = re.compile(' anos')
ano = re.compile(' ano')
amostra['Escolaridade'] = amostra['Escolaridade'].apply(lambda linha: anos_mais.sub('', linha))
amostra['Escolaridade'] = amostra['Escolaridade'].apply(lambda linha: anos.sub('', linha))
amostra['Escolaridade'] = amostra['Escolaridade'].apply(lambda linha: ano.sub('', linha))

amostra.Escolaridade.value_counts()


amostra['Escolaridade'] = pd.to_numeric(amostra['Escolaridade'], errors='coerce')

pd.isnull(amostra.Escolaridade).sum()

amostra.Escolaridade.describe()




import pingouin as pg
pg.corr(amostra.Escolaridade, amostra.Renda)


sns.set(style='whitegrid')

plt.hist(amostra.Escolaridade)
plt.title("Distribuição de anos completos de escolaridade")
plt.show()
















































