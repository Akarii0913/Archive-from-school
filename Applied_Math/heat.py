import numpy as np
import matplotlib.pyplot as plt
import sympy as sy

x, n, t = sy.symbols('x, n, t')

f1 = (1/((n+1/2)*sy.pi))*(sy.exp((-((n+1/2)*sy.pi)**2)*t))*(sy.sin((n+1/2)*sy.pi*x))
func = sy.summation(f1, (n, 0, 30))

p = sy.plot(func.subs(t, 1), func.subs(t, 2), func.subs(t, 3), (x, 0, 1), legend=True, show=False)
p[0].label = "t = 1"
p[1].label = "t = 2"
p[2].label = "t = 3"
p.show()
