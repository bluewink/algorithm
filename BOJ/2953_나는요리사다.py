'''
datas =[]
for i in range(5):
    data = list(map(int,input().split()))
    datas.append(data)
max_idx = 0
max_sum = 0
for i, data in enumerate(datas):
    total = sum(data)
    if(total > max_sum):
        max_idx = i+1
        max_sum = total
print(max_idx, max_sum, end=" ")
'''
max_idx, max_sum = 0,0
for i in range(5):
    total = sum(map(int, input().split()))
    if max_sum < total:
        max_idx = i+1
        max_sum = total
print(max_idx, max_sum)