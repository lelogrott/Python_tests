from ctypes import *


libStack = CDLL('/home/zaphod/Desktop/Python_tests/PDDE/libPDDE1.0')
print(libStack)

class nodeStack(Structure):
    pass

nodeStack._fields_ = [
    ("data", c_void_p),
    ("below", POINTER(nodeStack)),
    ("above", POINTER(nodeStack)),
    ]


class Stack(Structure):
    _fields_ = [
        ("sizeOfInfo",c_int),
        ("top",POINTER(nodeStack)),
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
