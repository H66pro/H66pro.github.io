shopping_list = ["jp", "键帽"]
print(shopping_list[0].upper())
shopping_list.append("显示器")
shopping_list.remove("jp")
shopping_list[1] = "硬盘"
print(shopping_list)
print(len(shopping_list))

num_list = [1, 0, -4, 54, 32]
print(sorted(num_list))
num_list = sorted(num_list)
print(num_list)

contacts = {"mom": "1313312", "dad": "124533"}
print(contacts["mom"])
example_tuple = ("sad", "44")
contacts_tuple = {("zhangwei", 22): "123312", ("zhangwei", 21): "244422"}
print(contacts_tuple[("zhangwei", 21)])
contacts_tuple[("kite", 24)] = "654436"
print(contacts_tuple)
del contacts['mom']
