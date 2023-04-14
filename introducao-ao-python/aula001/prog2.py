#print("Hello, World!")
#print(2**3)
#print(25**(1/2))
#print(27**(1/3))

n1, n2, n3 = 25, 9, 11
#print('n3 = ',n3,'\nn2 = ',n2)
#print('n3 + n1 = ',n3+n1)

#cubo = lambda x: pow(x, 3)
#print(cubo(2))

#def raizq(a):
   # """
   # faz a raiz quadrada de a
   # """
   # raiz = a**(1/2)
   # return (raiz)
    

#vr = raizq(n1)
#print(vr)

lt = [1,2,3,4,5,6,7,8,9]
lt2 = [0, 11, 12]
print(lt[0])
print(type(lt))
lt.append (10)
print(lt)
del lt[0]
print(lt)

print(len(lt))
lt3 = lt+lt2
print(lt3)

soma=sum(lt2)
media=soma/len(lt2)
print(media)

lt.sort(reverse=True)
print(lt)
lt.sort(reverse=False)
print(lt)