from ctypes import *


libQueue = CDLL('/home/zaphod/Desktop/Python_tests/FDDE/libFDDE1.0')
print(libQueue)

class nodeQueue(Structure):
    pass

nodeQueue._fields_ = [
    ("data", c_void_p),
    ("prev", POINTER(nodeQueue)),
    ("next", POINTER(nodeQueue)),
    ]


class Queue(Structure):
    _fields_ = [
        ("sizeOfInfo",c_int),
        ("first",POINTER(nodeQueue)),
        ]

foo = POINTER(Queue)()

libQueue.cria(byref(foo), sizeof(c_int))

x=c_int(7)
libQueue.insere(foo, byref(x))

libQueue.buscaNoInicio(foo, byref(x))
print x
libQueue.buscaNoFim(foo, byref(x))
print x

x=c_int(9)
libQueue.insere(foo, byref(x))

libQueue.buscaNoInicio(foo, byref(x))
print x
libQueue.buscaNoFim(foo, byref(x))
print x

libQueue.remove_(foo, byref(x))
print x

libQueue.buscaNoInicio(foo, byref(x))
print x
libQueue.buscaNoFim(foo, byref(x))
print x

libQueue.remove_(foo, byref(x))
print x

y=libQueue.testaVazia(foo)
if y==1:
    print("VAZIA")
else:
    print("NAO VAZIA")  
