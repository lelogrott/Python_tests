from ctypes import *


libPDDE = CDLL('/home/zaphod/Desktop/Python_tests/PDDE/libPDDE1.0')
print(libPDDE)

class noPDDE(Structure):
    pass

noPDDE._fields_ = [
    ("dados", c_void_p),
    ("abaixo", POINTER(noPDDE)),
    ("acima", POINTER(noPDDE)),
    ]


class PDDE(Structure):
    _fields_ = [
        ("tamInfo",c_int),
        ("topo",POINTER(noPDDE)),
        ]

foo = POINTER(PDDE)()

libPDDE.cria(byref(foo), sizeof(c_int))

x=c_int(7)
libPDDE.insere(foo, byref(x))

libPDDE.busca(foo, byref(x))
print x

x=c_int(9)
libPDDE.insere(foo, byref(x))

libPDDE.busca(foo, byref(x))
print x

libPDDE.removeElemento(foo, byref(x))
print x

libPDDE.removeElemento(foo, byref(x))
print x

y=libPDDE.testaSeVazia(foo)
if y==1:
    print("VAZIA")
else:
    print("NAO VAZIA")  
