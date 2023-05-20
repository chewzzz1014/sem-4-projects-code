# extended Euclidean Algorithm
# refer Cryptography and Network Security: Principles and Practice by William Stallings

a = int(input('Enter a:'))
b = int(input('Enter b:'))

i = -1
current_idx = 0
r_arr = [a, b]
x_arr = [1, 0]
y_arr = [0, 1]
q_arr = []

print('\n' + str(a) + 'x + ' + str(b) + 'y = ' + 'gdc(' + str(a) + ', ' + str(b) + ')')
print('\ni\tri\t\tqi\t\txi\t\tyi')

while r_arr[-1] != 0:
    if i == -1 or i == 0:
        r = r_arr[current_idx]
        x = x_arr[current_idx]
        y = y_arr[current_idx]
        q = '-'
    else:
        q = int(r_arr[current_idx - 2] / r_arr[current_idx - 1])
        r = r_arr[current_idx - 2] % r_arr[current_idx - 1]

        if r == 0:
            x = '-'
            y = '-'
        else:
            x = x_arr[current_idx - 2] - (q * x_arr[current_idx-1])
            y = y_arr[current_idx - 2] - (q * y_arr[current_idx - 1])

        q_arr.append(q)
        r_arr.append(r)
        x_arr.append(x)
        y_arr.append(y)

    if r >= 1000:
        output = str(i) + '\t' + str(r) + '\t' + str(q) + '\t\t' + str(x) + '\t\t' + str(y)
    else:
        output = str(i) + '\t' + str(r) + '\t\t' + str(q) + '\t\t' + str(x) + '\t\t' + str(y)

    print(output)
    i = i + 1
    current_idx = current_idx + 1

