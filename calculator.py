from os import system
from time import sleep
import platform

# i've made a function for everything for the simplicity & the ability
# to jump back & forth, wherever I want the program to jump to.


# checks what platform you opened the program from
# which is useful so I can clear your terminal / cmd prompt.
if platform.system() == "Windows":
    # pre-defining the clear function
    def clear():
        system("cls")
else:
    # pre-defining the clear function
    def clear():
        system("clear")

# pre-defining the exit function
def exit(i):
    while i != 0:
        clear()
        print("The program will exit in "+str(int(i))+" seconds.")
        sleep(1)
        i -= 1
    if i == 0:
        clear()

# main program
def calculator():
    
    clear()
    
    # first number input
    def num1_input():
        try:
            num1_input.num1 = float(input("num1: "))
        except ValueError:
            clear()
            print("Invalid number, try again!")
            num1_input()
        except AttributeError:
            clear()
            print("Invalid number, try again!")
            num1_input()
    num1_input()
    num1 = num1_input.num1

    clear()

    # operator input
    def operator_input():
        operator_input.operator = input("[+] = addition\n[-] = substraction\n[*] = multiplication\n[/] = division\noperator: ")
        operators = ["/","*","+","-"]
        if operator_input.operator not in operators:
            clear()
            print("Incorrect operator, try again!")
            operator_input()
    operator_input()
    operator = operator_input.operator

    clear()

    # second number input
    def num2_input():
        try:
            num2_input.num2 = float(input("num2: "))
        except ValueError:
            clear()
            print("Invalid number, try again!")
            num2_input()
    num2_input()
    num2 = num2_input.num2

    # elif operators
    def operator_choose():
        if operator == "+":
            operator_choose.answer = num1 + num2
        elif operator == "-":
            operator_choose.answer = num1 - num2
        elif operator == "*":
            operator_choose.answer = num1 * num2
        elif operator == "/":
            operator_choose.answer = num1 / num2
    operator_choose()
    final_answer = operator_choose.answer

    # rounding the answer if it's an integer.
    def answer_round():
        if final_answer % 1 == 0:
            answer_round.answer = int(final_answer)
        else:
            answer_round.answer = float(final_answer)
    answer_round()
    answer = answer_round.answer

    # printing the answer
    def answer_prompt():
        clear()
        print("answer: "+str(answer))
    answer_prompt()

    # restart program or continue
    def con():
        var = input("[1] = new calculation\n[2] = quit game\nYou: ")
        if var == "1":
              calculator()
        if var == "2":
            exit(3)
        else:
            clear()
            answer_prompt()
            print("Wrong input, try again!")
            con()
    con()
calculator()
