rotations = []
while True:
  rotation = input()
  if rotation == 'END':
    break
  rotations.append([rotation[0] == 'L', int(rotation[1:])])
dial = 50
password = 0
for is_left, num in rotations:
  if is_left:
    dial = (dial - num) % 100
  else:
    dial = (dial + num) % 100
  password += 1 if dial == 0 else 0
print(password)