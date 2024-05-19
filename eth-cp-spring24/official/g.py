
# read all text input at once
import sys
text = sys.stdin.read().splitlines()

# ignore first 6 lines
text = text[6:]

# get num values
values_str = text[0].split('values!')[0].split(' ')[-2]
# print(text[0].split('values!')[0].split(' '))
# print(values_str)
value_int = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5}[values_str]
print(value_int)

# parse comma separated values
values = text[0].split("operators")[-1].split(',')
values[0] = values[0][1:]
values[-1] = values[-1].split('and ')[-1][:-1]
operators = values

# skip 2 lines
text = text[3:]
# read table

func = [dict() for _ in range(len(values))]
# for i in range(len(values)):
current_op = 0
while current_op < len(operators):
    num_values = len(text[0].split(' '))
    num_arguments = num_values - 1
    length_table = value_int**num_arguments
    for i in range(length_table):
        line = text[i].split(' ')
        arg = ','.join(line[:-1])
        func[current_op][arg] = line[-1]
    current_op += 1
    text = text[length_table:]
print(func)

# skip one line
text = text[1:]

assign_op = text[0].split('are assigned with ')[-1].split('.')[0]
print(assign_op)

# skip 1 line
text = text[1:]

fs = dict()

# read until "And here are some rules"
value_table = dict()
index = 0
for line in text:
    index += 1
    if "And here are some rules" in line:
        break
    line_split = line.split(assign_op)
    variable = line_split[0].strip()
    expression = line_split[1].strip()
    if line_split[1].strip()[0] in operators:
        operator = expression.split(" ")[0]
        variables = expression.split(" ")[1:]
        print(variable, operator, "and", variables)
        fs[variable] = (operator, variables)
    else:
        value_table[variable] = expression

text = text[index:]

print(text)

# read until "Is there anything else"
value_table = dict()
for line in text:
    if "And here are some rules" in line:
        break
    line_split = line.split(assign_op)
    variable = line_split[0].strip()
    expression = line_split[1].strip()
    print(expression)
    if line_split[1].strip()[0] in operators:
        operator = expression.split(" ")[0]
        variables = expression.split(" ")[1:]
        print(variable, operator, "and", variables)
        fs[variable] = (operator, variables)
    else:
        print("Error")


print(fs)
print(value_table)