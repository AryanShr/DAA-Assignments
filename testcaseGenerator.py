import random

def generateTestCase(n):
    return [random.randint(0,10) for _ in range(n)]


test_cases = [generateTestCase(length) for length in range(0, 10000, 4)]
test_cases.sort(key=lambda x: len(x))

with open("test_case1.txt","w") as f:
    for test_case in test_cases:
        # Write the test case to the file
        f.write(f"{test_case}\n")