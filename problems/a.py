x, y = map(int, input().split())

# 최대 공약수
li_1 = []
li_2 = []

for i in range(1, x+1):
    if x % i == 0:
        li_1.append(i)

for i in range(1, y+1):
    if y % i == 0:
        li_2.append(i)
print(li_1)
print(set(li_1))

print(li_2)
print(list(set(li_1) & set(li_2)))
num = list(set(li_1) & set(li_2))[-1]
print(num)

 
# 최소 공배수
cnt = 1

while True:
    if num * cnt >= x and num * cnt >= y:
        if (num * cnt) % x == 0 and (num * cnt) % y == 0:
            print(num * cnt)
            break
        else:
            cnt += 1
    else:
        cnt += 1

