from itertools import product


with open("C.yml", "w") as f:
    for N, M, A, B in product(range(4, 6), range(4, 6), range(2, 7),range(2, 7)):
        print("---\ninput: |-\n  {} {} {} {}\nexpected: |-\n  \n...".format(N, M, A, B), file=f)
