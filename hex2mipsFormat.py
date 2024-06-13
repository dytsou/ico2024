hexnum = input()
mips = ""
for i in range(0, len(hexnum)):
    if hexnum[i] == '0':
        mips += "0000"
    elif hexnum[i] == '1':
        mips += "0001"
    elif hexnum[i] == '2':
        mips += "0010"
    elif hexnum[i] == '3':
        mips += "0011"
    elif hexnum[i] == '4':
        mips += "0100"
    elif hexnum[i] == '5':
        mips += "0101"
    elif hexnum[i] == '6':
        mips += "0110"
    elif hexnum[i] == '7':
        mips += "0111"
    elif hexnum[i] == '8':
        mips += "1000"
    elif hexnum[i] == '9':
        mips += "1001"
    elif hexnum[i] == 'A' or hexnum[i] == 'a':
        mips += "1010"
    elif hexnum[i] == 'B' or hexnum[i] == 'b':
        mips += "1011"
    elif hexnum[i] == 'C' or hexnum[i] == 'c':
        mips += "1100"
    elif hexnum[i] == 'D' or hexnum[i] == 'd':
        mips += "1101"
    elif hexnum[i] == 'E' or hexnum[i] == 'e':
        mips += "1110"
    elif hexnum[i] == 'F' or hexnum[i] == 'f':
        mips += "1111"
for i in range(0, len(mips)):
    if i == 6 or i == 11 or i == 16 or i == 21 or i == 26:
        print(" ", end="")
    print(mips[i], end="")
print()

opcode = mips[0:6]
op = int(opcode, 2)
func = mips[26:32]
funct = int(func, 2)
if op == 0:
    if funct == 32:
        print("add")
    elif funct == 33:
        print("addu")
    elif funct == 34:
        print("sub")
    elif funct == 35:
        print("subu")
    elif funct == 36:
        print("and")
    elif funct == 37:
        print("or")
    elif funct == 38:
        print("xor")
    elif funct == 39:
        print("nor")
    elif funct == 42:
        print("slt")
    elif funct == 43:
        print("sltu")
elif op == 2:
    print("j")
elif op == 3:
    print("jal")
elif op == 4:
    print("beq")
elif op == 5:
    print("bne")
elif op == 8:
    print("addi")
elif op == 9:
    print("addiu")
elif op == 10:
    print("slti")
elif op == 11:
    print("sltiu")
elif op == 12:
    print("andi")
elif op == 13:
    print("ori")
elif op == 14:
    print("xori")
elif op == 15:
    print("lui")
elif op == 35:
    print("lw")
elif op == 43:
    print("sw")