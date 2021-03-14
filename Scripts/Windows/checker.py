import sys
import os

class bcolors:
    OK = '\033[92m' #GREEN
    WARNING = '\033[93m' #YELLOW
    FAIL = '\033[91m' #RED
    RESET = '\033[0m' #RESET COLOR

def diff(id, output, ans):
	out = os.popen(f'fc /w {output} {ans}').read()
	if 'FC: no differences encountered' in out.split('\n'):
		print(f'TEST #{id}: {bcolors.OK} PASSED {bcolors.RESET}')
		return 1
	else:
		print(f'TEST #{id}: {bcolors.FAIL} FAIL {bcolors.RESET}')
		print(out)
		return 0

def evaluate(name):
	with open('tmp_out.txt', 'w') as f:
		pass

	NUM_TESTS = len(os.listdir('input'))
	count = 0
	for i in range(NUM_TESTS):
		inp_path = os.path.join('input', f'in{i}.txt')
		out_path = os.path.join('output', f'out{i}.txt')

		os.system(f'{name} < {inp_path} > tmp_out.txt')
		count += diff(i, 'tmp_out.txt', out_path)

	os.remove('tmp_out.txt')
	print(bcolors.WARNING + f'{count}/{NUM_TESTS} passed' + bcolors.RESET)

def clean(name):
	exec_name = name + '.exe'
	if exec_name in os.listdir():
		os.remove(exec_name)

def compile(name):
	os.system(f'g++ -std=c++14 {name}.cpp -o {name} -Wl,--stack,268435456')

if __name__ == '__main__':
	name = None
	for file in os.listdir():
		if file[-4:] == '.cpp':
			name = file[:-4]
			break

	if name is None:
		print("Can not find source file!")
	else:
		clean(name)
		compile(name)
		evaluate(name)