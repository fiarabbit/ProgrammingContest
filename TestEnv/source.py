lines_input = []
while True:
    try:
        i = input()
        lines_input.append(i)
    except EOFError:
        break

lines_output = []
for i in lines_input:
    lines_output.append(i[0])

for o in lines_output:
    print(o)
    pass
