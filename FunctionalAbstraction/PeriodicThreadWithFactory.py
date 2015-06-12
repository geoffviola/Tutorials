#Forward thread boundary
#Simulates factory pattern
import threading
import time

output_filename = "PeriodicThreadWithFactoryFile.txt"

def ft_io1(fun):
	fun("ft_io1 does not take arguments")

def ft_io2(fun, arg):
	fun("ft_io2 took", arg)
	
def ft_io3(fun, arg1, arg2):
	fun("ft_io3 took", arg1, "and", arg2)

def write_to_file(*args):
	with open(output_filename, 'a') as f:
		if len(args) > 0:
			for arg in args[:-1]:
				f.write(str(arg))
				f.write(" ")
			f.write(str(args[-1]) + "\n")

def factory(fun_type, io_type):
	io_fun = lambda x: None
	if 0 == io_type:
		io_fun = print
	elif 1 == io_type:
		io_fun = write_to_file
	else:
		print(io_type, "is not supported")
	if 0 == fun_type:
		return lambda x: ft_io1(io_fun)
	elif 1 == fun_type:
		return lambda x: ft_io2(io_fun, x)
	elif 2 == fun_type:
		return lambda x: ft_io3(io_fun, x, 2)
	else:
		print(fun_type, "is not supported")
		
def periodic_thread_run(fun):
	t = threading.Thread(target = lambda: periodic_thread_target(fun), 
		daemon=True)
	t.start()
	return t

def periodic_thread_target(fun):
	for i in range(5):
		fun(1)
		time.sleep(1)

#Clear file
with open(output_filename, 'w') as f:
	pass

#Run all the factory combinations
threads = []
for fun_types in range(3):
	for io_types in range(2):	
		threads.append(periodic_thread_run(factory(fun_types, io_types)))
for thread in threads:
	thread.join()

