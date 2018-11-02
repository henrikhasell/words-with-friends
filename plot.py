import matplotlib.pyplot as plt
import re

dictionary = {}

try:
    while True:
        line = input()
        pattern = re.match('Pass (\d+)', line)
        if pattern:
            current_pass = pattern.group(1)
            current_pass = int(current_pass)
            continue
        pattern = re.match('Time elapsed: (\S+) seconds.', line)
        if pattern:
            time_elapsed = pattern.group(1)
            time_elapsed = float(time_elapsed)
            if not current_pass in dictionary:
                dictionary[current_pass] = [time_elapsed]
            else:
                dictionary[current_pass] += [time_elapsed]
            continue
except EOFError:
    pass

for p in dictionary:
    plt.plot([p] * 5, dictionary[p], 'ro')
plt.show()

print(dictionary)
