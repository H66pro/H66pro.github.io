# BMI = 体重/kg ÷ (身高/m ** 2)
user_weight = float( input('请输入您的体重/kg: ') )
user_height = float(input('请输入您的身高/cm: ')) / 100

user_BMI = user_weight / (user_height ** 2)
print('您的BMI指数为: ' + str(user_BMI))

if user_BMI < 18.5:
    print("您太瘦了！")
elif user_BMI > 24:
    print("您太胖了！")
else:
    print("您的BMI指数正常。")