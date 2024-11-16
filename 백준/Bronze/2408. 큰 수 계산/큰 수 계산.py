N = int(input())
print(eval("".join([input() for _ in range(2 * N - 1)]).replace("/", "//")))