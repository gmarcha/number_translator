import random

while True:
	l = int(input("Enter number length: "))
	if l < 3:
		print("Give me a bigger number please")
	else:
		break

for _ in range(l):
	print(random.randint(0, 9), end="")
print()
input()