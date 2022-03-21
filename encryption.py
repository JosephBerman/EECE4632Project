import random


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
        if ((greater % num1 == 0) and (greater % num2 == 0)):
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


def modinv(u, v):
    # Step X1. Initialise
    u1 = 1
    u3 = u
    v1 = 0
    v3 = v
    # Remember odd/even iterations
    iter = 1
    # Step X2. Loop while v3 != 0
    while v3 != 0:
        # Step X3. Divide and "Subtract"
        q = u3 / v3
        t3 = u3 % v3
        t1 = u1 + q * v1
        # Swap
        u1 = v1;
        v1 = t1;
        u3 = v3;
        v3 = t3
        iter = -iter

    # Make sure u3 = gcd(u,v) == 1
    if u3 != 1:
        return 0;  # Error: No inverse exists
    # Ensure a positive result
    if iter < 0:
        inv = v - u1
    else:
        inv = u1
    return inv


# primes_list = primesInRange(300, 400)

q = 53  # random.choice(primes_list)	 first prime number
p = 61  # random.choice(primes_list)	 second prime number

n = p * q  # n is the product of the two generated prime numbers
print("p: ", p)
print("p: ", q)
print("n: ", n)

lcm = findLCM(p, q)
print("lcm: ", lcm)

for i in range(2, lcm):
    if isCoprime(i, lcm) == True:
        coprime = i
        break

coprime = 17

print("coprime:", coprime)

d = modinv(n, coprime)
print("d: ", d)

message = 69
print("Original Message: ", message)
encryptedMessage = pow(message, coprime) % n
print("Encrypted Message: ", encryptedMessage)
decryptedMessage = pow(encryptedMessage, d) % n
print("Decrypted Message: ", decryptedMessage)


