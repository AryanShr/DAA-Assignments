import random

def generateTestCase(n):
    return [random.randint(-1000000000,1000000000) for _ in range(n)]


test_cases = [generateTestCase(length) for length in range(1, 10000)]
test_cases.sort(key=lambda x: len(x))

with open("test_case.txt","w") as f:
    for test_case in test_cases:
        # Write the test case to the file
        f.write(f"{test_case}\n")