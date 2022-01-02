import string

def main():
    with open("../inputs/p022_names.txt", 'r') as fp:
        names = fp.readlines()

    names = names[0]
    names = names.strip().replace('"', '').split(',')
    names.sort()

    test = "COLIN"
    tres = 0
    for el in test:
        v = string.ascii_uppercase.index(el) + 1
        print(el, v)
        tres += v

    print("Test result: {}".format(tres))


    result = 0
    for i, name in enumerate(names):
        name_val = 0
        for c in name:
            val = string.ascii_uppercase.index(c) + 1
            name_val += val

        name_val *= (i+1)
        result += name_val

    print("Problem result: {}".format(result))


if __name__ == '__main__':
    main()
