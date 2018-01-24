import sys
# http://blog.csdn.net/lionel_d/article/details/43898649

m, n = 0, 0


class Product:
    def __init__(self, index, value, level, exchange_num):
        self.index = index
        self.value = int(value)
        self.level = int(level)
        self.exchange_list = list()
        self.parent = list()
        self.cost_to_parent = 0

    def add_exchange_choise(self, product_index, product_value):
        self.exchange_list.append((int(product_index), int(product_value)))

    def __str__(self):
        return str(id(self))+"-index:{self.index}, value:{self.value}".format(self=self)

    def __repr__(self):
        return self.__str__()


product_list = list()
product_list.append(Product(0, 0, 0, 0))

for line in sys.stdin:
    if not m and not n:
        m, n = line.split()
        m, n = int(m), int(n)
    else:
        tp = line.split()
        if len(tp) == 3:
            index = len(product_list)
            product_list.append(Product(index, *tp))
        else:
            product_list[-1].add_exchange_choise(*tp)


for i in range(1, n+1):
    product = product_list[i]
    if product.exchange_list:
        for index, value in product.exchange_list:
            product_list[index].parent.append(product)
            product_list[index].cost_to_parent = value

def find_min_cost(product):
    cost = product.value
    return cost + min()

