def test():
    import numpy as np
    n = 30000
    i_s = np.arange(n).reshape((n, 1))
    j_s = np.arange(n).reshape((1, n))
    ret = np.dot(i_s, j_s).ravel().sum()
    print(ret)
