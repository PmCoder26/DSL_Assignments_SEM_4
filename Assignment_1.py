n = int(input("Enter the size of table: "))
table = [-1] * n


# functions.

def linearProbing(ele):
    for i in range(0, n):
        index = (ele + i) % n
        if (table[index] == -1):
            table[index] = ele
            print("The element inserted successfully in the table.")
            break;
    else:
        print("The element not insreted in the table")


def quadraticProbing(ele):
    for i in range(0, n):
        index = (ele + i * i) % n
        if (table[index] == -1):
            table[index] = ele
            print("The element inserted successfully in the table.")
            break
    else:
        print("The element not inserted in the table")


def search(ele):
    count = 0
    for i in range(0, n):
        index = (ele + i) % n
        if (table[index] == ele):
            print("The element fount at index:", index, "with", count, "comparisions")
            break
        count += 1
    else:
        print("The element not fount in the table.")


def display():
    for i in range(0, n):
        print("Index:", i, ",Element:", table[i])


# main logic.


ans = 1
while (ans == 1):
    choice = -1
    print("What do you want to perfrom?")
    print("1.Linear probing")
    print("2.Quadratic probing")
    print("3.Search an element")
    print("4.Display the hash table")
    choice = int(input("Your response: "))
    if (choice == 1):
        while (True):
            linearProbing(int(input("Enter the element: ")))
            print("Do you want to continue linear probing?")
            print("Yes - 1, No - 2")
            c = int(input("Your response: "))
            if (c == 2):
                break
            else:
                continue
    elif (choice == 2):
        while (True):
            quadraticProbing(int(input("Enter the element: ")))
            print("Do you want to continue quadratic probing?")
            print("Yes - 1, No - 2")
            c = int(input("Your response: "))
            if (c == 2):
                break
            else:
                continue
    elif (choice == 3):
        while (True):
            search(int(input("Enter the element: ")))
            print("Do you want to continue searchng?")
            print("Yes - 1, No - 2")
            c = int(input("Your response: "))
            if (c == 2):
                break
            else:
                continue
    elif (choice == 4):
        while (True):
            display()
            print("Do you want to continue displaying elements?")
            print("Yes - 1, No - 2")
            c = int(input("Your response: "))
            if (c == 2):
                break
            else:
                continue
    else:
        print("Invalid choice!")

    print("Do you want to continue program?")
    print("Yes - 1, No - 2")
    ans = int(input("Your response: "))


















