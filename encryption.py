import random
import math

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def isCoprime(e, lcm):
    return gcd(e, lcm) == 1


def findLCM(num1, num2):
    num1 -= 1
    num2 -= 1
    if num1 > num2:
        greater = num1
    else:
        greater = num2

    while (True):
        if (greater % num1 == 0) and (greater % num2 == 0):
            lcm = greater
            break
        greater += 1

    return lcm


def primesInRange(x, y):
    prime_list = []
    for n in range(x, y):
        isPrime = True

        for num in range(2, n):
            if n % num == 0:
                isPrime = False

        if isPrime:
            prime_list.append(n)
    return prime_list




def modInv(u, v):
    for x in range(1, v):
        if ((u % v) * (x % v) % v == 1):
            return x

def getCoprime(lcm):
    for i in range(2, lcm):
        if isCoprime(i, lcm) == True:
            return i


def getTotient(x, y):
    return (x-1) * (y-1)

def getDval(phi, e):
    for i in range(e * 25):
        if (e * i) % phi == 1:
            return i

primes_list = primesInRange(200, 600)

q = random.choice(primes_list)#	 first prime number
p = random.choice(primes_list)	 #second prime number

n = p * q  # n is the product of the two generated prime numbers
print("p: ", p)
print("p: ", q)
print("n: ", n)

phi = getTotient(p, q)
print("phi: ", phi)
lcm = findLCM(p, q)
print("lcm: ", lcm)


coprime = getCoprime(lcm)

#coprime = 17

print("coprime:", coprime)
phi = getTotient(p, q)
d = modInv(coprime, phi)  #modinv(phi, coprime)
print("d: ", d)

message = 69
publicKey = [n, coprime]
privateKey = [n, d]
print("Public key", publicKey)
print("Private key", privateKey)

print("Original Message: ", message)
encryptedMessage = pow(message, coprime) % n
print("Encrypted Message: ", encryptedMessage)
decryptedMessage = pow(encryptedMessage, d) % n
print("Decrypted Message: ", decryptedMessage)


