total = 0
for i in range(5):
    student = int(input())
    if (student < 40):
        student = 40
    total += student
avg = total // 5
print(avg)