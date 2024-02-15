# temperature_dict = {"111": 36.5, "112": 37.1, "113": 38.9, "114": 37.5, "115": 38.2}
# for staff_id, temperature in temperature_dict.items():
#     if temperature >= 38:
#         print(staff_id)

num_range = range(1, 101)   # 不包括101
sum_range = 0
count = 0

for num in num_range:
    sum_range += num
    count += 1

if count == 0:
    result = 0
else:
    result = sum_range / count

print(result)
