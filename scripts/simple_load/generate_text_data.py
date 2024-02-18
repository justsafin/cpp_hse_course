import random

with open("text.txt", "r") as fr:
    with open("text_data.txt", "w") as fw:
        text = fr.readline()
        test_list = text.split(". ")
        for i in range(500):
            rand_i = random.randint(0, len(test_list)-1)
            fw.write(f"{test_list[rand_i]}\n")