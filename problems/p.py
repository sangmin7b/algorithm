import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input())
a = list(map(int,input().split()))
def gcd(lst):
	def g(x, y):
		while y:
			x, y = y, x % y
		return x
	a = lst[0]
	for b in lst[1:]:
		a = g(a, b)
	return a
 
def BT(array):
	mid = len(array) // 2
	if len(array) == 1:
		return array[0]
	elif len(array) == 2:
		return array[0] + array[1]
	
	return max(BT(array[ :mid]) + gcd(array[mid: ]), BT(array[mid: ]) + gcd(array[ :mid]))
 
mid = N // 2
if N == 1:
	print(a[0])
else:
	print(max(BT(a[ :mid]) + gcd(a[mid: ]), BT(a[mid: ]) + gcd(a[ :mid])))