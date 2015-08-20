from ctypes import *

libC = CDLL('/home/udesc/Documentos/Python_tests/glue_test/testlib')
print(libC)

libC.myPrintf()
