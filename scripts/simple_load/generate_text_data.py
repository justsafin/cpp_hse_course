import random

with open("text.txt", "r") as fr:
    with open("text_data.txt", "w") as fw:
        text = fr.readline()
        test_list = text.split(". ")
        for i in range(500):
            rand_i = random.randint(0, len(test_list)-1)
            str_to_write = test_list[rand_i]
            min = 10
            if len(str_to_write) < 10:
                min = len(str_to_write)-1
            len_rand = random.randint(min, len(str_to_write)-1)
            fw.write(f"{str_to_write[:len_rand]}\n")