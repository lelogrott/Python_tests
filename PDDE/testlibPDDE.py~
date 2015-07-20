from ctypes import *


libStack = CDLL('/home/zaphod/Desktop/Python_tests/PDDE/libPDDE1.0')
print(libStack)

class nodeStack(Structure):
    pass

nodeStack._fields_ = [
    ("dados", c_void_p),
    ("abaixo", POINTER(nodeStack)),
    ("acima", POINTER(nodeStack)),
    ]


class Stack(Structure):
    _fields_ = [
        ("tamInfo",c_int),
        ("topo",POINTER(nodeStack)),
        ]

foo = POINTER(Stack)()

libStack.cria(byref(foo), sizeof(c_int))

x=c_int(7)
libStack.insere(foo, byref(x))

libStack.busca(foo, byref(x))
print x

x=c_int(9)
libStack.insere(foo, byref(x))

libStack.busca(foo, byref(x))
print x

libStack.removeElemento(foo, byref(x))
print x

libStack.removeElemento(foo, byref(x))
print x

y=libStack.testaSeVazia(foo)
if y==1:
    print("VAZIA")
else:
    print("NAO VAZIA")  
