rotations = []
while True:
  rotation = input()
  if rotation == 'END':
    break
  rotations.append([rotation[0] == 'L', int(rotation[1:])])
dial = 50
password = 0
for is_left, num in rotations:
  # print(password)
  if is_left:
    if dial - num <= 0:
      password += (num - dial) // 100 + (1 if dial != 0 else 0)
    dial = (dial - num) % 100
  else:
    if dial + num >= 100:
      password += (dial + num) // 100
    dial = (dial + num) % 100
print(password)