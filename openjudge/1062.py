import sys
import copy

# http://blog.csdn.net/lionel_d/article/details/43898649
INF = 9999999
m, n = 0, 0


class Product:
    def __init__(self, index, value, level, exchange_num):
        self.index = index
        self.value = int(value)
        self.level = int(level)
        self.exchange_list = set()

    def add_exchange_choise(self, product_index, product_value):
        self.exchange_list.add((int(product_index), int(product_value)))


product_list = list()
product_list.append(Product(0, 0, 0, 0))

try_produect_list = list()

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


target_product = product_list[1]
left = target_product.level -m if target_product.level - m > 0 else 0
right = m - left


def build_try_list(product, min_level, max_level):
    if product.exchange_list:
        delete_set = set()
        for item in product.exchange_list:
            if product_list[item[0]].level > max_level or product_list[item[0]].level < min_level:
                delete_set.add(item)

        if delete_set:
                product.exchange_list.difference_update(delete_set)

        for item in product.exchange_list:
                build_try_list(try_produect_list[item[0]], min_level, max_level)


def dijstra():
    d = [INF] * (n+1)
    parent = [None] * (n+1)
    d[1] = target_product.value

    s = set()
    q = set(try_produect_list[1:])
    while q:
        min_d = None
        u = None
        for p in q:
            if not min_d and d[p.index] != INF:
                min_d = d[p.index]
                u = p
            if min_d and d[p.index] < min_d:
                u = p
        if not u:
            break
        q.remove(u)
        s.add(u)
        for index, cost in u.exchange_list:
            if parent[u.index]:
                new_cost = cost + try_produect_list[index].value + d[u.index] - u.value
                if new_cost < d[index]:
                    d[index] = new_cost
                    parent[index] = u
            else:
                d[index] = cost + try_produect_list[index].value
                parent[index] = u

    return min(d)


k = left
ans = target_product.value
while k <= target_product.level:
    try_produect_list = copy.deepcopy(product_list)
    build_try_list(try_produect_list[1], k, k+m)
    ans = min(ans, dijstra())
    k = k + 1

print(ans)
