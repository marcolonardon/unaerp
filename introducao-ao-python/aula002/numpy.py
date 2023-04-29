import numpy as np

a = np.arange(90).reshape(3, 3, 2, 5)

#print (a)
#print (a.ndim)#dimensão
#print (a.shape)
#print (a[0, 0])
#print (a[1,2,1,1])#cubo 1, slice 2, linha 1, valor 1
# os valores começam em zero

#a=np.arange(15).reshape(3,5)#muda o np
#print (a)

b=np.array([(1.5,2,3),(4,5,6)], dtype=object)
#b[1,2]=9
#print (b)
c=np.array([(10,11,12),(13.9,14,15)], dtype=object)

s=b+c#as dimensões precisam ser do mesmo tamanho
#print (s)

#si=np.asarray(s, dtype=int)#transforma array float para inteiro
#print (si)

m=2*b #multiplicação de array
#print (m)

p=b**2 #potencia de array

vp=c@b.T #multiplicação transposta, linhaxcolunas
#print (vp)


#print(np.mean(vp))#calcula a média

peso=np.array([(2,1),(5,2)])
#print (np.average(peso))#tambem calcula a média
print (np.average(vp, weights=peso))
#print (np.sin(peso))#pode calcular seno ou cosseno