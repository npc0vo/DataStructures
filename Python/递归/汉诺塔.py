def moveTower (height,from_,to,with_):
    if height >=1:
        moveTower(height-1,from_,with_,to)
        moveDisk(height,from_,to)
        moveTower(height-1,with_,from_,to)
def moveDisk(height,from_,to):
    print(f"Moving disk{height} from_{from_} to {to}")

moveTower(3,1,2,3)
# def moveTower(height, from__pole, to_pole, with__pole):
#     if height >= 1:
#         moveTower(height - 1, from__pole, with__pole, to_pole)
#         moveDisk(height, from__pole, to_pole)
#         moveTower(height - 1, with__pole, to_pole, from__pole)

# def moveDisk(height, from__pole, to_pole):
#     print(f"将盘子 {height} 从柱子 {from__pole} 移动到柱子 {to_pole}")

# moveTower(3, 1, 2, 3)



