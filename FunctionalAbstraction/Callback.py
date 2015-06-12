import threading
import random
import time

def callback_main(fun_name, fun, data):
	print(fun_name + ":", fun(data))

def zero():
	return 0

def add1(x):
	return x + 1

def addY(x, y):
	return x + y

#Register callbacks
callback_handlers = []
callback_handlers.append(("zero", lambda x: zero()))
callback_handlers.append(("add1", add1))
callback_handlers.append(("addY", lambda x: addY(x, 2)))

#Setup asynchronous callbacks
def asynch_fun(fun_name, fun, data):
	time.sleep(random.randint(0, 5))
	callback_main(fun_name, fun, data)

threads = []
for callback_handler in callback_handlers:
	new_thread = threading.Thread(target=lambda:asynch_fun(callback_handler[0], callback_handler[1], random.randint(0, 10)))
	new_thread.start()
	threads.append(new_thread)
for thread in threads:
	thread.join

