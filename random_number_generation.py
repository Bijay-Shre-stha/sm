import numpy as np

# Mixed LCG
def mixed_lcg(seed, a, c, m, n):
    random_numbers = []
    x = seed
    for _ in range(n):
        x = (a * x + c) % m
        random_numbers.append(x / m)  # Normalize to [0,1]
    return random_numbers

# Multiplicative LCG (MLCG)
def multiplicative_lcg(seed, a, m, n):
    random_numbers = []
    x = seed
    for _ in range(n):
        x = (a * x) % m
        random_numbers.append(x / m)  # Normalize
    return random_numbers

# Additive LCG (Fibonacci LCG)
def additive_lcg(seed1, seed2, m, n):
    random_numbers = []
    x, y = seed1, seed2  # Two seeds
    for _ in range(n):
        x, y = y, (x + y) % m
        random_numbers.append(y / m)  # Normalize
    return random_numbers

# Example usage
seed = 12345
a = 1664525
c = 1013904223
m = 2**32
n = 10  # Generate 10 random numbers

print("Mixed LCG:", mixed_lcg(seed, a, c, m, n))
print("Multiplicative LCG:", multiplicative_lcg(seed, a, m, n))
print("Additive LCG:", additive_lcg(1234, 5678, m, n))
