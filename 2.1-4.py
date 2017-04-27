def add_bins(a, b):
    to_next = 0
    result = []
    for a_bit, b_bit in reversed(zip(a, b)):
        _sum = a_bit + b_bit + to_next
        to_next = _sum // 2
        _sum %= 2
        result.insert(0, _sum)
    if to_next:
        result.insert(0, to_next)
    return result


checks = [
    [[0, 0, 0], [0, 0, 0], [0, 0, 0]],
    [[0, 0, 1], [0, 0, 0], [0, 0, 1]],
    [[0, 0, 1], [0, 0, 1], [0, 1, 0]],
    [[0, 1, 1], [0, 1, 1], [1, 1, 0]],
    [[1, 1, 1], [1, 1, 1], [1, 1, 1, 0]]
]

for a, b, result in checks:
    assert add_bins(a, b) == result, result

print('done')
