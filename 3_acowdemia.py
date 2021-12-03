
import sys

def main():
  grid = []
  rows = input()
  cols = input()
  print(rows, cols)
  for _ in range(int(rows)):
    grid.append(sys.stdin.readline().strip().split(" "))
  print(grid)

main()