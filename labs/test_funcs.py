
import cppimport
funcs = cppimport.imp("wrap1")

if __name__ == '__main__':
    print(funcs.logistic(x))