#Ideally, all globally state would be abstracted away

do_not_change_directly = False
def get_global():
	return do_not_change_directly
def set_global(new_val):
	global do_not_change_directly
	do_not_change_directly = new_val

def run(entered_once_getter, entered_once_setter):
	if not entered_once_getter():
		entered_once_setter(True)
		print("runner initialized")
	print("runner ran")

print("running normally")
for i in range(5):
	run(get_global, set_global)

print("")
def test_setter(new_val):
	print("new_val set to", new_val)
print("run for tests")
print("Test 1 entered once")
run(lambda: False, test_setter)
print("Test 2 entered already")
run(lambda: True, test_setter)
