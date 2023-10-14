import os
import sys
import json
import argparse
from http.server import HTTPServer, BaseHTTPRequestHandler

json_data = None

class S(BaseHTTPRequestHandler):
    def do_POST(self):
        global json_data
        json_data = json.load(self.rfile)
        # print(json.dumps(json_data, indent=2))

def runServer(server_class=HTTPServer, handler_class=S, addr="localhost", port=8000):
    server_address = (addr, port)
    httpd = server_class(server_address, handler_class)

    print(f"Waiting for data on {addr}:{port}")
    while True:
        httpd.handle_request()
        if json_data != None:
            break

def makeTest(data, inp_folder, out_folder):
    for i, t in enumerate(data['tests']):
        with open(os.path.join(inp_folder, f'in{i}.txt'), 'w') as f:
            f.write(t['input'])

        with open(os.path.join(out_folder, f'out{i}.txt'), 'w') as f:
            f.write(t['output'])

def makeEnv(contest, problem, data, has_tests):
    if not contest in os.listdir():
    	os.mkdir(contest)
        # import shutil
        # shutil.rmtree(contest, ignore_errors=True)

    prob_dir = os.path.join(contest, problem)
    test_inp_dir = os.path.join(prob_dir, 'input')
    test_out_dir = os.path.join(prob_dir, 'output')
    
    os.mkdir(prob_dir)
    os.mkdir(test_inp_dir)
    os.mkdir(test_out_dir)
    if has_tests:
    	makeTest(data, test_inp_dir, test_out_dir)

    from shutil import copyfile
    copyfile('C:\\Users\\khanh\\OneDrive\\CP\\templates\\main.cpp', os.path.join(prob_dir, f'{problem}.cpp'))
    copyfile('C:\\Users\\khanh\\OneDrive\\CP\\scripts\\checker.py', os.path.join(prob_dir, 'checker.py'))


if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument('--contest_name')
	parser.add_argument('--prob_name')
	parser.add_argument('--has_tests', default=1)
	args = parser.parse_args()

	contest_name = args.contest_name
	prob_name = args.prob_name
	has_tests = int(args.has_tests)

	if has_tests:
		runServer(addr='127.0.0.1', port=10043)
	makeEnv(contest_name, prob_name, json_data, has_tests)

