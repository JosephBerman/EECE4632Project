def getKeys():
    keyFile = open('keys.txt', 'r')
    public = keyFile.readline().strip()
    public = public.split(', ')
    print(public)
    private = keyFile.readline().strip()
    private = private.split(', ')
    print(private)


    keyFile.close()



    return [public, private]

def decrypt(privateKey:list):
    message = []
    decryptFile = open('message.txt', 'r')

    while True:
        character = decryptFile.readline()
        if not character:
            break

        message.append(chr(pow(int(character), int(privateKey[1])) % int(privateKey[0])))

    return message


keys = getKeys()
print(keys)
publicKey = keys[0]
publicKey[0]
privateKey = keys[1]
print("public: ", publicKey)
print("private: ", privateKey)
decryptedMessage = decrypt(privateKey)

print(''.join(decryptedMessage))